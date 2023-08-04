#include <iostream>

void HelloWorld(int a)
{
    std::cout << "hello world Value: "<< a << std::endl;
}

int main()

{ 
    typedef void(*HelloWorldFunction)(int);

    HelloWorldFunction function = HelloWorld; // removing the parentheses, no longer calls the function, rather takes in the pointer to the function

    function(8); // now this calls the function pointed to

    // void(*function)(); this is what is used instead of auto
    std::cin.get();
}