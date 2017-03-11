#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

template <typename RandomIt>
std::enable_if(std::void merge_sort_helper(RandomIt begin, RandomIt end)
{
    if (begin == end)
        return;


    auto mid = begin + (std::distance(begin, end)/2 - 1);
    //merge_sort_helper(begin, mid);
    //merge_sort_helper(mid+1, end);

    std::cout << "begin=" << *begin
        << ",mid=" << *mid
        << ",end=" << *end
        << '\n';

    if (mid+1 == end)
        return;

    for (auto first = begin, second = (mid+1); first != (mid+1) || second != end;) {
        std::cout << "comparing " << *begin << " vs " << *(mid+1) << " = " << (*first < *(mid+1)) << '\n';
        if (*first > *(mid+1)) {
            std::iter_swap(begin, mid+1);
            ++first;
            continue;
        }

        ++second;
    }
}

template <typename Container>
void merge_sort(Container& v) {
    merge_sort_helper(v.begin(), v.end());
}

int main() {
    size_t n = 0;
    std::cin >> n;

    //std::cout << "constructing vector of size " << n << '\n';
    std::vector<int> v;
    v.reserve(n);

    for (size_t i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;

        //std::cout << "pushing back " << x << '\n';
        v.push_back(x);
    }

    std::cout << "size: " << v.size() << '\n';
    merge_sort(v);

    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
