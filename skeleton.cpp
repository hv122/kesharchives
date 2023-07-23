#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() :
	health(100)
{
}


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
		sprite.setPosition(sf::Vector2f(500, 500));
		healthText.setString(std::to_string(health));


		int XIndex = 0;
		int YIndex = 2;
		
		sprite.scale(sf::Vector2f(2, 2));

		boundingRectangle.setSize(
			sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y)
		);

		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));

	}
	else
	{
		std::cout << "Skeleton texture failed to load\n";
	}

	if (font.loadFromFile("Assets/Fonts/Consolas.ttf"))
	{
		std::cout << "Font assets loaded successfully\n";
		healthText.setFont(font);
	}
	else
	{
		std::cout << "Failed to load font assets successfully\n";
	}
} 

void Skeleton::Update(float deltaTime)
{
	if (health > 0) {
		boundingRectangle.setPosition(sprite.getPosition());
		healthText.setPosition(sprite.getPosition());
	}

}

void Skeleton::Draw(sf::RenderWindow& window)
{
	if (health > 0) {
		window.draw(sprite);
		window.draw(boundingRectangle);
		window.draw(healthText);
	}
}

void Skeleton::changeHealth(int hp)
{
	health += hp;
	healthText.setString(std::to_string(health));
}
