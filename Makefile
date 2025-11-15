SHELL = /bin/bash
FLAGS = -nostartfiles -nostdinc -g -fPIC -I. -z noexecstack -ffreestanding
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
define TO_OBJ
$(basename $(subst src,build,$1)).o
endef

b:
	gcc $(FLAGS) $(call MAIN_FN, $@) lib/lib$(LIB).so $(START)

.ONESHELL:
run:
	export LD_LIBRARY_PATH=./lib
	./a.out

examples/%.c:
	$(CC) $(FLAGS) $@ $(LIB) $(START)

build/%.o: src/%.c
	$(CC) $(FLAGS) -o $@ -c $(call TO_SRC, $@)

OBJ := $(foreach src, $(SRC), $(call TO_OBJ, $(src)))

.ONESHELL:
test-all:
	failed=;
	for item in $(TESTS); do gcc $(FLAGS) test.c tests/$$item.c lib/lib$(LIB).so $(START) -o $$item-test.exe; done;
	for item in $(TESTS); do
		./$$item-test.exe
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

clean:
	rm a.out
	rm *-test.exe

clean-build:
	rm build/*.o
