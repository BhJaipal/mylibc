#pragma once
#include <new.hpp>
#include <malloc.h>
#include <file.h>

namespace std {
	template <class Ret, class... Targs>
    class FunctorBase {
    public:
        virtual ~FunctorBase() = default;
        virtual Ret invoke(Targs... args) = 0;
        virtual FunctorBase* clone() const = 0; // Needed for copy
    };

    template <class Ret, class T, class... Targs>
    class FunctorWrapper : public FunctorBase<Ret, Targs...> {
        T callable_;
    public:
        FunctorWrapper(T&& callable) : callable_(callable) {}
        FunctorWrapper(T callable) : callable_(callable) {}

        Ret invoke(Targs... args) override {
            return callable_(args...);
        }
        FunctorWrapper* clone() const override {
            return new FunctorWrapper(callable_);
        }
    };

    template <class T>
    class function;

    template <class Ret, class... Targs>
    class function<Ret(Targs...)> {
        using BasePtr = FunctorBase<Ret, Targs...>*;
        BasePtr p_base_ = nullptr; // Store the type-erased pointer

    public:
        ~function() { delete p_base_; }

        function(Ret(*ptr)(Targs...)) {
            p_base_ = new FunctorWrapper<Ret, Ret(*)(Targs...), Targs...>(ptr);
        }
        
        template <class T>
        function(T callable) {
            p_base_ = new FunctorWrapper<Ret, T, Targs...>(callable);
        }

        Ret operator()(Targs... args) {
			return p_base_->invoke(args...);
        }
    };
}
