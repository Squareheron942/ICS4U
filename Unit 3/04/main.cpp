#include <iostream>
#include <string>
#include <utility>

#define PRINT_ARRAY(array, n) for (size_t i = 0; i < n; ++i) std::cout << array[i] << " ";std::cout << std::endl;

enum sort_order {
    ASCENDING = 0,
    DESCENDING = 1
};

template<typename T>
bool arraySorted(T array[], size_t n, sort_order order = ASCENDING) {
    for (size_t i = 0; i < n - 1; ++i) 
        if (order ? array[i] < array[i + 1] : array[i] > array[i + 1]) return false;
    return true;
}

template<typename T>
void bubbleSort(T array[], size_t n, sort_order order = ASCENDING, bool quiet = false) {
    size_t end = 0;
    while (!arraySorted(array, n, order)) {
        end++;
        if (!quiet) {PRINT_ARRAY(array, n)}
        for (size_t i = 0; i < n - end; ++i)
            if (order ? array[i] < array[i + 1] : array[i] > array[i + 1])
                std::swap(array[i], array[i + 1]);
    }
    if (!quiet) {PRINT_ARRAY(array, n)}
}

template<typename T>
size_t shakerSort(T array[], size_t n, sort_order order = ASCENDING, bool quiet = false) {
    size_t end = n - 1, start = 0, swaps = 0;
    while (!arraySorted(array, n, order)) {
        if (!quiet) {PRINT_ARRAY(array, n)}
        for (size_t i = 0; i < end; ++i)
            if (order ? array[i] < array[i + 1] : array[i] > array[i + 1])
                {std::swap(array[i], array[i + 1]);++swaps;}
        end--;

        if (arraySorted(array, n, order)) return swaps;

        for (size_t i = end; i > start; --i)
            if (order ? array[i] < array[i + 1] : array[i] > array[i + 1])
                {std::swap(array[i], array[i + 1]);++swaps;}
        start++;
    }
    if (!quiet) {PRINT_ARRAY(array, n)}
    return swaps;
}

int main() {

    std::cout << "Q1" << std::endl;

    std::cout << "(3  8) 3  2  7  5\n"
                " 3 (8  3) 2  7  5\n"
                " 3  3 (8  2) 7  5\n"
                " 3  3  2 (8  7) 5\n"
                " 3  3  2  7 (8  5)\n"
                "(3  3) 2  7  5  8\n"
                " 3 (3  2) 7  5  8\n"
                " 3  2 (3  7) 5  8\n"
                " 3  2  3 (7  5) 8\n"
                "(3  2) 3  5  7  8\n"
                " 2 (3  3) 5  7  8\n"
                " 2 (3  3) 5  7  8\n"
                " 2  3 (3  5) 7  8\n"
                "(2  3) 3  5  7  8\n"
                " 2 (3  3) 5  7  8\n"
                "(2  3) 3  5  7  8\n"
                " 2  3  3  5  7  8\n";

    /**
     * Q2
     * 
     * To make bubble sort work in reverse order, array[i] < array[i + 1] should be changed to array[i] > array[i + 1]
     */

    std::cout << "Q3" << std::endl;

    std::cout << "(2  9) 4  6  1  7  4\n"
                " 2 (9  4) 6  1  7  4\n"
                " 2  4 (9  6) 1  7  4\n"
                " 2  4  6 (9  1) 7  4\n"
                " 2  4  6  1 (9  7) 4\n"
                " 2  4  6  1  7 (9  4)\n"
                " 2  4  6  1 (7  4) 9\n"
                " 2  4  6 (1  4) 7  9\n"
                " 2  4 (6  1) 4  7  9\n"
                " 2 (4  1) 6  4  7  9\n"
                "(2  1) 4  6  4  7  9\n"
                " 1  2  4  6  4  7  9\n";

    std::cout << "Q4" << std::endl;
    double *Q4;
    size_t n;

    std::cin >> n;

    Q4 = new double[n];

    for (size_t i = 0; i < n; i++) std::cin >> Q4[i];

    size_t swaps = shakerSort(Q4, n, ASCENDING, true);

    PRINT_ARRAY(Q4, n);

    std::cout << swaps << std::endl;

    delete[] Q4;

    return 0;
}