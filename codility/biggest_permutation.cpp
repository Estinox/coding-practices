#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

string repeat(string s, int n) {
    string res = "";
    for (int i = 0; i < n; ++i)
        res += s;
    return res;
}

int solution(int N) {
    vector<int> count(9,0);

    do {
        count[N%10] += 1;
        N = N / 10;
    } while (N > 0);


    //copy(count.rbegin(), count.rend(), ostream_iterator<int>(cout, " "));

    string res = "";
    //for (auto it = count.rbegin(); it < count.rend(); ++it) {
    for (int i = 9; i >= 0; --i) {
        res += repeat(to_string(i), count[i]);
        //std::cout << res << '\n';
    }

    if (stol(res) > 100000000)
        return -1;

    return stoi(res);
}

int main() {
    std::cout << solution(2147483647);
    return 0;
}
