#include <stdio.h>
int main(int argc, char** argv) {
  if (argc <= 1) {
     printf("please specify a file\n");
  }
  FILE* aFile = fopen(argv[1], "r");
  if (aFile == NULL) {
     printf("error opening file: %s", argv[0]);
  }
  int c;
  int n = 0;
  printf("%8s", "");
  for (int i = 0; i < 16; i++) {
    printf("%02x  ", i);
  }
  printf("\n");
  while ((c = fgetc(aFile)) != -1) {
    if (n % 16 == 0) {
      printf("%6x  ", n);
    }
    printf("%02x  ", c);
    n++;
    if (n % 16 == 0) {
      printf("\n");
    }
  }
  printf("\n");
  fclose(aFile);
}
