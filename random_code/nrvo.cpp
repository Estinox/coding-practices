#include <iostream>

struct fractional_parts {
    int numerator;
    int denominator;
};

fractional_parts convertToFraction(double val) {
    int numerator = 1/*calculation */ ;
    int denominator = 2/*calculation */ ;
    return {numerator, denominator}; // C++11 braced initialisation -> RVO
}


int main () {
    auto parts = convertToFraction(1.);
    std::cout << parts.numerator << " " << parts.denominator << std::endl;
}
