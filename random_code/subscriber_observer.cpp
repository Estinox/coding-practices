#include <vector>
#include <iostream>
#include <algorithm>

template <typename... Args> class Signal {
  public:
    using fp = void (*)(Args...);
    Signal() : subscribers_(){};

    void subscribe(void (*fp)(Args...)) {
      subscribers_.push_back(fp);
    }

    void notify(Args... args) {
      std::for_each(subscribers_.begin(), subscribers_.end(), [&](auto& func){func(args...);});
    }

  private:
    std::vector<fp> subscribers_;
};

void multiply(int a, int b)
{
  std::cout << a << " times " << b  << " is " << a*b << std::endl;
}

void subtract(int a, int b)
{
  std::cout << a << " minus " << b << " is " << a-b << std::endl;
}


int main() {
  auto signal = Signal<int, int>();

  signal.subscribe(&multiply);
  signal.subscribe(&subtract);
  signal.notify(3,1);
  signal.notify(8,2);
}
