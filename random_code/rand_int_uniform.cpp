// this macro can be toggled between true and false for verbose debugging
#ifndef _DEBUG
#define _DEBUG false
#endif

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

// event and its probability pairs; can be adapted for diff types
template <typename Event, typename Prob> struct Density {
  Event event;
  Prob prob;

  // lvalue reference constructor
  Density(Event const &e, Prob const &p) : event(e), prob(p){};

  // forwarding reference constructor
  Density(Event &&e, Prob &&p)
      : event(std::forward<Event>(e)), prob(std::forward<Prob>(p)){};

  // how to print this struct
  template <typename E, typename P>
  friend std::ostream &operator<<(std::ostream &out,
                                  Density<E, P> const &density);
};

template <typename E, typename P>
std::ostream &operator<<(std::ostream &out, Density<E, P> const &density) {
  out << "event=" << density.event << ", prob=" << density.prob << std::flush;
  return out;
};

// typedef template alias of Density<long, long double> for this excercise
using IntegerDensity = Density<long, long double>;

// probability density generator class
class RandomGen {
public:
  // ctors
  RandomGen(std::vector<long> &random_nums,
            std::vector<long double> &probabilities);

  // force all constructions to be defined
  RandomGen() = delete;

  // member functions
  long next_num();
  void seed(unsigned s) { generator_.seed(s); };

  // returns pdf(X=event)
  long double pdf(long event) const;

  // operators
  friend std::ostream &operator<<(std::ostream &out, RandomGen const &rg);

private:
  // track the pdf and cdf of the input
  // we could also write a function that converts between pdf and cdf
  // this can be an implemenation trade off between space and speed
  std::vector<IntegerDensity> pdf_;
  std::vector<IntegerDensity> cdf_;

  // generator and uniform real dist
  std::default_random_engine generator_;
  std::uniform_real_distribution<long double> distribution_;
};

RandomGen::RandomGen(std::vector<long> &random_nums,
                     std::vector<long double> &probabilities)
    : generator_(), distribution_(0.0L, 1.0L) {
  // assumes length of two vectors are equal,
  pdf_.reserve(random_nums.size());
  for (std::size_t i = 0; i < random_nums.size(); ++i) {
    pdf_.emplace_back(std::move(random_nums[i]), std::move(probabilities[i]));
  }

  // sort pdf in descending order of IntegerDensity::prob
  // because higher prob has greater chance of being drawn, and when we search
  // thru our pdf and cdf sequentially, we want the search to return
  // true as early as possible.
  std::sort(pdf_.begin(), pdf_.end(),
            [](auto const &a, auto const &b) { return a.prob > b.prob; });

  // construct cdf from sorted pdf
  cdf_.reserve(pdf_.size());
  std::for_each(pdf_.cbegin(), pdf_.cend(),
                [&, cum = 0. ](auto const &v) mutable {
                  cum += v.prob;
                  cdf_.emplace_back(v.event, cum);
                });
}

long RandomGen::next_num() {
  // idea here is to generate a real number between [0, 1) uniformly,
  // then take that number and map it to the highest CDF of the
  // corresponding event
  auto num = distribution_(generator_);
  // lower bound finds the first element equal or greatr than our num
  auto event =
      std::lower_bound(cdf_.cbegin(), cdf_.cend(), num, [](auto const &cdf,
                                                           auto const &val) {
        return cdf.prob < val;
      })->event;

#if _DEBUG
  std::cout << "random_num=" << num << ", event=" << event << '\n';
#endif

  return event;
}

inline long double RandomGen::pdf(long event) const {
  return std::find_if(pdf_.cbegin(), pdf_.cend(),
                      [&](auto const &v) { return v.event == event; })
      ->prob;
}

std::ostream &operator<<(std::ostream &out, RandomGen const &rg) {
  out << "PDF in descending likelihood order:\n";
  std::for_each(rg.pdf_.cbegin(), rg.pdf_.cend(),
                [&](auto const &v) { out << v << '\n'; });

  out << "\nCDF in descending likelihood order:\n";
  std::for_each(rg.cdf_.cbegin(), rg.cdf_.cend(),
                [&](auto const &v) { out << v << '\n'; });

  out << std::flush;
  return out;
}

// driver program
int main() {
  // number of random number and probability pairs and trials
  long N, trials;
  std::cin >> trials >> N;

  // args check
  if (trials <= 0) {
    std::cout << "no trials to perform" << std::endl;
    return 0;
  }
  else if (N <= 0) {
    std::cout << "exiting with no probability pairs given" << std::endl;
    return 0;
  }

  // set up a contiguous vector container and preallocate N units of memory
  // so the container doesn't need to resize when items are pushed in
  std::vector<long> random_num;
  std::vector<long double> probabilities;
  random_num.reserve(N);
  probabilities.reserve(N);

  // copy input into vector
  std::copy_n(std::istream_iterator<long>(std::cin), N,
              std::back_inserter(random_num));
  std::copy_n(std::istream_iterator<long double>(std::cin), N,
              std::back_inserter(probabilities));

  // error checking
  auto total_prob =
      std::accumulate(probabilities.cbegin(), probabilities.cend(), 0.0L);
  if (std::fabs(total_prob - 1.0L) >
      std::numeric_limits<long double>::epsilon() * 5) {
    throw std::invalid_argument("total_probability equals to " +
                                std::to_string(total_prob));
  }

  // driver program
  RandomGen random_gen{random_num, probabilities};

#if _DEBUG
  // Print out the probability pdf and cdf
  std::cout << random_gen << '\n';
#endif

  // Start drawing random numbers
  std::map<long, long> freq_table{};
  for (std::size_t i = 0; i < trials; ++i) {
    long event = random_gen.next_num();
    // increment count for every random number we see
    ++freq_table[event];
  }

  // Print out frequency table
  std::cout << "\nFrequency Table (trials=" << trials << "):" << '\n';
  for (auto const &kvp : freq_table) {
    std::cout << kvp.first << ": " << kvp.second << " times"
              << "; sample density="
              << kvp.second / static_cast<long double>(trials)
              << ", population density=" << random_gen.pdf(kvp.first) << '\n';
  }

  // force flush at the end just in case, more efficient than flushing everytime
  // with std::endl
  std::cout << std::flush;
  return 0;
}
