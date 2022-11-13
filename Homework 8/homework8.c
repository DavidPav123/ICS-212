/*****************************************************************
//
//  NAME:        David Pavlicek
//
//  HOMEWORK:    8
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
//   Accepts input of a TCP Packet for a binary file and writes a
//   response packet. It then prints out the contents of the
//   response packet to the terminal.
//
//  REFERENCES:
//   Sections 2.9, B1.5, B4
//
****************************************************************/

#include <math.h>
#include <stdio.h>

int readfile(const char[], unsigned char[]);
int writefile(const char[], const unsigned char[]);
void printheader(const unsigned char[]);
void makeheader(const unsigned char[], unsigned char[]);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Calls the functions for reading a TCP packet,
//                writing a response packet, and printing out the
//                contents of the rsponse packet to the terminal
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : main function was executed sucesfully
//                 -1 : file was unable to be accessed
//
****************************************************************/

int main(int argc, char *argv[])
{
    int returnVal = 0;
    unsigned char tcpPacket[20], tcpResponse[20];

    if (readfile("request1.bin", tcpPacket) == -1)
    {
        returnVal = -1;
    }
    makeheader(tcpPacket, tcpResponse);
    if (writefile("response1.bin", tcpResponse) == -1)
    {
        returnVal = -1;
    }
    readfile("response1.bin", tcpPacket);
    printf("Printing response1.bin:\n");
    printheader(tcpPacket);

    if (readfile("request2.bin", tcpPacket) == -1)
    {
        returnVal = -1;
    }
    makeheader(tcpPacket, tcpResponse);
    if (writefile("response2.bin", tcpResponse) == -1)
    {
        returnVal = -1;
    }
    readfile("response2.bin", tcpPacket);
    printf("Printing response2.bin:\n");
    printheader(tcpPacket);

    if (readfile("request3.bin", tcpPacket) == -1)
    {
        returnVal = -1;
    }
    makeheader(tcpPacket, tcpResponse);
    if (writefile("response3.bin", tcpResponse) == -1)
    {
        returnVal = -1;
    }
    readfile("response3.bin", tcpPacket);
    printf("Printing response3.bin:\n");
    printheader(tcpPacket);

    return returnVal;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   This function opens a file containing the
//                 informtation from a tcp packet and
//                 stores that data in an array
//
//  Parameters:    filename (const char []) : name of the file to
//                                            read the data from
//                  dataArr (unsigned char []) : array to write the
//                                             data from the file to
//
//  Return values:  0 : file was opened and written to succesfully
//                 -1 : file failed to open
//
****************************************************************/

int readfile(const char filename[], unsigned char dataArr[])
{
    int returnVal = 0;
    FILE *fptr;

    fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        returnVal = -1;
    }
    else
    {
        fread(dataArr, sizeof(dataArr[0]), 20, fptr);
        fclose(fptr);
    }

    return returnVal;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   This functions takes in an array containing the
//                 infromation of a tcp packet and writes the
//                 contents of the array to the specified file
//
//  Parameters:    filename (const char []) : name of the file to
//                                            write the data to
//                  dataArr (const unsigned char []) : array containing
//                      the data of a tcp packet to be written the file
//
//  Return values:  0 : file was opened and written to succesfully
//                 -1 : file failed to open
//
****************************************************************/

int writefile(const char filename[], const unsigned char dataArr[])
{
    int returnVal = 0;
    FILE *fptr;

    fptr = fopen(filename, "w+");

    if (fptr == NULL)
    {
        returnVal = -1;
    }
    else
    {
        fwrite(dataArr, sizeof(dataArr[0]), 20, fptr);
        fclose(fptr);
    }

    return returnVal;
}

/*****************************************************************
//
//  Function name: printheader
//
//  DESCRIPTION:   This function takes in a tcp packet and prints
//                 out the contents
//
//  Parameters:    dataArr (const unsigned char []) : an array
//                                 holding the data of a tcp file
//
//  Return values:  none
//
****************************************************************/

void printheader(const unsigned char dataArr[])
{
    unsigned int i, n;
    printf("%s%u\n", "source port: ", (dataArr[1] * 256) + dataArr[0]);
    printf("%s%u\n", "destination port: ", (dataArr[3] * 256) + dataArr[2]);
    printf("%s%u\n", "sequence number: ",
    (dataArr[7] * 16777216) + (dataArr[6] * 65536) + (dataArr[5] * 256) +
    dataArr[4]);
    printf("%s%u\n", "acknowledgement number: ",
    (dataArr[11] * 16777216) + (dataArr[10] * 65536) + (dataArr[9] * 256) +
    dataArr[8]);
    n = dataArr[13];
    printf("Flags: ");
    for (i = 1 << 5; i > 0; i = i / 2)
    {
        if (i == 32)
        {
            if (n & i)
            {
                printf("URG ");
            }
        }
        if (i == 16)
        {
            if (n & i)
            {
                printf("ACK ");
            }
        }
        if (i == 8)
        {
            if (n & i)
            {
                printf("PSH ");
            }
        }
        if (i == 4)
        {
            if (n & i)
            {
                printf("RST ");
            }
        }
        if (i == 2)
        {
            if (n & i)
            {
                printf("SYN ");
            }
        }
        if (i == 1)
        {
            if (n & i)
            {
                printf("FIN\n\n");
            }
        }
    }
}

/*****************************************************************
//
//  Function name: makeheader
//
//  DESCRIPTION:   This function takes in a tcp request and generates
//                 a respone, storing that response in a provided array
//
//  Parameters:    dataArr (const unsigend char []) : array that
//                  holds the information from the request file
//                 newArr (unsigned char) : Array the header
//                                          data is written to
//
//  Return values:  none
//
****************************************************************/

void makeheader(const unsigned char dataArr[], unsigned char newArr[])
{
    unsigned int newSeq, n = dataArr[13],
    sourcePort = (dataArr[1] * 256) + dataArr[0];
    newSeq = (dataArr[7] * 16777216) + (dataArr[6] * 65536) + (dataArr[5] * 256) +
    dataArr[4] + 1;

    newArr[0] = dataArr[2];
    newArr[1] = dataArr[3];

    if (sourcePort > 32767)
    {
        if (((sourcePort & (1 << 6)) >> 6) ^ ((sourcePort & (1 << 10)) >> 10))
        {
            sourcePort ^= 1 << 6;
            sourcePort ^= 1 << 10;
            newArr[2] = sourcePort % 256;
            newArr[3] = ((sourcePort - newArr[2]) / 256) % 256;
        }
    }
    else
    {
        newArr[2] = dataArr[0];
        newArr[3] = dataArr[1];
    }

    newArr[4] = newSeq % 256;
    newArr[5] =
    ((newSeq - ((dataArr[7] * 16777216) + (dataArr[6] * 65536) + newArr[4])) /
    256) % 256;
    newArr[6] =
    ((newSeq - ((dataArr[7] * 16777216) + (newArr[5] * 256) + newArr[4])) /
    65536) % 256;
    newArr[7] =
    ((newSeq - ((newArr[6] * 65536) + (newArr[5] * 256) + newArr[4])) /
    16777216) % 256;

    newArr[8] = dataArr[4];
    newArr[9] = dataArr[5];
    newArr[10] = dataArr[6];
    newArr[11] = dataArr[7];
    newArr[12] = dataArr[12];

    if (n & (1 << 1))
    {
        if (n & (1 << 4))
        {
            newArr[13] = dataArr[13];
        }
        else
        {
            newArr[13] = dataArr[13] + 16;
        }
    }
    else
    {
        newArr[13] = dataArr[13];
    }

    newArr[14] = 0;
    newArr[15] = 0;
    newArr[16] = 255;
    newArr[17] = 255;
    newArr[18] = 0;
    newArr[19] = 0;
}
