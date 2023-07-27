#pragma once
#include <SFML\Graphics.hpp>

struct Tile // structs are the same as a class, however in a struct the default access is public
{	
	int id = -1; 
	// there is actually an id of 0, so if you forget to initialise, they will all point to -1 instead
	sf::Vector2i position;
	// use two variables instead of four like with rect
};

// structs are all values, no functions

