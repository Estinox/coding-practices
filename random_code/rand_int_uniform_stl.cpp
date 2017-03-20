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

class RandomGen {
public:
  RandomGen(std::vector<long> &random_nums,
            std::vector<long double> &probabilities)
      : generator_(),
        distribution_(probabilities.cbegin(), probabilities.cend()),
        random_nums_(std::move(random_nums)) {}

  auto next_num() { return random_nums_[distribution_(generator_)]; }

private:
  std::default_random_engine generator_;
  std::discrete_distribution<long> distribution_;
  std::vector<long> random_nums_;
};

// driver program
int main() {
  // number of random number and probability pairs and trials
  int N, trials;
  std::cin >> trials >> N;

  // return if no probability pairs are given
  if (N <= 0) {
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
    std::cout << kvp.first << ": " << kvp.second << " times\n";
  }

  // force flush at the end just in case, more efficient than flushing everytime
  // with std::endl
  std::cout << std::flush;
  return 0;
}
