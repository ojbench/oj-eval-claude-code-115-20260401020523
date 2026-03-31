#include <iostream>
#include "src.hpp"

int main() {
    std::cout << "=== Test self-reset ===" << std::endl;
    {
        sjtu::unique_ptr<int> p1(new int(42));
        int* raw = p1.get();
        std::cout << "Before reset: p1.get() = " << p1.get() << ", *p1 = " << *p1 << std::endl;
        p1.reset(raw);  // Self-reset
        std::cout << "After reset: p1.get() = " << p1.get() << ", *p1 = " << *p1 << std::endl;
    }
    std::cout << "Test completed without crash!" << std::endl;
    return 0;
}
