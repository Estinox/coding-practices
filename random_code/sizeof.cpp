#include <iostream>
#include <cstdint>

struct St {
    long i;
    char c;
    char c2;
    int a;
};

int main()
{
    St s();
    std::cout << sizeof(uint64_t) << std::endl;
}
