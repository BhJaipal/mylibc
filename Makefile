SHELL = /bin/bash
FLAGS = -nostartfiles -nostdinc -g -fPIC -Iinclude -z noexecstack -ffreestanding
SRC := $(wildcard ./src/*.c)
START := ./start/libc-start.c
LIB = myc
CC ?= gcc
CXX := $(wildcard ./src/c++/*.cpp)
CXXFLAGS = -Iinclude/c++

SRCCXX := $(wildcard ./src/c++/*.cpp)
SRCCXX_C := ./src/format.c ./src/c-impl.c ./src/env.c ./src/in.c ./src/stat.c ./src/file.c ./src/unistd.c ./src/string.c ./src/io.c

TESTS := $(foreach test,$(wildcard tests/*.c), $(subst .c,,$(subst tests/,,$(test))))

define MAIN_FN
$(filter-out $1,$(MAKECMDGOALS))
endef

define TO_SRC
$(basename $(subst build,src,$1)).c
endef
define TO_OBJ
$(basename $(subst src,build,$1)).o
endef

.PHONY: bin/% bin-src/%.c examples/%.c
bin/%:
	gcc $(FLAGS) $(subst bin,bin-src,$@).c lib/lib$(LIB).so $(START) -o $@

.ONESHELL:
bins:
	for item in $(wildcard ./bin-src/*.c); do
		make -B $$item
	done

bin-src/%:
	gcc $(FLAGS) $@ lib/lib$(LIB).so $(START) -o $(subst .c,, $(subst -src,,$@))

runpp:
	g++ $(FLAGS) $(call MAIN_FN, $@) lib/lib$(LIB).so $(CXXFLAGS) $(CXX) $(START)pp

runpp-static:
	g++ $(FLAGS) $(call MAIN_FN, $@) -static lib/lib$(LIB).a $(CXXFLAGS) $(CXX) $(START)pp

run:
	gcc $(FLAGS) $(call MAIN_FN, $@) lib/lib$(LIB).so $(START)

run-static:
	gcc $(FLAGS) $(call MAIN_FN, $@) -static lib/lib$(LIB).a $(START)

examples/%.c:
	$(CC) $(FLAGS) $@ lib/lib$(LIB).so $(START)

build/%.o: src/%.c
	$(CC) $(FLAGS) -o $@ -c $(call TO_SRC, $@)

build/c++/%.o: src/c++/%.cpp
	g++ $(FLAGS) $(CXXFLAGS) $(subst build,src,$(basename $@)).cpp -c -o $@

buildcxx:
	$(foreach src, $(SRCCXX), make $(subst src,build,$(basename $(src))).o;)

OBJ := $(foreach src, $(SRC), $(call TO_OBJ, $(src)))

.ONESHELL:
test-all:
	failed=;
	for item in $(TESTS); do
		gcc $(FLAGS) test.c tests/$$item.c lib/lib$(LIB).so $(START) -o $$item-test.exe;
		if [[ $$? == 1 ]]; then failed=1; fi;
	done;
	for item in $(TESTS); do
		./$$item-test.exe;
		if [[ $$? == 1 ]]; then failed=1; fi;
	done;
	if [[ $$failed == 1 ]]; then echo -e "\e[91mSome Test Failed\e[0m";
	else echo -e "\e[92mAll Test Passed\e[0m";
	fi

.ONESHELL:
test:
	gcc $(FLAGS) test.c tests/$(TEST).c lib/lib$(LIB).so $(START) -o $(TEST)-test.exe
	./$(TEST)-test.exe

.ONESHELL:
compile:
	$(foreach s, $(OBJ), make $(s);)
	echo -e "\e[92mCompiled all done source files\e[0m"

shared: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -shared -o lib/lib$(LIB).so
	echo -e "\e[92mBuilt done lib$(LIB).so successfully\e[0m"


ar: $(OBJ)
	ar rcs lib/lib$(LIB).a $(OBJ)
	echo -e "\e[92mBuilt done lib$(LIB).a successfully\e[0m"

clean:
	rm a.out
	rm *-test.exe

clean-build:
	rm build/*.o
