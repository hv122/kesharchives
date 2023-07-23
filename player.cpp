#include "player.h" // this is used so that the cpp recognises the class names
#include <iostream> // this only needs to be here, as there are no std namespace items in the header file
#include "Math.h"


void Player::Initialize()
{
}

void Player::Load()
{
	if(texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
	{
		std::cout << "Player texture loaded!\n";
		sprite.setTexture(texture);

		auto XIndex = 0;
		auto YIndex = 0;

		sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		sprite.scale(sf::Vector2f(3, 3));
		sprite.setPosition(sf::Vector2f(0, 0));
	}
	else
	{
		std::cout << "Player texture failed to load!\n";
	}
}

void Player::Update(Skeleton& skeleton)
{
	auto position = sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		sprite.setPosition(position + sf::Vector2f(1, 0));


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		sprite.setPosition(position + sf::Vector2f(-1, 0));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		sprite.setPosition(position + sf::Vector2f(0, 1));


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		sprite.setPosition(position + sf::Vector2f(0, -1));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		bullets.push_back(sf::CircleShape(10.0f));

		int i = bullets.size() - 1;
		bullets[i].setPosition(sprite.getPosition());
	}

	for (size_t i = 0; i < bullets.size(); i++)
	{
		sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
		bulletDirection = Math::NormalizeVector(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
	}
}

void Player::Draw(sf::RenderWindow& window) // needs to have the same class "Player" otherwise it doesn't refer to our header file
{
	window.draw(sprite);// the cpp denotes what the functions actually does

	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}
}