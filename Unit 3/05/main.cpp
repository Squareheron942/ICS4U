#include <iostream>
#include <string>
#include <utility>
#include <math.h>
#include <stdio.h>

#define PRINT_ARRAY_CAPPED(array, n)\
    for (size_t i = 0; i < n; ++i) {\
        if (i % 10 == 0 && i != 0) std::cout << std::endl;std::cout << array[i] << " ";\
    }\
    std::cout << std::endl;

#define PRINT_ARRAY(array, n)\
    for (size_t i = 0; i < n; ++i) std::cout << array[i] << " ";\
    std::cout << std::endl;

void decremk(size_t& k);

size_t calck_2n_add_1(size_t n) {
    size_t halfn = n >> 1, k = 9;
    if (halfn <= 5) return halfn <= 2 ? 1 : halfn <= 4 ? 2 : 4;
    else while (halfn > k) (k <<= 1)++;
    return k;
}

void decremk_2n_add_1(size_t& k) {
    if (k > 4) --k >>= 1;
    else k >>= 1;
}

// Q4a
size_t calck(size_t n) {
    size_t thirdn = n / 3, k = 1;
    while (thirdn > k) (k *= 3)++;
    decremk(k);
    return k;
}

// Q4b
void decremk(size_t& k) {
    --k /= 3;
    // if (k < 1) k = 1;
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
        for (size_t i = 0; i < k; i++) {
            size_t len = ceilf((n - i) / (float)k);
            T** arr = new T*[len];
            // create sub array referencing the elements
            for (size_t j = 0; j < len; j++) arr[j] = &array[j * k + i];
            // add the number of shifts
            nshifts += sublistSort(arr, len);
            delete[] arr;
        }
        printf("%luk sort list:\n", k);
        PRINT_ARRAY_CAPPED(array, n);
        if (k != 1) std::cout << std::endl;

        // decrement k by one index
        decremk(k);
    } while (k);
    return nshifts;
}

int main() {
    // Q1
    std::cout << "Q1" << std::endl;
    int arr0[] = {
        26, 37, 21, 41, 63, 19, 61, 72, 55, 29, 47, 18, 26, 22
    };
    size_t k = 5, n0 = 14;
    for (size_t i = 0; i < k; i++) {
        size_t len = ceilf((n0 - i) / (float)k);
        int** arr = new int*[len];
        // create sub array referencing the elements
        for (size_t j = 0; j < len; j++) arr[j] = &arr0[j * k + i];
        // add the number of shifts
        sublistSort(arr, len);
        delete[] arr;
    }

    PRINT_ARRAY(arr0, 14)

    // Q2
    std::cout << "Q2" << std::endl;
    
    k = 4;

    for (size_t i = 0; i < k; i++) {
        size_t len = ceilf((n0 - i) / (float)k);
        int** arr = new int*[len];
        // create sub array referencing the elements
        for (size_t j = 0; j < len; j++) arr[j] = &arr0[j * k + i];
        // add the number of shifts
        sublistSort(arr, len);
        delete[] arr;
    }

    PRINT_ARRAY(arr0, 14)

    // Q3
    /*
    
    Insertion sort is faster on almost-sorted arrays, so 
    it ends up being faster to pre-sort the array in 
    smaller chunks (which are also faster since insertion 
    sort is O(n^2)) before sorting the entire array.

    */
    
    // Q4

    // Q5
    size_t n;

    std::cin >> n;

    int* arr = new int[n];

    for (size_t i = 0; i < n; i++) std::cin >> arr[i];

    std::cout << "Q5" << std::endl;

    shellSort(arr, n);

    // Q6

    /**
     * 
     * Doing k = n, k(n) = k(n-1) + 1 was slowest
     * 
     * k = n / 4, k(n) = k(n-1) * 4 + 1 was slightly faster but quite similar, depending on the length and per run it would change
     */

    return 0;
}