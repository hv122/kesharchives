#pragma once
#include <SFML/Graphics.hpp>

class skeleton
{
private:
	sf::Texture texture;	// these need to be here, because they need to stay in scope after
	// they are initialised, not just for the duration of that fn

public: // public variable
	sf::Sprite sprite;

public:


	void Initialize();
	void Load();
	void Update();
	void Draw(sf::RenderWindow& window);


	void Shoot();
	void playerHP();

};