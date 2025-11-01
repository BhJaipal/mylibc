SHELL = /bin/bash
FLAGS = -nostdlib -nostdinc -Wno-builtin-declaration-mismatch -g -fPIC -I. -z noexecstack -Llib
SRC := $(wildcard ./src/*.c)
START := ./start/asm-impl.s ./start/libc-start.c
LIB = myc
CC ?= gcc

TESTS := $(foreach test,$(wildcard tests/*.c), $(subst .c,,$(subst tests/,,$(test))))

define MAIN_FN
$(filter-out $1,$(MAKECMDGOALS))
endef

define TO_SRC
$(basename $(subst build,src,$1)).c
endef
define TO_SRCPP
$(basename $(subst build/cpp,src,$1)).c
endef
define TO_OBJ
$(basename $(subst src,build,$1)).o
endef
define TO_OBJPP
$(basename $(subst src,build/cpp,$1)).o
endef

b:
	gcc $(FLAGS) $(call MAIN_FN, $@) -l$(LIB) $(START)
bpp:
	g++ $(FLAGS) -Ic++ -fpermissive -Wno-narrowing -fno-rtti ./c++/heap.cpp $(call MAIN_FN, $@) ./c++/new.cpp $(START)pp -l$(LIB)

.ONESHELL:
run:
	export LD_LIBRARY_PATH=./lib
	./a.out

examples/%.c:
	$(CC) $(FLAGS) $@ $(LIB) $(START)

build/%.o: src/%.c
	$(CC) $(FLAGS) -o $@ -c $(call TO_SRC, $@)

build/cpp/%.o: src/%.c
	if [[ ! -d build/cpp ]]; then mkdir -p build/cpp; fi
	g++ -fpermissive -Wno-narrowing $(FLAGS) -o $@ -c $(call TO_SRCPP, $@)

OBJ := $(foreach src, $(SRC), $(call TO_OBJ, $(src)))
OBJPP := $(foreach src, $(SRC), $(call TO_OBJPP, $(src)))

.ONESHELL:
test-all:
	failed=;
	for item in $(TESTS); do
		make test TEST=$$item;
		if [[ $$? == 2 ]]; then failed=1; fi;
	done;
	
	if [[ $$failed ]]; then
		echo -e "\e[91mTest failed\e[0m";
	fi

.ONESHELL:
test:
	gcc $(FLAGS) test.c tests/$(TEST).c $(LIB) $(START) -o $(TEST)-test.exe
	./$(TEST)-test.exe $(TEST)

.ONESHELL:
compile:
	$(foreach s, $(OBJ), make $(s);)
	echo -e "\e[92mCompiled all done source files\e[0m"

shared: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -shared -o lib/lib$(LIB).so
	echo -e "\e[92mBuilt done lib$(LIB).so successfully\e[0m"

sharedpp: $(OBJPP)
	g++ $(FLAGS) $(OBJPP) -shared -o lib/lib$(LIBXX).so
	echo -e "\e[92mBuilt done lib$(LIBXX).so successfully\e[0m"

clean:
	rm a.out
	rm *-test.exe

clean-build:
	rm build/*.o
