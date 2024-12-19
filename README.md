## ebpf-inline-testing

This repository showcases several attempt to write eBPF source code at the instruction level. The documentation for how an eBPF instruction is formatted can be found [here](https://www.kernel.org/doc/html/v5.17/bpf/instruction-set.html).

The tool contains a userspace program that verifies if a sample can (a) be opened by libbpf and (b) additionally loaded into the kernel after passing the eBPF verifier.

## Usage

for compiling userspace program:
- gcc prog.c -o prog ./libbpf/src/libbpf.a -lelf -lz

for compiling sample:
- clang -target bpf -c sampleX.c -o sampleX.o

## Background

The main files of importance are sample1-sample7. The .c files were compiled with clang -target bpf -c sampleX.c -o sampleX.o, and the corresponding object files were fed into llvm-objdump to create the .txt files that verify what the instructions do.

When I first conducted testing, I used a return signature of int for the function, which implicitly always set r0 after compilation to the return value (in sample4, for example). After changing the return type to void, the only instruction that clang adds is the eBPF exit, meaning every other instruction can be manually inserted. sample5, for example, manually sets r0 to 1, and then clang adds an exit instruction post-compilation as seen in sample5.txt.

Lastly, I wrote a small user-space program to attempt to (a) open and (b) load each object file. Every single sample was able to open, but libbpf internally ignores any program with the ".text" section (which is the default if no section is provided). sample1-sample5 were able to open, but there was no detection of the my_func program. sample6, however, is successfully opened, detected, and loaded, as it attaches to the "socket" section. sample7 is just like sample6, except that it uses a bogus section/attachment point, so it is not able to load.

Ultimately, given the success of sample6, this tool showcases the ability to write more granular eBPF programs that can be directly compiled to an object file with minimal efforts.
