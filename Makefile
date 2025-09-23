SHELL = /bin/bash
FLAGS = -nostdlib -nostdinc -Wno-builtin-declaration-mismatch -g -fPIC -I.
SRC := ./src/syscall.c ./src/c-impl.c ./src/malloc.c ./src/libc-start.c ./src/string.c ./src/file.c ./src/format.c ./src/stat.c
ASM := ./asm-impl.s
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

asm:
	gcc $(FLAGS) $(call MAIN_FN, $@) -S

run:
	gcc $(FLAGS) $(call MAIN_FN, $@) $(LIB) $(ASM)

examples/%.c:
	gcc $(FLAGS) $@ $(LIB) $(ASM)

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
	gcc $(FLAGS) src/test.c tests/$(TEST).c $(LIB) $(ASM) -o $(TEST)-test.exe
	./$(TEST)-test.exe $(TEST);

.ONESHELL:
compile:
	echo $(OBJ)
	$(foreach s, $(OBJ), make $(s);)
	echo -e "\e[92mCompiled all done source files\e[0m"

shared:
	gcc $(FLAGS) $(OBJ) -shared -o $(LIB)
	echo -e "\e[92mBuilt done $(LIB) successfully\e[0m"

build-clean:
	rm build/*.o
	rm ./mylibc.so
clean:
	rm a.out
	rm *-test.exe
