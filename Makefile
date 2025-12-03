SHELL = /bin/bash
FLAGS = -nostartfiles -nostdinc -g -fPIC -Iinclude -z noexecstack -ffreestanding
CFLAGS = -Wno-implicit-function-declaration

SRC := $(wildcard ./src/*.c)
SRCCXX := $(wildcard ./src/c++/*.cpp)

START := ./start/libc-start.c
LIBC = myc
LIBCXX = stdc++
CC ?= gcc
CXX := $(wildcard ./src/c++/*.cpp)
CXXFLAGS = -Iinclude/c++ -nolibc -nostdinc++ -nostdlib++

define MAIN_FN
$(filter-out $1,$(MAKECMDGOALS))
endef

define TO_SRC
$(basename $(subst build,src,$1)).c
endef
define TO_OBJ
$(basename $(subst src,build,$1)).o
endef


C_OBJ := $(foreach src, $(SRC), $(call TO_OBJ, $(src)))
CXX_OBJ := $(foreach src, $(SRC), $(call TO_OBJ, $(src))) $(foreach src, $(SRCCXX), $(call TO_OBJ, $(src)))

TESTS := $(foreach test,$(wildcard tests/*.c), $(subst .c,,$(subst tests/,,$(test))))

.PHONY: bin/% bin-src/%.c examples/%.c
bin/%:
	gcc $(FLAGS) $(CFLAGS) $(subst bin,bin-src,$@).c lib/lib$(LIBC).so $(START) -o $@

.ONESHELL:
bins:
	for item in $(wildcard ./bin-src/*.c); do
		make -B $$item
	done

bin-src/%:
	gcc $(FLAGS) $(CFLAGS) $@ lib/lib$(LIBC).so $(START) -o $(subst .c,, $(subst -src,,$@))

runpp:
	g++ $(FLAGS) $(CXXFLAGS) $(call MAIN_FN, $@) lib/lib$(LIBCXX).so $(START)pp

runpp-static:
	g++ $(FLAGS) $(CXXFLAGS) $(call MAIN_FN, $@) -static lib/lib$(LIBCXX).a $(START)pp

run:
	gcc $(FLAGS) $(CFLAGS) $(call MAIN_FN, $@) lib/lib$(LIBC).so $(START)

run-static:
	gcc $(FLAGS) $(CFLAGS) $(call MAIN_FN, $@) -static lib/lib$(LIBC).a $(START)

examples/%.c:
	$(CC) $(FLAGS) $(CFLAGS) $@ lib/lib$(LIBC).so $(START)

build/%.o: src/%.c
	$(CC) $(FLAGS) $(CFLAGS) -o $@ -c $(call TO_SRC, $@)

build/c++/%.o: src/c++/%.cpp
	g++ $(FLAGS) $(CXXFLAGS) $(subst build,src,$(basename $@)).cpp -c -o $@

buildcxx:
	$(foreach src, $(SRCCXX), make $(subst src,build,$(basename $(src))).o;)

.ONESHELL:
test-all:
	failed=;
	for item in $(TESTS); do
		gcc $(FLAGS) $(CFLAGS) test.c tests/$$item.c lib/lib$(LIBC).so $(START) -o $$item-test.exe;
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
	gcc $(FLAGS) $(CFLAGS) test.c tests/$(TEST).c lib/lib$(LIBC).so $(START) -o $(TEST)-test.exe
	./$(TEST)-test.exe

.ONESHELL:
compile:
	$(foreach s, $(C_OBJ), make $(s);)
	echo -e "\e[92mCompiled all done source files\e[0m"

shared: $(C_OBJ)
	$(CC) $(FLAGS) $(CFLAGS) $(C_OBJ) -shared -o lib/lib$(LIBC).so
	echo -e "\e[92mBuilt done lib$(LIBC).so successfully\e[0m"

stdcxx: $(CXX_OBJ) shared
	g++ $(FLAGS) $(CXXFLAGS) $(CXX_OBJ) lib/lib$(LIBC).so -shared -o lib/lib$(LIBCXX).so

ar: $(C_OBJ)
	ar rcs lib/lib$(LIBC).a $(C_OBJ)
	echo -e "\e[92mBuilt done lib$(LIBC).a successfully\e[0m"

clean:
	rm a.out
	rm *-test.exe

clean-build:
	rm build/*.o
	rm build/c++/*.o
