#include "player.h" // this is used so that the cpp recognises the class names
#include <iostream> // this only needs to be here, as there are no std namespace items in the header file
#include "Math.h"


Player::Player() :
	bulletSpeed(0.5f), playerSpeed(1.0f)
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

void Player::Update(float deltaTime, Skeleton& skeleton) 
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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		bullets.push_back(sf::CircleShape(10.0f));

		int i = bullets.size() - 1;
		bullets[i].setPosition(sprite.getPosition());
	}

	for (size_t i = 0; i < bullets.size(); i++) // the slower the frame rate, the slower the bullets
	{
		sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
		bulletDirection = Math::NormalizeVector(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime); // we want to use delta time
		// delta time keeps the speed of objects the same independent of framerate
	}
	
	boundingRectangle.setPosition(sprite.getPosition());

	if (Math::DidRectCollide(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds()))
	{
		std::cout << "Collision detected!\n";
	}

}

void Player::Draw(sf::RenderWindow& window) // needs to have the same class "Player" otherwise it doesn't refer to our header file
{
	window.draw(sprite);// the cpp denotes what the functions actually does
	window.draw(boundingRectangle);

	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}
}