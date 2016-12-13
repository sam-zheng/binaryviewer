#include <stdio.h>
#include <string.h>
int main(int argc, char** argv) {
  if (argc <= 1) {
     printf("please specify a file\n");
  }
  FILE* aFile = fopen(argv[1], "r");
  if (aFile == NULL) {
     printf("error opening file: %s", argv[0]);
  }
  fseek(aFile, 0L, SEEK_END);
  long aSize = ftell(aFile);
  char aTemp[1024];
  rewind(aFile);
  long aLines = aSize & ~15; 
  sprintf(aTemp, "%lx", aLines);
  int aLen = strlen(aTemp);

  int c;
  int n = 0;
  printf("%*s+    ", aLen - 1, "");
  for (int i = 0; i < 16; i++) {
    printf("%02x  ", i);
  }
  printf("\n\n");
  while ((c = fgetc(aFile)) != -1) {
    if (n % 16 == 0) {
      printf("%*x    ", aLen, n);
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
