#include <iostream>

void del_np(int, int**);

int main() {
    int size = 0;
    std::cin >> size;
    size++;
    int *arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = 1;
    del_np(size, &arr);
    for (int i = 2; i < size; i++) if (arr[i]) std::cout << i << ' ';
    return 0;
}

void del_np(int size, int** arr) {
    for (int i = 2; i < size; ++i) {
        int n = 2;
        while ((i * n) < size) {
            (*arr)[i * n] = 0;
            n++;
        };
    }
}