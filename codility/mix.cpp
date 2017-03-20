
#include <algorithm>
#include <string>
#include <iostream>


using namespace std;

int solution(int A, int B) {
    auto a = to_string(A);
    auto b = to_string(B);

    auto i = a.begin();
    auto j = b.begin();

    std::cout << a << " " << b << '\n';

    string res = "";
    const int MAX = 100000000;
    while (i != a.end() || j != b.end()) {
        if (i != a.end()) {
            res += *i;
            ++i;
        }
        if (j != b.end()) {
            res += *j;
            ++j;
        }

        if (stoi(res) > MAX)
            return -1;
    }

    return stoi(res);
}

int main() {
    cout << solution(123, 67845989);
}
