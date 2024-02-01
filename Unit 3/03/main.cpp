#include <iostream>
#include <string>

#define PRINT_ARRAY(array, n) for (size_t i = 0; i < n; ++i) std::cout << array[i] << " ";std::cout << std::endl;

template<typename T> void selectionSort(T arr[], size_t len, bool smallestFirst) {
    T* selected = arr, temp; // assume largest/smallest is first one
    PRINT_ARRAY(arr, len)
    
    if (smallestFirst) {
        for (size_t i = 0; i < len - 1; i++) {
            for (size_t j = i; j < len; j++)
                if (arr[j] <= *selected) selected = arr + j;
            temp = arr[i];
            arr[i] = *selected;
            *selected = temp;
            PRINT_ARRAY(arr, len)
        }
    } else {
        for (size_t i = len - 1; i > 0; i--) {
            for (size_t j = 0; j <= i; j++) 
                if (arr[j] > *selected) selected = arr + j;
            temp = arr[i];
            arr[i] = *selected;
            *selected = temp;
            PRINT_ARRAY(arr, len)
        }
    }
}

template<typename T> void selectionSort(T arr[], size_t len, size_t k, bool smallestFirst) {
    T* selected = arr, temp; // assume selected is first one
    // PRINT_ARRAY(arr, len)
    if (smallestFirst) {
        for (size_t i = 0; i < len && i < k; i++) {
            for (size_t j = i; j < len; j++)
                if (arr[j] <= *selected) selected = arr + j;
            temp = arr[i];
            arr[i] = *selected;
            *selected = temp;
            // PRINT_ARRAY(arr, len)
        }
    } else {
        for (size_t i = len - 1; i > 0 && len - i <= k; i--) {
            for (size_t j = 0; j <= i; j++) 
                if (arr[j] > *selected) selected = arr + j;
            temp = arr[i];
            arr[i] = *selected;
            *selected = temp;
            // PRINT_ARRAY(arr, len)
        }
    }
}

int main() {
    
    // Q1
    std::cout << "Q1" << std::endl;

    std::string arr[] = {"Robert", "Brian", "Victor", "David", "Scott"};

    selectionSort(arr, 5, false);

    // Q2

    /**
     * if the expression arr[j] > arr[max_pos] were to be changed to arr[j] < arr[max_pos], 
     * the array would be sorted in reverse order
     */

    // Q3

    /**
     * An extra check could be implemented to ensure that a value is not swapped with itself. 
     * 
     * However, implementing such a check would introduce branching behaviour, which could end up causing 
     * the code to run more slowly than if the redundant swaps were made, especially on a system that is 
     * processor-limited and not bandwidth-limited.
     */


    // Q4
    std::cout << "Q4" << std::endl;
    int arr2[] = {8, 9, 6, 1, 2, 4};

    selectionSort(arr2, 6, true);

    // Q5
    std::cout << "Q5" << std::endl;

    int n, k;

    std::cin >> n;
    std::cin >> k;

    int* arr3 = new int[n];

    for (int i = 0; i < n; i++) std::cin >> arr3[i];

    selectionSort(arr3, n, k, false);
    PRINT_ARRAY(arr3, (size_t)n);

    delete[] arr3;

    return 0;
}