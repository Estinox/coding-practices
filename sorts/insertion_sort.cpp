#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <type_traits>
#include <typeinfo>

template<typename RandomIt>
    std::enable_if_t<std::is_same<typename std::iterator_traits<RandomIt>::iterator_category, std::random_access_iterator_tag>::value>
insertion_sort(RandomIt begin, RandomIt end)
{
    for (auto it = begin; it != end; ++it) {
        auto upper = std::upper_bound(begin, it, *it);
        std::rotate(upper, it, it+1);
    }
}

int main() {
    size_t n = 0;
    std::cin >> n;

    std::vector<int> v;
    v.reserve(n);

    for (size_t i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;

        //std::cout << "pushing back " << x << '\n';
        v.push_back(x);
    }

    insertion_sort(v.begin(), v.end());

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}
