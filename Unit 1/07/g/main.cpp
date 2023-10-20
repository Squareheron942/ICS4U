#include <iostream>

int largest(int*, int), recursive_largest(int*, int, int = INT32_MIN);

int main() {
    int n;
    int* arr = NULL;
    std::cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    // std::cout << largest(arr, n) << std::endl;
    std::cout << recursive_largest(arr, n);
    return 0;
}

int largest(int* arr, int n) {
    int s = INT32_MIN;
    for (int i = 0; i < n; i++) s = arr[i] > s ? arr[i] : s;
    return s;
}

int recursive_largest(int* arr, int n, int s) {
    if (n == 0) return s;
    return recursive_largest(arr, n - 1, arr[n - 1] > s ? arr[n - 1] : s);
}