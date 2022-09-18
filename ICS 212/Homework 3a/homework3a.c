#include <stdio.h>

void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{
    int num1, num2 = 10;
    char c1 = 'A';
    char c2 = 'B';
    float score1 = 20.5;
    char ca[3] = "Hi";
    printf("%d\n", argc);
    printf("%p\n", &argc);
    printf("%p\n", argv);
    printf("%p\n", &argv);
    printf("%d\n", num1);
    printf("%p\n", &num1);
    printf("%d\n", num2);
    printf("%p\n", &num2);
    printf("%c\n",c1);
    printf("%p\n", &c1);
    printf("%c\n",c2);
    printf("%p\n", &c2);
    printf("%f\n", score1);
    printf("%p\n", &score1);
    printf("%c\n", ca[0]);
    printf("%p\n", &ca[0]);
    printf("%c\n", ca[1]);
    printf("%p\n", &ca[1]);
    printf("%c\n", ca[2]);
    printf("%p\n", &ca[2]);

    dummy(num2, c1, ca, score1);

    return 0;
}

void dummy(int x, char y, char* z, float w)
{
    x++;
    y++;
    w = w + 2.1;

    printf("%d\n", x);
    printf("%p\n", &x);
    printf("%c\n", y);
    printf("%p\n", &y);
    printf("%p\n", z);
    printf("%p\n", &z);
    printf("%f\n", w);
    printf("%p\n", &w);

    /* pause here */
}