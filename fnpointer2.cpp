#include <iostream>
#include <vector>

void PrintValue(int value)
{
    std::cout << "Value: " << std::endl;
}


void ForEach(const std::vector <int>& values, void(*func)(int))
{
    for(int value : values)
        func(value);
}



int main(){
    std::vector <int> values = {1, 5, 4, 2, 3};

    ForEach(values, PrintValue); // PrintValue without parentheses is a pointer to the function

    // For such a simple function such as PrintValue, we can use a lambda function!


}