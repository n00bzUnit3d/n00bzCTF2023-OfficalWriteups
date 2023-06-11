#include <stdio.h>
#include <stdlib.h>

char fake_flag[17] = "n00bz{f4k3_fl4g}";

void init() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void main2() {
	FILE* flag_ptr;
	char flag[40];
	flag_ptr = fopen("flag.txt", "r");
 	
    if (flag == NULL) {
        printf("Flag File not found");
    }
    fgets(flag, 40, flag_ptr);
    printf(fake_flag);
};

void main() {
	init();
	char buf[100];
	puts("Do you love strings? ");
	fgets(buf,100,stdin);
	printf(buf);
	main2();
};