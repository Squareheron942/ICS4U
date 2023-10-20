#include <iostream>
#include <math.h>
#include <random>
#include <time.h>

#define NUM_TRIALS 10000000

unsigned long long int factorial(int);
double bdayproblem(int);
double recursive_bdayproblem(int n);

int main() {
    int n = 0;
    std::cin >> n;
    time_t t;
    localtime(&t);
    srand(t);
    std::cout << 1 - recursive_bdayproblem(n) << std::endl;
    // std::cout << bdayproblem(n) << std::endl;
    return 0;
}

unsigned long long int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

double bdayproblem(int n) {
    // int numMatches = 0;
    // int* birthdays = new int[n];
    // for (int trial = 0; trial < NUM_TRIALS; trial++)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         birthdays[i] = (rand() % 365) + 1;

    //         for(int j = 0; j < i; j++){
    //             if(birthdays[j] == birthdays[i]){
    //                 if (j != i)
    //                     numMatches++;
    //             }
    //         }               
    //     }
    // }
    // return numMatches / float(NUM_TRIALS);

    // mid approximation, not close enough but generally ok
    return 1 - pow(2.718281828, -n*n*0.001369863014);
}

double recursive_bdayproblem(int n) {
    if (n <= 1) return 1;
    return (366 - n) * 0.002739726027 * recursive_bdayproblem(n - 1);
}