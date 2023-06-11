// n00bz{ZzZ_zZZ_zZz_ZZz_zzZ_Zzz}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void bye() {
	puts("That's wrong!");
	exit(-1);
}

void check(char secret[]) {
	if (secret[0] >> 4 != 6) {
		bye();
	}
	if ((secret[1] ^ secret[2]) == 0) {
		
	} else {
		bye();
	}
	if ((secret[3] | secret[6]) != 122 || (secret[3] & secret[6]) != 66) {
		bye();
	}
	switch (secret[4] ^ secret[28]) {
		case 0:
			break;
		default:
			bye();
	}
	if (secret[5] * secret[29] * 0x1337 != 75629625) {
		bye();
	} else if ((secret[6] + secret[7] + secret[8]) != 302 || ((secret[6] * secret[7]) - secret[8])!= 10890) {
		bye();
	}
	if ((secret[9] - secret[8]) != 5 || (secret[10] - secret[9]) != 27 || (secret[11] ^ secret[10]) != 32) {
		bye();
	} else if ((secret[12] - secret[15]) != 0 || (secret[12] + secret[11]) != 180 || (secret[13] + secret[12]) != 185) {
		bye();
	}
	if ((secret[13] + secret[14] - secret[16]) != secret[13]) {
		bye();
	} else if (secret[16] + secret[17] != 217 || (secret[17] ^ secret[13]) != 0) {
		bye();
	} else if (secret[14] + secret[16] != 2 * secret[14]) {
		bye();
	}
	if (secret[18] != 90 || secret[18] != secret[19] || (secret[19] ^ secret[20] ^ secret[21]) != 127) {
		bye();
	} else if ((secret[20] ^ secret[21] ^ secret[22]) != secret[21]) {
		bye();
	} else if (secret[21] != 95 || secret[24] + secret[6] != 180) {
		bye();
	}
	if ((~secret[23] + secret[24]) != -33) {
		bye();
	}
	if (secret[25] == secret[9]) {

	} else {
		bye();
	}
	if (secret[26] + secret[27] == 212) {
		if (secret[27] == secret[28]) {
			puts("You got it!");
		} else {
			bye();
		}
	} else {
		bye();
	}

}

int main(int argc, char const *argv[])
{
	char buf[30];
	puts("What's the secret passcode?");
	if (read(0, buf, sizeof(buf)) < 0) {
		puts("Error reading from stdin!");
		exit(-1);
	}
	check(buf);
	return 0;
}