#include "skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
}

void Skeleton::Load()
{
	if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
	{
		std::cout << "Skeleton texture loaded!\n";
		sprite.setTexture(texture);

		int XIndex = 0;
		int YIndex = 2;

		sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		sprite.scale(sf::Vector2f(3, 3));
		sprite.setPosition(sf::Vector2f(500, 500));

	}
	else
	{
		std::cout << "Skeleton texture failed to load\n";
	}
} 

void Skeleton::Update()
{
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
