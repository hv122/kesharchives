#include <iostream>
#include <memory>
#include <cstdlib>

std::shared_ptr<int> getData()
{
    auto a = std::make_shared<int>(5);
    return a;
}

int main()
{
    auto b = getData();
    std::weak_ptr weak = b;

    auto shared = weak.lock(); // this creates a shared pointer from it, then checks the shared pointer]
    if (shared)
    {
        std::cout << *shared << std::endl;
    }

    return 0;
}

// weak pointers are similar to shared pointers, but they are not managers/owners, so when referencing
// that area of memory you can't be sure that, that area is still valid.