#include <iostream>
#include <iomanip>
#include <limits.h>
#include <cmath>

using namespace std;

int zero_bits(unsigned int value) {
    int num = 0;
    for(size_t i = 0; i < 30; ++i)
    {
        if ((value & (1 << i)) == 0)
            ++num;
    }
    return num;
}

int solution(int A, int B, int C) {
    long one = pow(2, zero_bits(A)) + pow(2, zero_bits(B)) + pow(2, zero_bits(C));
    long two = pow(2, zero_bits(A|B)) + pow(2, zero_bits(A|C)) + pow(2, zero_bits(B|C));
    long three = pow(2, zero_bits(A|B|C));
    long sum = one - two + three;
    return static_cast<int>(sum);
}

int main() {
    //cout << solution(1073741727, 1073741631, 1073741679);
    cout << solution(1073741727, 1073741631, 1073741679);

    return 0;
}
