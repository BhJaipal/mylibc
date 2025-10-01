#!/bin/python3
import sys

with open("./syscall.table", "r") as syscallf:
    syscall = ""
    if len(sys.argv) == 1:
        syscall = input("Enter syscall: ")
    else:
        syscall = sys.argv[1]

    syscalls = syscallf.readlines()
    for line in  syscalls:
        sys_args = line.split(": ")
        if sys_args[0] == syscall:
            args = sys_args[1].strip().split("|")
            declaration = "extern int " + syscall + "("
            defination = "int " + syscall + "("
            declaration += (", ".join(args) + ");")
            defination += (", ".join(args) + ") {\n\tSYSCALL(return, SYS_" + syscall + ", ")
            args = map(lambda x: (x.split()[-1][1:] if x.split()[-1][0] == "*" else x.split()[-1]), args)
            defination += ", ".join(args)
            defination += ");\n}"
            print(declaration)
            print()
            print(defination)
