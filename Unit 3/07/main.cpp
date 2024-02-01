#include <iostream>
#include <cmath>

#define PRINT_ARRAY(array, n) for (size_t i = 0; i < n; ++i) std::cout << array[i] << " ";std::cout << std::endl;

size_t npasses;

template<typename T>
void insertionSort(T array[], size_t n) {
    for (size_t j = 1; j < n; ++j) {
        for (size_t k = 0; k < j; k++) {
            if (array[k] > array[j]) {
                T temp = array[j];
                for (size_t l = j; l > k; --l) array[l] = array[l - 1];
                array[k] = temp;
}   }   }   }


template<typename T> void mergeSort(T arr[], size_t n) {
    npasses++;
    if (n > 2) { // no need to split completely into 1-long arrays
        mergeSort(arr, ceilf(n / 2.0f));
        mergeSort(arr + (int)ceilf(n / 2.0f), n >> 1);
    }
    insertionSort(arr, n);
}

int main() {
    npasses = 0;
    size_t n = 0;
    std::cin >> n;

    std::string* arr = new std::string[n];
    for (size_t i = 0; i < n; i++) std::cin >> arr[i];
    mergeSort(arr, n);
    std::cout << npasses << std::endl;
    PRINT_ARRAY(arr, 6);
    return 0;
}