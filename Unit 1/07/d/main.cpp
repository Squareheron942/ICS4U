#include <time.h>
#include <random>
#include <stdio.h>

void init_array(int*&, int = 0);

int main() {
    tm now;
    srand(timelocal(&now));
    int* arr = new int[10];;
    init_array(arr);
    if (arr != nullptr) for (int i = 0; i < 10; i++) printf("%u ", arr[i]);
    printf("\n");
    delete[] arr;
    return 0;
}

void init_array(int*& arr, int beginIndex) {
    arr[beginIndex] = rand() % 50 + 1;
    if (beginIndex < 9) init_array(arr, ++beginIndex);
}