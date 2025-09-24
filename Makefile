SHELL = /bin/bash
FLAGS = -nostdlib -nostdinc -Wno-builtin-declaration-mismatch -g -fPIC -I.
SRC := $(wildcard ./src/*.c)
START := ./start/asm-impl.s ./start/libc-start.c
LIB = ./mylibc.so

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

run:
	gcc $(FLAGS) $(call MAIN_FN, $@) $(LIB) $(START)

examples/%.c:
	gcc $(FLAGS) $@ $(LIB) $(START)

build/%.o: src/%.c
	gcc $(FLAGS) -o $@ -c $(call TO_SRC, $@)

OBJ := $(foreach src, $(SRC), $(call TO_OBJ, $(src)))

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
	gcc $(FLAGS) src/test.c tests/$(TEST).c $(LIB) $(START) -o $(TEST)-test.exe
	./$(TEST)-test.exe $(TEST)

.ONESHELL:
compile:
	$(foreach s, $(OBJ), make $(s);)
	echo -e "\e[92mCompiled all done source files\e[0m"

shared: $(OBJ)
	gcc $(FLAGS) $(OBJ) -shared -o $(LIB)
	echo -e "\e[92mBuilt done $(LIB) successfully\e[0m"

clean:
	rm a.out
	rm *-test.exe
