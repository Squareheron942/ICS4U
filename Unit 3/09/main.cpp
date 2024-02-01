#include <iostream>
#include <string>
#include <utility>
#include <math.h>

#define PRINT_ARRAY(array, n) for (size_t i = 0; i < n; ++i) std::cout << array[i] << " ";std::cout << std::endl;

size_t calck(size_t n) {
    size_t ks[] = {1, 2, 4};
    size_t halfn = n >> 1, k = 9;
    if (halfn <= 5) return halfn <= 2 ? 1 : halfn <= 4 ? 2 : 4;
    else while (halfn < k) (k <<= 1)++;
    return k;
}

template<typename T>
size_t insertionSort(T array[], size_t n) {
    size_t nshifts = 0;
    for (size_t j = 1; j < n; ++j) {
        for (size_t k = 0; k < j; k++) {
            if (array[k] > array[j]) {
                T temp = array[j];
                for (size_t l = j; l > k; --l) array[l] = array[l - 1];
                array[k] = temp;
                ++nshifts;
    }   }   }
    return nshifts;
}

template<typename T>
size_t sublistSort(T* array[], size_t n) {
    size_t nshifts = 0;
    for (size_t j = 1; j < n; ++j) {
        for (size_t k = 0; k < j; k++) {
            if (*array[k] > *array[j]) {
                T temp = *array[j];
                for (size_t l = j; l > k; --l) *array[l] = *array[l - 1];
                *array[k] = temp;
                ++nshifts;
    }   }   }
    return nshifts;
}

template<typename T>
size_t shellSort(T array[], size_t n) {
    // calculate k from length
    size_t k = calck(n);
    size_t nshifts = 0;
    do {
        for (int i = 0; i < k; i++) {
            size_t len = ceilf((n - i) / (float)k);
            T** arr = new T*[len];
            // create sub array referencing the elements
            for (int j = 0; j < len; j++) arr[j] = &array[j * k + i];
            // add the number of shifts
            nshifts += sublistSort(arr, len);
            delete[] arr;
        }

        // decrement k by one index
        if (k > 4) --k >>= 1;
        else k >>= 1;
    } while (k);
    return nshifts;
}

int* r_binsearch_i(int* a, int v, int l) {
    int halfl = (l - 1) >> 1;
    if (halfl < 1) return NULL;
    if (l == 1 || a[halfl] == v) return a + halfl;
    return (a[halfl] > v ? r_binsearch_i(a, v, halfl) : r_binsearch_i(a + halfl + 1, v, halfl)); 
}

int binarysearch(int* array, int val, int len) {
    int* foundval = r_binsearch_i(array, val, len);
    if (foundval == nullptr) return -1;
    if (*foundval == val) return foundval - array;
    return -1;
}

int main() {
    size_t len, val;
    std::cin >> len;

    int* arr = new int[len];
    int* arr2 = new int[len];

    for (int i = 0; i < len; i++) std::cin >> arr[i];
    for (int i = 0; i < len; i++) arr2[i] = arr[i];

    std::cin >> val;

    size_t nshiftsshell = shellSort(arr, len);
    size_t nshiftsinsert = insertionSort(arr2, len);

    std::cout << nshiftsinsert << std::endl;
    std::cout << nshiftsshell << std::endl;

    std::cout << ((nshiftsshell > nshiftsinsert) ? "Insertion" : ((nshiftsshell == nshiftsinsert) ? "Same" : "Shell")) << std::endl;

    size_t i = binarysearch(arr, val, len);

    std::cout << (abs((long)(arr[i + 1] - val)) < abs((long)(arr[i - 1] - val)) ? arr[i + 1] : arr[i - 1]) << std::endl;
}