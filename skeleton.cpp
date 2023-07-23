#include "skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
	boundingRectangle.setOutlineColor(sf::Color::Blue);
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineThickness(1.0f);

	size = sf::Vector2i(64, 64);
}

void Skeleton::Load()
{
	if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
	{
		std::cout << "Skeleton texture loaded!\n";
		sprite.setTexture(texture);

		int XIndex = 0;
		int YIndex = 2;
		
		sprite.scale(sf::Vector2f(1, 1));

		boundingRectangle.setSize(
			sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y)
		);

		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.setPosition(sf::Vector2f(500, 500));
	}
	else
	{
		std::cout << "Skeleton texture failed to load\n";
	}
} 

void Skeleton::Update()
{
	boundingRectangle.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);
}
