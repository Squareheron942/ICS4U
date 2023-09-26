#include <math.h>

void cubeByPointer(int*), sumTwoInt(int*, int*), circle(int*, int*, int*), swap(float*, float*), SquareComplex(double&, double&);
bool quadEquation(float*, float*, float*, float*, float*);

int main() {
    
    return 0;
}

void cubeByPointer(int* n) { *n = *n * *n * *n; }

void sumTwoInt(int* num1, int* num2) { *num1 += *num2; }

void circle(float* radius, float* area, float* circumference) { *area = *radius * *radius * 3.1415926535; *circumference = 2 * 3.1415926535 * *radius;}

bool quadEquation(float* a, float* b, float* c, float* s1, float* s2) {
    bool has_s = (*b * *b - 4 * *a * *c) >= 0;
    if (has_s) {
        float denum = 1 / (2 * *a);
        *s1 = (-*b + sqrt(*b * *b - 4 * *a * *c)) * denum;
        *s2 = (-*b - sqrt(*b * *b - 4 * *a * *c)) * denum;
        return true;
    }
    return false;
}

void swap(float *p1, float *p2) {
    // the value of the pointers are swapped, but only the copies passed in are swapped.
    // to swap the value of x and y the pointers need to be dereferenced and the
    // values they point to need to be swapped

    // float *temp;
    // temp = p1;
    // p1 = p2;
    // p2 = temp;

    float temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Squares a complex number a + bi
void SquareComplex(double &a, double &b) {
    // a is modified before it is used to calculate b meaning b will be wrong
    // a = a*a - b*b;
    // b = 2*a*b;

    double tmp_a = a;
    a = a*a - b*b;
    b = 2*tmp_a*b;
}