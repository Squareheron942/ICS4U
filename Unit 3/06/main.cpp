#include <iostream>
#include <stdio.h>

#define PRINT_ARRAY(array, n) for (size_t i = 0; i < n; ++i) std::cout << array[i] << " ";std::cout << std::endl;

template<typename T> void quickSort(T arr[], T* start, T* end) {
    if (start >= end) return;
    int left = start - arr, right = end - arr;
    T pivot = *start;
    bool direction = false;

    std::cout << pivot << " [" << left << " " << right << "]" << std::endl;

    while (left < right) {
        if (direction){
            while ((arr[left] <= pivot) && left - right)
                left++;
            std::swap(arr[left], arr[right]);
        } else {
            while ((arr[right] >= pivot) && left - right)
                right--;
            std::swap(arr[left], arr[right]);
        }
        direction ^= true;
    }
    arr[left] = pivot;
    quickSort(arr, start, arr + left - 1);
    quickSort(arr, arr + right + 1, end);
}

int main() {
    size_t n = 0;

    std::cin >> n;

    int* arr = new int[n];

    for (size_t i = 0; i < n; i++) std::cin >> arr[i];

    quickSort(arr, arr, arr + n - 1);

    PRINT_ARRAY(arr, n);

    delete[] arr;
    return 0;
}