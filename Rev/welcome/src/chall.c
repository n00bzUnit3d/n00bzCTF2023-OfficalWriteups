#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char input[256];

  printf("Input flag : ");
  fgets(input, 256, stdin);

  if (!strcmp(input, "n00bz{N3v3R_$torE_$ENs1TIV3_1nFOrMa7IOn_P1aiNtexT_In_yoUr_bin4rI3S!!!!!}")) {
    printf("Correct flag !\n");
  } else {
    printf("Wrong flag !\n");
  }

  return 0;
}