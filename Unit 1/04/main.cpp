#include <iostream>
#include <random>
#include <cstring>

static int* array;

void q1a(), q1b(), q1c(), q1d();

template<class T>
void alloc(T**, int);

int main() {
    return 0;
}

template<class T>
void alloc(T** array, int size) {
    *array = new T[size];
}

void q1a() {
    int size;
    std::cin >> size;
    alloc(&array, size);
    for (int i = 0; i < size; ++i) std::cout << array[i];
    delete[] array;
}

void q1b() {
    int size;
    std::cin >> size;
    alloc(&array, size);
    for (int i = 0; i < size; ++i) std::cout << array[size - i - 1];
    delete[] array;
}

void q1c() {
    int size, sum = 0;
    std::cin >> size;
    alloc(&array, size);
    for (int i = 0; i < size; ++i) array[i] = rand() % 51 + 1;
    for (int i = 0; i < size; ++i) sum += array[i];
    std::cout << sum;
    delete[] array;
}

void q1d() {
    int *arr1, *arr2, *arr3;
    int size1, size2;
    std::cin >> size1;
    std::cin >> size2;
    alloc(&arr1, size1);
    alloc(&arr2, size2);
    alloc(&arr3, size1 + size2);
    
    memcpy(arr3, &arr1, sizeof(int) * size1);
    memcpy(&arr3[size1], &arr2, sizeof(int) * size2);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}