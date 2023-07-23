#include "Bullet.h"
#include "Math.h"

Bullet::Bullet() :
	speed(0)
{

}

void Bullet::Initialize(const sf::Vector2f& position,const sf::Vector2f& target, float speed)
{
	this->speed = speed; 
	// this means the "speed of the bullet" allowing the speed to be used in other member fns of the class
	rectangleShape.setSize(sf::Vector2f(10.0f, 5.0f));
	rectangleShape.setPosition(position);
	direction = Math::NormalizeVector(target - position); 
	// only once per instance of bullet
}

void Bullet::Update(float deltaTime)
{
	rectangleShape.setPosition(rectangleShape.getPosition() + direction * speed * deltaTime); // as seen here
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(rectangleShape);
}
