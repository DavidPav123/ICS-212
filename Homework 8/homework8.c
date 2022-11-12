/*****************************************************************
//
//  NAME:        David Pavlicek
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 12th, 2022
//
//  FILE:        homework8.c
//
//  DESCRIPTION:
//   Describe the file
//
//  REFERENCES:
//   List references used here
//
****************************************************************/

#include <stdio.h>
#include <math.h>

int readfile(const char[], unsigned char[]);
int writefile(const char[], const unsigned char[]);
void printheader(const unsigned char[]);
void makeheader(const unsigned char[], unsigned char[]);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 function does.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/

int main(int argc, char *argv[]) {
  int returnVal;
  unsigned char tcpPacket[20], tcpResponse[25];

  readfile("request1.bin", tcpPacket);
  for (int i = 0; i < 20; i++) {
    printf("%x ", tcpPacket[i]);
  }
  printheader(tcpPacket);
  makeheader(tcpPacket, tcpResponse);
  for (int i = 0; i < 20; i++) {
    printf("%x ", tcpResponse[i]);
  }
  printf("\n");
  writefile("response1.bin", tcpResponse);
  readfile("response1.bin", tcpPacket);
  printheader(tcpPacket);

  return 0;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   A template function
//                 This function does not do anything.
//                 Please describe your function correctly.
//
//  Parameters:    bar (int) : Describe the meaning
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/
int readfile(const char filename[], unsigned char dataArr[]) {
  int returnVal;
  FILE *fptr;

  fptr = fopen(filename, "rb+");

  if (fptr == NULL) {
    returnVal = -1;
  } else {
    fread(dataArr, sizeof(&dataArr), 20, fptr);

    fclose(fptr);
  }
  
  return returnVal;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   A template function
//                 This function does not do anything.
//                 Please describe your function correctly.
//
//  Parameters:    bar (int) : Describe the meaning
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/
int writefile(const char filename[], const unsigned char dataArr[]) {
  int returnVal;
  FILE *fptr;

  fptr = fopen(filename, "wb+");

  if (fptr == NULL) {
    returnVal = -1;
  } else {
    fwrite(dataArr, sizeof(&dataArr) + 2, 2, fptr);

    fclose(fptr);
  }

  return returnVal;
}

/*****************************************************************
//
//  Function name: printheader
//
//  DESCRIPTION:   A template function
//                 This function does not do anything.
//                 Please describe your function correctly.
//
//  Parameters:    bar (int) : Describe the meaning
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/
void printheader(const unsigned char dataArr[]) {
  unsigned int i, n;
  printf("\n%u\n", (dataArr[1] * 256) + dataArr[0]);
  printf("%u\n", (dataArr[3] * 256) + dataArr[2]);
  printf("%u\n", (dataArr[7] * 16777216) + (dataArr[6] * 65536) +
                     (dataArr[5] * 256) + dataArr[4]);
  printf("%u\n", (dataArr[11] * 16777216) + (dataArr[10] * 65536) +
                     (dataArr[9] * 256) + dataArr[8]);
  n = dataArr[13];
  printf("Control bits which are set to 1:\n");
  for (i = 1 << 5; i > 0; i = i / 2) {
    if (i == 32) {
      if (n & i) {
        printf("URG\n");
      }
    }
    if (i == 16) {
      if (n & i) {
        printf("ACK\n");
      }
    }
    if (i == 8) {
      if (n & i) {
        printf("PSH\n");
      }
    }
    if (i == 4) {
      if (n & i) {
        printf("RST\n");
      }
    }
    if (i == 2) {
      if (n & i) {
        printf("SYN\n");
      }
    }
    if (i == 1) {
      if (n & i) {
        printf("FIN\n");
      }
    }
  }
}

/*****************************************************************
//
//  Function name: makeheader
//
//  DESCRIPTION:   A template function
//                 This function does not do anything.
//                 Please describe your function correctly.
//
//  Parameters:    bar (int) : Describe the meaning
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/
void makeheader(const unsigned char dataArr[], unsigned char newArr[]) {
  unsigned int newSeq, n = dataArr[13], sourcePort = (dataArr[1] * 256) + dataArr[0];
  int i;
  newSeq = (dataArr[7] * 16777216) + (dataArr[6] * 65536) + (dataArr[5] * 256) + dataArr[4] + 1;

  // Flip the bits in the header
  // Dest header to source header
  if (((sourcePort & (1 << 6)) >> 6) ^ ((sourcePort & (1 << 10)) >> 10)) {
    sourcePort ^= 1 << 6;
    sourcePort ^= 1 << 10;
  }
  newArr[0] = dataArr[2];
  newArr[1] = dataArr[3];
  // Source header to dest header
  newArr[2] = dataArr[0];
  newArr[3] = dataArr[1];
  // Sequence Number = sequence number + 1
  newArr[4] = newSeq % 256;
  newArr[5] = ((newSeq - ((dataArr[7]*16777216) + (dataArr[6]*65536) + newArr[4]))/256)  % 256;
  newArr[6] = ((newSeq - ((dataArr[7]*16777216) + newArr[5] + newArr[4]))/65536)  % 256;
  newArr[7] = ((newSeq - ((dataArr[6]*65536) + (dataArr[5]*256) + dataArr[4]))/16777216) % 256;
  // Ack Number  = sequence Number
  newArr[8] = dataArr[4];
  newArr[9] = dataArr[5];
  newArr[10] = dataArr[6];
  newArr[11] = dataArr[7];
  // Data offset/reserved
  newArr[12] = dataArr[12];
  // reserved/flags
  /*if (n & (1 << 1)) {
    if (n & (1 << 4)) {
      newArr[13] = dataArr[13];
    } else {
      newArr[13] = dataArr[13] + 2;
    }
  }*/
  newArr[13] = 19;
  // Ending bits
  newArr[14] = 0;
  newArr[15] = 0;
  newArr[16] = 255;
  newArr[17] = 255;
  newArr[18] = 0;
  newArr[19] = 0;
}