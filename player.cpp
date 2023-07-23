#include "player.h" // this is used so that the cpp recognises the class names
#include <iostream> // this only needs to be here, as there are no std namespace items in the header file
#include "Math.h"


Player::Player() :
	playerSpeed(0.2f), maxFireRate(250), fireRateTimer(0)
{
}

void Player::Initialize()
{
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineThickness(1.0f);

	size = sf::Vector2i(64, 64);
}

void Player::Load()
{
	if(texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
	{
		std::cout << "Player texture loaded!\n";
		sprite.setTexture(texture);

		auto XIndex = 0;
		auto YIndex = 0;

	sprite.scale(sf::Vector2f(1, 1));

	boundingRectangle.setSize(
		sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y)
	);

		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.setPosition(sf::Vector2f(0, 0));
	}
	else
	{
		std::cout << "Player texture failed to load!\n";
	}
}

void Player::Update(float deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition) 
{
	auto position = sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		sprite.setPosition(position + sf::Vector2f(1, 0) * playerSpeed * deltaTime);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		sprite.setPosition(position + sf::Vector2f(-1, 0) * playerSpeed * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		sprite.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * deltaTime);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		sprite.setPosition(position + sf::Vector2f(0, -1) * playerSpeed * deltaTime);

	//------------- BULLET -------------------------

	fireRateTimer += deltaTime;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate)
	{
		bullets.push_back(Bullet());

		int i = bullets.size() - 1;
		bullets[i].Initialize(sprite.getPosition(), mousePosition, 0.5f);
		fireRateTimer = 0;
	}

	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].Update(deltaTime);

		if (skeleton.health > 0)
		{
			if(Math::DidRectCollide(bullets[i].GetGlobalBounds(), skeleton.sprite.getGlobalBounds()))
			{
				skeleton.changeHealth(-10);
				bullets.erase(bullets.begin() + i);
			}
		}
	}
	boundingRectangle.setPosition(sprite.getPosition());
}

// ----------------------------------------------------

void Player::Draw(sf::RenderWindow& window) // needs to have the same class "Player" otherwise it doesn't refer to our header file
{
	window.draw(sprite);// the cpp denotes what the functions actually does
	window.draw(boundingRectangle);

	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].Draw(window);
	}
}