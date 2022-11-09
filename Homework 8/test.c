#include <stdio.h>

int main()
{
    FILE *fptr;
    unsigned char buffer[20];
    int i;
    unsigned char header[2];


    fptr = fopen("request1.bin", "rb+");

    fread(buffer, sizeof(buffer), 1, fptr);

    fclose(fptr);

    header[0] = buffer[1];
    header[1] = buffer[0];

    //multiply each individual component by its place value ie for ff12 make it ff00 + 12
    printf("%d",header[0] header[1]);

    return 0;

}