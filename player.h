#pragma once // this 
#include "skeleton.h"

class Player // the header file is used to tell source files that a certain class exists, the linker can use this information
{
public: // public variable
	sf::Sprite sprite;

public:


	void Initialize();
	void Load();
	void Update(Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);


	void Shoot();
	void playerHP();


private:
	sf::Texture texture;					// these need to be here, because they need to stay in scope after
	std::vector<sf::CircleShape> bullets;	// they are initialised, not just for the duration of that fn
	float bulletSpeed = 0.5f;


};