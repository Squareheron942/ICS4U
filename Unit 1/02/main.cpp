#include <stdio.h>

void q1(), q2(), q3();

int main() {
    q1();
    q2();
    q3();
}

void q1() {
    int number = 123;
    int *pnumber;
    pnumber = &number;
    printf("%u\n%p\n%p\n%u\n", number, &number, pnumber, *pnumber);
}

void q2() {
    int num1 = 50, num2 = 100;
    int *pnum = NULL;
    pnum = &num1;
    *pnum += 10;
    printf("%u\n%p\n%u\n", num1, pnum, *pnum);
}

void q3() {
    double value1 = 200000, value2;
    double *lPtr;
    lPtr = &value1;
    printf("%f\n", *lPtr);
    value2 = *lPtr;
    printf("%p\n", &value2);
    printf("%f\n", value2);
    printf("%p\n", &value1);
    printf("%p\n", lPtr);
}