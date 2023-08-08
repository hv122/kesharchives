#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
public: // public variable
	sf::Sprite sprite;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;
	int health;

public:

	Skeleton();
	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void changeHealth(int hp);



private:
	sf::Texture texture;	// these need to be here, because they need to stay in scope after
	// they are initialised, not just for the duration of that fn

	sf::Text healthText;
	sf::Font font;
};