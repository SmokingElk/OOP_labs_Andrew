#include <iostream>
#include <memory_resource>
#include <string>
#include "include/stack.hpp"
#include "include/static-resource.hpp"

#include "map"

struct Complex {
    int x;
    std::string str;

    Complex () : x{0}, str{""} {}
    Complex (int xVal, std::string strVal) : x{xVal}, str{strVal} {}
};

int main () {
    StaticResource<1024, false> resource;

    StackAllocator<int> allocator(&resource);
    Stack<int> stack(allocator);

    StackAllocator<Complex> allocator2(&resource);
    Stack<Complex> stack2(allocator);

    stack.push(0);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack2.push(Complex(1, "abobus"));
    stack2.push(Complex(2, "kek"));
    stack2.push(Complex(3, "lol"));

    while (!stack.empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }

    for (auto it = stack2.begin(); it != stack2.end(); ++it) {
        std::cout << it->x << " " << it->str << std::endl;
    }

    return 0;
}
