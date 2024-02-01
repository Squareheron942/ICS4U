#include <iostream>
#include <string>
#include <utility>

#define PRINT_ARRAY(array, n) for (size_t i = 0; i < n; ++i) std::cout << array[i] << " ";std::cout << std::endl;

template<typename T>
void insertionSort(T array[], size_t n, bool quiet = false) {
    for (size_t j = 1; j < n; ++j) {
        if (!quiet) {PRINT_ARRAY(array, n)}
        for (size_t k = 0; k < j; k++) {
            if (array[k] > array[j]) {
                T temp = array[j];
                for (size_t l = j; l > k; --l) array[l] = array[l - 1];
                array[k] = temp;
            }
        }
    }
    if (!quiet) {PRINT_ARRAY(array, n)}
}

int main() {

    std::cout << "Q1" << std::endl;

    int Q1[] = {6, 2, 8, 3, 1, 7, 4};

    insertionSort(Q1, 7);

    /**
     * Q2
     * 
     * The comparison operator direction would need to be swapped
     * (code added to show how it could be done)
     */

    std::cout << "Q3" << std::endl;

    std::string Q3[] = {
        "mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune"
    };

    insertionSort(Q3, 8);

    std::cout << "Q4" << std::endl;

    int n;
    double *Q4;

    std::cin >> n;

    Q4 = (double*)malloc(n * sizeof(double));

    for (int i = 0; i < n; ++i) std::cin >> Q4[i];

    insertionSort(Q4, n, true);

    if (n % 2) std::cout << Q4[n >> 1] << std::endl;
    else std::cout << ((Q4[n >> 1]) + Q4[(n >> 1) - 1]) * 0.5 << std::endl;

    free(Q4);

    return 0;
}