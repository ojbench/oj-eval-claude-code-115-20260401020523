#include <iostream>
#include "src.hpp"

struct TestObj {
    int value;
    TestObj(int v) : value(v) {
        std::cout << "Constructed: " << value << std::endl;
    }
    ~TestObj() {
        std::cout << "Destructed: " << value << std::endl;
    }
};

int main() {
    std::cout << "=== Test 1: Basic construction ===" << std::endl;
    {
        sjtu::unique_ptr<int> p1;
        sjtu::unique_ptr<int> p2(new int(42));
        std::cout << "p1 is " << (p1 ? "not null" : "null") << std::endl;
        std::cout << "p2 is " << (p2 ? "not null" : "null") << std::endl;
        if (p2) {
            std::cout << "*p2 = " << *p2 << std::endl;
        }
    }

    std::cout << "\n=== Test 2: Move construction ===" << std::endl;
    {
        sjtu::unique_ptr<int> p1(new int(100));
        sjtu::unique_ptr<int> p2(std::move(p1));
        std::cout << "p1 is " << (p1 ? "not null" : "null") << std::endl;
        std::cout << "p2 is " << (p2 ? "not null" : "null") << std::endl;
        if (p2) {
            std::cout << "*p2 = " << *p2 << std::endl;
        }
    }

    std::cout << "\n=== Test 3: Move assignment ===" << std::endl;
    {
        sjtu::unique_ptr<int> p1(new int(200));
        sjtu::unique_ptr<int> p2(new int(300));
        p2 = std::move(p1);
        std::cout << "p1 is " << (p1 ? "not null" : "null") << std::endl;
        std::cout << "p2 is " << (p2 ? "not null" : "null") << std::endl;
        if (p2) {
            std::cout << "*p2 = " << *p2 << std::endl;
        }
    }

    std::cout << "\n=== Test 4: reset() ===" << std::endl;
    {
        sjtu::unique_ptr<int> p1(new int(400));
        p1.reset();
        std::cout << "p1 is " << (p1 ? "not null" : "null") << std::endl;
    }

    std::cout << "\n=== Test 5: reset(ptr) ===" << std::endl;
    {
        sjtu::unique_ptr<int> p1(new int(500));
        p1.reset(new int(600));
        if (p1) {
            std::cout << "*p1 = " << *p1 << std::endl;
        }
    }

    std::cout << "\n=== Test 6: release() ===" << std::endl;
    {
        sjtu::unique_ptr<int> p1(new int(700));
        int* raw = p1.release();
        std::cout << "p1 is " << (p1 ? "not null" : "null") << std::endl;
        std::cout << "*raw = " << *raw << std::endl;
        delete raw;
    }

    std::cout << "\n=== Test 7: make_unique ===" << std::endl;
    {
        auto p1 = sjtu::make_unique<int>(800);
        if (p1) {
            std::cout << "*p1 = " << *p1 << std::endl;
        }
    }

    std::cout << "\n=== Test 8: swap ===" << std::endl;
    {
        sjtu::unique_ptr<int> p1(new int(900));
        sjtu::unique_ptr<int> p2(new int(1000));
        p1.swap(p2);
        if (p1) {
            std::cout << "*p1 = " << *p1 << std::endl;
        }
        if (p2) {
            std::cout << "*p2 = " << *p2 << std::endl;
        }
    }

    std::cout << "\n=== Test 9: Object with destructor ===" << std::endl;
    {
        auto p = sjtu::make_unique<TestObj>(42);
        std::cout << "p->value = " << p->value << std::endl;
    }

    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}
