#include <iostream>

template <typename T>
inline T const& max (T const& a, T const& b)
{
    std::cout << "called with " << a << " " << b << std::endl;
    return a < b ? b : a;
}

int main() {
    char char_a = 'a';
    char char_b = 'b';
    char* pointer_char_a = &char_a;
    char const* const& a = pointer_char_a;
    const char* const& a_prime = pointer_char_a;
    
    std::cout << "a: " << *a << " " << *a_prime << std::endl;

    int i = 42;
    std::cout << "max(7, i): " << max(7,i) << std::endl;

    // this casts the params into ints
    std::cout << "max(1.2, 4.3): " << max<int>(1.2, 4.3) << std::endl;
}
