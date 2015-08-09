#include <iostream>

using namespace std;

class Animal {
 public:
  void eat();
};

class Mammal : public Animal {
 public:
  void eat();
};

class WingedAnimal : public Animal {
};

void Animal::eat()
{
  cout << "Animal eat()\n";
}

void Mammal::eat()
{
  cout << "Mammal eat()\n";
}


int main()
{
  WingedAnimal wa;
  wa.eat();

  Mammal m;
  m.eat();
}
