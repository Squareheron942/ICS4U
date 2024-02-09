#include "fraction.h"

#include <assert.h>
#include <string>

#define nonzero(n) assert(n != 0)

long long fraction::gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }

long long fraction::lcm(long long a, long long b) { return (a * b) / gcd(a, b); }

void fraction::simplify() {
    long long divisor = gcd(num, denom);
    num /= divisor;
    denom /= divisor;
}

fraction::fraction(long long num) : num(num), denom(1) {}

fraction::fraction(long long num, long long denom) {
    nonzero(denom);

    if (denom < 0) {
        this->num = -num;
        this->denom = -denom;
    } else {
        this->num = num;
        this->denom = denom;
    }
    simplify();
}

// fraction::fraction(fraction& f) : num(f.num), denom(f.denom) {}

void fraction::set_numerator(long long val) { num = val; simplify(); }

void fraction::set_denominator(long long val) {
    nonzero(val);
    if (val < 0) {
        denom = -val;
        num = -num;
    } else denom = val;
    simplify();
}

fraction fraction::inverse() {
    nonzero(num);
    return fraction(denom, num);
}

fraction fraction::operator*(fraction b) {
    nonzero(b.denom);
    fraction f = *this;
    f *= b.num;
    f /= b.denom;
    f.simplify();
    return f;
}

void fraction::operator*=(fraction b) {
    nonzero(b.denom);
    num *= b.num;
    denom *= b.denom;
    simplify();
}

fraction fraction::operator+(fraction b) {
    fraction f = *this;
    f.num = f.num * b.denom + f.denom * b.num;
    f.denom = f.denom * b.denom;
    f.simplify();
    return f;
}

void fraction::operator+=(fraction b) {
    *this = *this + b;
    simplify();
}

fraction fraction::operator-(fraction b) {
    fraction f = ((*this) + b * -1);
    f.simplify();
    return f;
}

void fraction::operator-=(fraction b) {
    *this += b * -1;
    simplify();
}

fraction fraction::operator/(fraction b) {
    fraction f = *this * b.inverse();
    f.simplify();
    return f;
}

void fraction::operator/=(fraction b) {
    denom *= b.num;
    num *= b.denom;
    simplify();
}

fraction::operator std::string() { return std::to_string(num) + "/" + std::to_string(denom); }
fraction::operator long double() { return (long double)num / denom; }