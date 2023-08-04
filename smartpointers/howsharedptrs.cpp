#include <iostream>
#include <memory> // needs to be included to be used

std::shared_ptr<int> getData()
{
    std::shared_ptr<int> a = std::make_shared<int>(5); // declared a shared pointer of type int on the lhs,
    return a;                                          // rhs assigns a location in memory to this pointer
} // containing int 5

int main()
{
    auto b = getData(); // auto can be used instead of the whole syntax
    auto c = b;         // as they are shared pointers, we can do this
    std::cout << *b << std::endl;
}

// memory that shared_ptrs point to only gets deleted once all pointers to it go out of scope