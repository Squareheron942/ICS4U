#pragma once

#include <string>

class fraction {
    long long num, denom;
    long long gcd(long long a, long long b);
    long long lcm(long long a, long long b);
    void simplify();

    public:
    fraction(long long num = 0);
    fraction(long long num, long long denom);
    // fraction(fraction& f);

    inline long long numerator() { return num; }
    inline long long denominator() { return denom; }
    void set_numerator(long long val);
    void set_denominator(long long val);

    fraction inverse();

    fraction operator*(fraction b);
    void operator*=(fraction b);
    fraction operator+(fraction b);
    void operator+=(fraction b);
    fraction operator-(fraction b);
    void operator-=(fraction b);
    fraction operator/(fraction b);
    void operator/=(fraction b);

    operator std::string();
    operator long double();
};