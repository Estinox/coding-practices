#include <iostream>
#include <vector>

struct PlusOne {
    void plus_one() { val += 1; }
    int val = 0;
};

struct PlusTwo {
    void plus_two() { val += 2; }
    int val = 0;
};

struct Delegate {
    void *fp;
    void *obj;
};

template <typename CallSignature> struct DelegateContainer;

template <typename... Args> struct DelegateContainer<void(Args...)> {
    using call_signature = void (*)(void * /*obj*/, Args...);

    template <typename T> void insert(void (T::*fp)(Args...), T *obj) {
        _delegates.push_back(Delegate{reinterpret_cast<void *>(fp),
                                      reinterpret_cast<void *>(obj)});
    }

    void call(Args &&... args) {
        for (auto &d : _delegates) {
            (reinterpret_cast<call_signature>(d.fp))(d.obj,
                                                     std::forward(args)...);
            // std::invoke(d.f
        }
    }

    std::vector<Delegate> _delegates;
};

int main() {
    auto delegate_container = DelegateContainer<void()>{};
    auto p1 = PlusOne();
    auto p2 = PlusTwo();

    delegate_container.insert(&PlusOne::plus_one, &p1);
    delegate_container.insert(&PlusTwo::plus_two, &p2);

    std::cout << "p1.val=" << p1.val << std::endl;
    std::cout << "p2.val=" << p2.val << std::endl;

    delegate_container.call();

    std::cout << "p1.val=" << p1.val << std::endl;
    std::cout << "p2.val=" << p2.val << std::endl;
}
