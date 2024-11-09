#include <iostream>
#include <memory_resource>
#include "include/stack.hpp"
#include "include/static-resource.hpp"

#include "map"

int main () {
    StaticResource<1024> resource;
    StackAllocator<int> allocator(&resource);

    Stack<int> stack(allocator);

    stack.push(0);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    while (!stack.empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }

    return 0;
}
