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

void worker(int id)
{
  std::cout << "worker handling id " << id << std::endl;
}


int main() {
  auto signal = Signal<int>();

  Worker w{1};

  signal.subscribe(&worker);
  signal.notify(5);
  signal.notify(8);
}
