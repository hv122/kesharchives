#include <iostream>

int *getData()
{
    auto a = 5;
    return &a;
} // the stack made in getData() isn't valid in main, as it goes out of scope
  // so we should use smart pointers as an alternative.

int main()
{
    int *b = getData();
    std::cout << *b << std::endl;
    return 0;
}
