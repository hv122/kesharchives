#include <iostream>
#include <memory>

std::shared_ptr<int> data()
{
    auto a = std::make_shared<int>(5);
    return a;
}






int main(){

    std::shared_ptr<int> a;

    a = data();
    auto b = a;

    auto c = std::move(a); // move destroys the pointer a to the object, and makes a new one c

    // std::cout << *a << std::endl; causes a seg fault as it has been destroyed
    std::cout << *b << std::endl;
    std::cout << *c << std::endl;
}