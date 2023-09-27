#include <iostream>
#include <random>
#include <cstring>

void q1a(), q1b(), q1c(), q2();

void modifyArray (int*, int);
void modifyElement(int&);
int main()
{
int element[5];
for (int index =0; index <= 4; index++)
element[index] = index;
std::cout << "Effects of passing entire array call by reference\n\n";
std::cout << "Value of the original array is \n";
for (int x = 0; x <= 4; x++)
std::cout << element[x] << " ";
std::cout << std::endl;
modifyArray (element, 5);
std::cout << std::endl << std::endl;
std::cout << "Effects of passing array element call-by-value\n\n";
std::cout << "The value of element[3] is " << element[3] << std::endl;
modifyElement(element[3]);
std::cout << "The value of element[3] is " << element[3] << std::endl;
return 0;
}
void modifyArray(int *b, int ArraySize){
    for (int i = 0; i < ArraySize; i++) {b[i] *= 2;std::cout << b[i];}
}
void modifyElement(int &a)
{
    a *= 2;
    std::cout << a << std::endl;
}

void q1a() {
    int sx, sy, *arr;
    std::cin >> sx;
    std::cin >> sy;
    arr = new int[sx * sy]; // same as 2d array, it makes no difference in memory
    for (int i = 0; i < sy; i++) for (int j = 0; j < sx; j++) std::cin >> arr[i * sx + j];
    for (int i = 0; i < sy; i++) {for (int j = 0; j < sx; j++) std::cout << arr[i * sx + j];std::cout<<std::endl;}
    delete[] arr;
}

void q1b() {
    int sx, sy, *arr, sum = 0;
    std::cin >> sx;
    std::cin >> sy;
    arr = new int[sx * sy]; // same as 2d array, it makes no difference in memory
    for (int i = 0; i < sy; i++) for (int j = 0; j < sx; j++) arr[i * sx + j] = rand() % 1000;
    for (int i = 0; i < sy; i++) for (int j = 0; j < sx; j++) sum += arr[i * sx + j];
    std::cout << sum / (sx * sy) << std::endl;
    delete[] arr;
}

void q1c() {
    int sx, *arr;
    std::cin >> sx;
    arr = new int[sx * sx]; // same as 2d array, it makes no difference in memory
    for (int i = 0; i < sx; i++) for (int j = 0; j < sx; j++) std::cin >> arr[i * sx + j];
    for (int i = 0; i < sx; i++) std::cout << arr[i * (sx + 1)];
    delete[] arr;
}

void q2() {
    int sx1, sy1, *arr1 = NULL, sx2, sy2, *arr2 = NULL;
    std::cin >> sx1;
    std::cin >> sy1;
    arr1 = new int[sx1 * sy1]; // same as 2d array, it makes no difference in memory
    for (int i = 0; i < sy1; i++) for (int j = 0; j < sx1; j++) std::cin >> arr1[i * sx1 + j];
    for (int i = 0; i < sy1; i++) {for (int j = 0; j < sx1; j++) std::cout << arr1[i * sx1 + j] << " ";std::cout<<std::endl;}
    std::cin >> sx2;
    std::cin >> sy2;
    arr2 = new int[sx2 * sy2]; // same as 2d array, it makes no difference in memory
    for (int i = 0; i < sy2; i++) for (int j = 0; j < sx2; j++) std::cin >> arr2[i * sx2 + j];
    int s = sx1 * sy1 + sx2 * sy2, *arr3 = NULL;
    arr3 = new int[s];
    memcpy(arr3, arr1, sx1 * sy1 * sizeof(int));
    memcpy(&arr3[sx1 * sy1], arr2, sx2 * sy2 * sizeof(int));
    for (int i = 0; i < s; i++) std::cout << arr3[i] << " ";

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}

