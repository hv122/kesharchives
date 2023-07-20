#include <iostream>
#include <memory>

std::unique_ptr<int> getData()
{
    std::unique_ptr<int> a = std::make_unique<int>(5);
    return a;
}

int main()
{
    auto b = getData(); // auto can be used instead of the whole syntax
    auto c = b;         // this line will not compile when using unique pointers
    std::cout << *b << std::endl;
    std::cout << *c << std::endl;
}

// when using unique pointers, you can use auto c = std::move(b), although you can't copy pointers.