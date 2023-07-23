#pragma once
#include <SFML/Graphics.hpp> 

class Math
{
public:
	static sf::Vector2f NormalizeVector(sf::Vector2f vector);
	// the static keyword is used to call functions without making an object
	// a restriction with the static keyword is that you can only have one object of that class in main; 
	// eg you can only have one player  
};

