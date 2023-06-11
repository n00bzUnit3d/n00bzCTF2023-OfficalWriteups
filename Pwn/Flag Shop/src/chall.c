// gcc chall.c -o flag_shop
#include <stdio.h>
#include <stdlib.h>

void init() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void main() { 
	init();
	puts("Welcome to the flag shop! The flag costs $1337 but you have $100. You can buy the fake flag which costs $50");
	int cost_flag = 1337;
	int cost_fake_flag = 50;
	unsigned int money = 100;
	FILE *flagptr;
	char flag;
	int how_many;
	int inp;
	int i;
	while (1) {
	puts("[1] Buy real flag - $1337\n[2] Buy fake flag - $50\n[3] Check account balance");
	scanf("%i",&inp);
	getc(stdin);
	if (inp == 1) {
		if (money >= cost_flag) { 
			puts("How many? ");
			scanf("%i",&how_many);
			getc(stdin);	
			flagptr = fopen("flag.txt", "r");
    		if (flagptr == NULL)
    {
        printf("Flag file not found! If this is on the remote server, please open a ticket and let us know!\n");
        exit(0);
    }
    while((flag=fgetc(flagptr))!=EOF) {
   	printf("%c",flag);
}	money -= how_many*cost_flag;
    fclose(flagptr);
    exit(0);
		} 
	if (money < cost_flag) { 
		puts("Not enough money!");
		exit(0);
	}
}
	if (inp == 2) {
		if (money > cost_fake_flag) { 
			puts("How many? ");
			scanf("%i",&how_many);
			getc(stdin);
			money -= how_many*cost_fake_flag;
			for (i = 0; i < how_many; i++) { 
			puts("n00bz{f4k3_flag}");
			};
		}
	}
	if (inp==3) {
		printf("$%i\n",money);
	}
}
};