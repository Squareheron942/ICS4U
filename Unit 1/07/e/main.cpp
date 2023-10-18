#include <iostream>

int* twopower(int*& arr, int n, int i = 0);

int main() {
    int *arr = NULL;
    int n = 0;
    std::cin >> n;
    arr = twopower(arr, n);
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}

int power(int a, int b) {
    return b == 0 ? 1 : b > 1 ? a * power(a, --b) : a;
}

int* twopower(int*& arr, int n, int i) {
    if (i >= n) return arr;
    if (i == 0 && arr == nullptr) arr = new int[n];
    arr[i] = power(2, i);
    return twopower(arr, n, ++i);
}