// Lambdas are used as a quick disposable function, more like a variable
// Anywhere you would set a function pointer to a function, we can set it to a lambda

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{
    for(int value : values)
        func(value);
}

int main()
{
    std::vector<int> values = {1, 5, 4, 3, 2};
    
    int a = 5;

    auto lambda = [a](int value) {std::cout << "Values: " << a << " " << value << std::endl;};
    ForEach(values, lambda); // this is the syntax for a lambda
    std::cin.get();
}

// [] -- these are the captures for the lambda, that are able to capture everything, certain things or nothing in the lambdas body, by capture or reference
// captures are used to include variables that are not in the scope of the lambda, e.g. a, is put into the []
// for this specific situation, we must use an std::function in the ForEach parameters