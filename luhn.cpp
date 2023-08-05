#include <iostream>
#include <string>
#include <cmath>

int getDigit (const int number)
{
    return number % 10 + (number / 10 % 10);
}

int sumOddDigits(const std::string cardNumber)
{
    int sum = 0;

    for (int i = 1; i < cardNumber.size(); i += 2)
    {
        sum += cardNumber[i] - '0';
    }

    return sum;
}

int sumEvenDigits(const std::string cardNumber)
{
    int sum = 0;

    for (int i = 0; i < cardNumber.size(); i += 2)
    {
        sum += getDigit((cardNumber[i] - '0') * 2);
    }

    return sum;
    
}

int main()
{
    std::string cardNumber;
    int result = 0;

    std::cout << "Enter your card number: \n";
    std::cin >> cardNumber;

    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    if(result % 10 == 0){
        std::cout << cardNumber << " is valid\n";
    } else {
        std::cout << cardNumber << " is not valid\n";
    }
}