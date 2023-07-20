#include <iostream>
#include <memory> // needs to be included to be used

std::shared_ptr<int> getData()
{
    std::shared_ptr<int> a = std::make_shared<int>(5); // declared a shared pointer of type int on the lhs,
    return a;                                          // rhs assigns a location in memory to this pointer
} // containing int 5

int main()
{
    std::shared_ptr<int> b = getData();
    std::cout << *b << std::endl;
}