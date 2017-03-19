#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


template<typename RandomIt>
void selection_sort(RandomIt begin, RandomIt end)
{
    for (auto it = begin; it != end; ++it)
    {
        auto min_element = std::min_element(it, end);
        std::iter_swap(it, min_element);
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

    selection_sort(v.begin(), v.end());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}
