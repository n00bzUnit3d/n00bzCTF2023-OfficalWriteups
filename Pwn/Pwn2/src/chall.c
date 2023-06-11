#include <stdio.h>
#include <stdlib.h>

__asm__("pop %rdi; ret");

char input[25];

void init() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void main() {
	init();
	char second_input[25];
	puts("Would you like a flag?");
	fgets(input,25,stdin);
	puts("Wrong Answer! I'll give you another chance!\n");
	puts("Would you like a flag?");
	fgets(second_input,0x60,stdin);
	system("cat fake_flag.txt");
};
