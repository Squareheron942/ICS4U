#include <iostream>

void printArray(int*, int, int);

int main() {
    int length = 0;
    std::cin >> length;
    int *a = new int[length];
    for (int i = 0; i < length; i++) std::cin >> a[i];
    printArray(a, length, 0);
}

void printArray(int* array, int length, int startindex) {
    std::cout << array[startindex] << " ";
    if (length - startindex == 1) {std::cout << std::endl;return;}
    printArray(array, length, ++startindex);
}