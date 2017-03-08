#include <cmath>
#include <iterator>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

template <typename InputIt, typename OutputIt>
auto candies(InputIt begin, InputIt end, OutputIt out)
{
    int prev_rating = 0;
    int curr_rating = 0;
    int prev_candy = 0;

    //for (int i = 0; i < v.size(); ++i) {
    for (auto it = begin; it != end; std::advance(it, 1)) {
        if (prev_rating < *it)
            ++prev_candy;
        else if (prev_rating >= *it)
            prev_candy = 1;

        //std::cout << "prev_candy: " << prev_candy << ", prev_rating: " << prev_rating << ", curr_rating: " << curr_rating << '\n';
        prev_rating = *it;
        *out = prev_candy;
        ++out;
    }
}

template <typename InputIt, typename OutputIt>
void max_by_element(InputIt v1_begin, InputIt v1_end, InputIt v2_begin, OutputIt out) {
    for (; v1_begin != v1_end; ++v1_begin, ++v2_begin) {
        //std::cout << *v1_begin << " " << *v2_begin << " = " << std::max(*v1_begin, *v2_begin) << std::endl;
        *out = std::max(*v1_begin, *v2_begin);
        ++out;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0;
    std::cin >> n;

    std::vector<int> r;

    for (int i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;
        r.push_back(x);
    }
    //std::copy(r.cbegin(), r.cend(), std::ostream_iterator<int>(std::cout, " ")); std::cout << endl;

    std::vector<int> forward(n);
    std::vector<int> backward(n);

    candies(r.cbegin(), r.cend(), forward.begin());
    candies(r.rbegin(), r.rend(), backward.rbegin());

    // cout
    //std::copy(forward.cbegin(), forward.cend(), std::ostream_iterator<int>(std::cout, " ")); std::cout << endl;
    //std::copy(backward.cbegin(), backward.cend(), std::ostream_iterator<int>(std::cout, " ")); std::cout << endl;

    std::vector<int> max_vector(n);
    max_by_element(forward.cbegin(), forward.cend(), backward.cbegin(), max_vector.begin());
    //std::copy(max_vector.cbegin(), max_vector.cend(), std::ostream_iterator<int>(std::cout, " ")); std::cout << endl;

    std::cout << std::accumulate(max_vector.cbegin(), max_vector.cend(), 0);

    return 0;
}
