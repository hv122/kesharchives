#pragma once // this 
#include "Skeleton.h"
#include "Bullet.h"

class Player // the header file is used to tell source files that a certain class exists, the linker can use this information
{
public: // public variable
	sf::Sprite sprite;

public:

	Player();

	void Initialize();
	void Load();
	void Update(float deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);



private:
	

	sf::Texture texture;					// these need to be here, because they need to stay in scope after
	std::vector<Bullet> bullets;	// they are initialised, not just for the duration of that fn
	float playerSpeed;
	
	
	float  maxFireRate;
	float fireRateTimer;
	
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;



};