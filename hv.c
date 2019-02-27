/*
 * to view a file in raw HEX.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char** argv) {
  if (argc <= 1) {
    fprintf(stderr, "please specify a file\n");
    return 1;
  }
  FILE* aFile = fopen(argv[1], "r");
  if (aFile == NULL) {
    fprintf(stderr, "error opening file: %s\n", argv[1]);
    return 1;
  }
  fseek(aFile, 0L, SEEK_END);
  long aSize = ftell(aFile);
  char aTemp[1024];
  rewind(aFile);

  sprintf(aTemp, "%lx", (aSize & ~15));
  int aHW = strlen(aTemp);

  int c;
  int n = 0;
  printf("%*s+    ", aHW - 1, "");
  for (int i = 0; i < 16; i++) {
    printf("%02x  ", i);
  }
  printf("\n\n");
  char aText[17];
  aText[16] = '\0';
  int i = 0;
  while ((c = fgetc(aFile)) != -1) {
    if (n % 16 == 0) {
      printf("%*x    ", aHW, n);
    }
    printf("%02x  ", c);
    if (isprint(c)) {
      aText[i++] = c;
    } else {
      aText[i++] = ' ';
    }
    n++;
    if (n % 16 == 0) {
      printf("  %s", aText);
      i = 0;
      printf("\n");
    }
  }
  if (i > 0) {
    for (int j = i; j < 16; j++) {
      printf("%4s", "");
    }
    aText[i] = '\0';
    printf("  %s", aText);
  }
  printf("\n");
  fclose(aFile);
}
