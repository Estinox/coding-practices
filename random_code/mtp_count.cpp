#include <array>
#include <iostream>
#include <typeinfo>

// int... container
template <int... Vals> struct Ints {};

// Rotate
template <typename T> struct Rotate;
template <int One, int... Two> struct Rotate<Ints<One, Two...>> {
  using type = Ints<Two..., One>;
};

template <typename Ints> struct MakeArray;

template <int... Vals> struct MakeArray<Ints<Vals...>> {
  static std::array<int, sizeof...(Vals)> arr;
};

// Sum
template <typename T> struct SumHelper;
template <int One, int... Rest> struct SumHelper<Ints<One, Rest...>> {
  // using type = Ints<One>;
  static const size_t value = One + SumHelper<Ints<Rest...>>::value;
};
template <> struct SumHelper<Ints<>> { static const size_t value = 0; };

template <int... Vals> struct Sum : public SumHelper<Ints<Vals...>> {};

// static member of the class template
template <int... Vals>
std::array<int, sizeof...(Vals)> MakeArray<Ints<Vals...>>::arr = {{Vals...}};

template <int... Vals>
struct RotateArray : public MakeArray<typename Rotate<Ints<Vals...>>::type> {};

int main() {
  using type = RotateArray<1, 2, 3, 4, 5>;
  for (auto const &v : type::arr)
    std::cout << v << std::endl;
  std::cout << std::endl;

  using SumMtp = Sum<2, 5, 3>;
  std::cout << "Sum::value " << SumMtp::value;
}
