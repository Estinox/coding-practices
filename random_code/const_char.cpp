#include <iostream>

class MyString {
public:
    char c;
    char* cp;

    MyString(char const* cptr) {
        std::cout << "constructor" << std::endl;
        c = 'a';
        cp = &c;
    }

    char& operator[] (int i) {
        std::cout << "1" << std::endl;
        return *cp;
    }

    char const& operator[] (int i) const {
        std::cout << "2" << std::endl;
        return reinterpret_cast<char const&>(*cp);
    }

};

int main() {
    MyString s(reinterpret_cast<char const*>(1));

    char const& a = s[0];
    char& b = s[0];

    std::cout << a << " " << b << std::endl;
}
