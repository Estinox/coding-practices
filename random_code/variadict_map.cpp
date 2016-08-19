#include <iostream>
#include <string>

template <class Type> class Slot {
protected:
  Type &doGet() // A nice encapsulation, that will be usefull later on.
  {
    return value_;
  }

  void doSet(const Type &value) // Same encapsulation.
  {
    value_ = value;
  }

private:
  Type value_;
};

template <class... Slots>
class Repository : private Slots... // inherit from our slots...
{
public:
  template <class Type> // Give me a type and,
  Type &get() {
    return Slot<Type>::doGet(); // I can select the Base class.
  }

  template <class Type> void set(const Type &value) {
    Slot<Type>::doSet(value);
  }
};

// Create a type for our repository.
using MyRepository = Repository<Slot<int>, // Let's pick the type of our slots.
                                Slot<std::string>>;

int main() {
  MyRepository myRepository;

  myRepository.set<std::string>("toto");
  myRepository.set(42); // Notice the type deduction: we pass an int, so it
                        // writes in the int slot.

  std::cout << myRepository.get<int>() << std::endl;         // Print: "toto".
  std::cout << myRepository.get<std::string>() << std::endl; // Print: 42.

  return EXIT_SUCCESS;
}
