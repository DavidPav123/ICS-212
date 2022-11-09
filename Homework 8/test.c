#include <stdio.h>

int main() {
  FILE *fptr;
  unsigned char dataArr[20];
  unsigned int i;
  unsigned int n = dataArr[13], sourcePort = 51703;
  char binStr[100];

  fptr = fopen("request2.bin", "rb+");

  fread(dataArr, sizeof(dataArr), 1, fptr);

  fclose(fptr);

  if (((sourcePort & (1 << 6)) >> 6) ^ ((sourcePort & (1 << 10)) >> 10)) {
    sourcePort ^= 1 << 6;
    sourcePort ^= 1 << 10;
  }
  printf("%x", sourcePort);

  return 0;
}