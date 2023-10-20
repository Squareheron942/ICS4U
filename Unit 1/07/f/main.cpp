#include <iostream>

int sum(int*, int), recursive_sum(int*, int, int = 0);

int main() {
    int n;
    int* arr = NULL;
    std::cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    // std::cout << sum(arr, n) << std::endl;
    std::cout << recursive_sum(arr, n);
    return 0;
}

int sum(int* arr, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) s += arr[i];
    return s;
}

int recursive_sum(int* arr, int n, int s) {
    if (n == 0) return s; 
    return recursive_sum(arr, n - 1, s + arr[n - 1]);
}