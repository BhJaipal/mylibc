# MYGLIBC

> I started as me implementing syscalls in assembly
>
> now I am trying to implement whole glibc

## Building

```sh
make compile # create build/*.o of src
make shared  # creates ./mylibc.so
```

## Run tests

> This is one of the rare occasions when I wrote tests

```sh
make test-all # run all test
# For solo test:
make test TEST=(test-name)
# as I will assume tested file is in tests/ folder with .c extension
```

## Compiling your files

```sh
make all your-file.c
```
