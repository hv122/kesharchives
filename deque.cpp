#include <iostream>
#include <deque>
#include <vector>

// deques (decks) are much like vectors, but allow for us to access either end of them, increasing efficiency

int main(){

    std::deque<std::string> foods4 = {"tacos", "honey", "apples", "pumpkin"};

    foods4.push_back("oranges");
    foods4.push_front("pizza");

    for (int i = 0; i < foods4.size(); i++)
    {
        std::cout << foods4[i] << std::endl;
    }
    

}