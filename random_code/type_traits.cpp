#include <iostream>
#include <vector>
#include <deque>
#include <list>


struct vectorlike_tag {};
struct listlike_tag {};

template <typename C> struct container_traits;

template <typename T, typename A> struct container_traits<std::vector<T, A>> {
  using category = vectorlike_tag;
};

template <typename T, typename A>
struct container_traits<std::deque<T, A>> {
  using category = vectorlike_tag;
};

template <typename T, typename A>
struct container_traits<std::list<T, A>> {
  using category = listlike_tag;
};

template <typename C>
void who_helper (C const &c, vectorlike_tag) {
  std::cout << "vector like" << std::endl;
}

template <typename C>
void who_helper (C const &c, listlike_tag) {
  std::cout << "list like" << std::endl;
}

template <typename C> void who(C const &c) {
  who_helper(c, typename container_traits<C>::category());
}

int main() {
  std::vector<int> v;
  std::list<int> l;

  who(v);
  who(l);
}

/////////////////////////////////////////

// template <typename SubClass> class SubClass_traits {};
//
// template <typename Subclass> class A {
// public:
//  void action(typename SubClass_traits<Subclass>::mytype var) {
//    (static_cast<Subclass *>(this))->do_action(var);
//  }
//};
//
//// Definitions for B
// class B; // Forward declare
//
// template <> // Define traits for B. So other classes can use it.
// class SubClass_traits<B> {
// public:
//  typedef int mytype;
//};
//
//// Define B
// class B : public A<B> {
//  // Define mytype in terms of the traits type.
//  typedef SubClass_traits<B>::mytype mytype;
//
// public:
//  B() {}
//
//  void do_action(mytype var) {
//    // Do stuff
//  }
//};
//
// int main(int argc, char **argv) {
//  B myInstance;
//  return 0;
//}
