#include <iostream>
#include <climits>

#define PRINT_ARRAY(a, l) for (int i = 0; i < l; i++) std::cout << a[i] << " ";std::cout << std::endl;

int binarysearch(int* array, int val, int len);
int linearsearch(int* array, int val, int len);
int* sort(int* array, int len);

int main() {
    int len, val;
    std::cin >> len;
    std::cin >> val;
    int* arr = new int[len];
    int* sorted;

    for (int i = 0; i < len; i++) 
        std::cin >> arr[i];
     
    sorted = sort(arr, len);

    std::cout << "Linear Search" << std::endl;
    int index = linearsearch(sorted, val, len);
    (index >= 0 ? std::cout << "found at index " << index << std::endl : std::cout << "not found" << std::endl); 
    std::cout << std::endl;
    std::cout << "Binary Search" << std::endl;
    index = binarysearch(sorted, val, len);
    (index >= 0 ? std::cout << "found at index " << index << std::endl : std::cout << "not found" << std::endl);

    delete[] arr;
    delete[] sorted;
}

int* sort(int* array, int len) { // selection sort
    int* out = new int[len];
    int* lowest = &array[0];
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) 
            if (array[j] < *lowest) lowest = &array[j];
        out[i] = *lowest;
        *lowest = INT_MAX;
    }
    return out;
}

int* r_binsearch_i(int* a, int v, int l) {
    PRINT_ARRAY(a, l);
    int halfl = ((l - 2) >> 1) + 1;
    if (l == 1 || a[halfl] == v) return a + halfl;
    return (a[halfl] > v ? r_binsearch_i(a, v, halfl) : r_binsearch_i(a + halfl + 1, v, halfl)); 
}

int binarysearch(int* array, int val, int len) {
    int* foundval = r_binsearch_i(array, val, len);
    if (*foundval == val) return foundval - array;
    return -1;
}

int* r_linearsearch_i(int* a, int v, int l) {
    PRINT_ARRAY(a, l);
    if (l == 1 || *a == v) return a;
    return r_linearsearch_i(a + 1, v, l - 1);
}

int linearsearch(int* array, int val, int len) {
    int* foundval = r_linearsearch_i(array, val, len);
    if (*foundval == val) return foundval - array;
    return -1;
}