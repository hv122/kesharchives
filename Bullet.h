#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet();


	void Initialize(const sf::Vector2f& position,const sf::Vector2f& target, float speed);
	// position is passed by ref (origin at player), target is normalized towards cursor
	// const means that nothing inside the initialize function will be allowed to change player position,
	// or the position selected by the cursor initally
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	inline const sf::FloatRect& GetGlobalBounds() { return rectangleShape.getGlobalBounds(); }
	// this function serves to keep the shape and size of the bullets private, whilst allowing
	// for collision calculations using getGlobalBounds
	// the inline keyword prevents the compiler from calling a function, saving performance
	// use inline for super short functions with returns
	 
private:
	sf::RectangleShape rectangleShape; 
	sf::Vector2f direction; // properties of the bullet
	float speed;
};

