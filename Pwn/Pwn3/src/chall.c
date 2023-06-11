#include <stdio.h>
#include <stdlib.h>

void init() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void main() {
	init();
	char input[25];
	puts("Would you like a flag?");
	fgets(input,0x50,stdin);
	puts("n00bz{f4k3_fl4g}");
}

void gadget_one() {
	__asm__("pop %rdi");
	__asm__("ret");
};