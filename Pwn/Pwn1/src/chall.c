#include <stdio.h>
#include <stdlib.h>

void init() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void main() {
	init();
	char input[50];
	puts("Would you like a flag?");
	fgets(input,0x50,stdin);
	system("cat fake_flag.txt");
};

void win() {
	__asm__("push %rdi");
	system("/bin/sh");
}
