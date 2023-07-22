#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h> // angled brackets denote that the file exists on my computer
#include "player.h" // double quotes denote that this file exists in my project
// we include player.h as it reduces the size of the exe, it doesn't need to be executed or compiled

sf::Vector2f NormalizeVector(sf::Vector2f vector) {
	float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	sf::Vector2f normalizedVector;
	
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

	int main() 
	
	{

		// ------------------------------- INITIALIZE -----------------------------------------
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;

		sf::RenderWindow window(sf::VideoMode(1600, 900), "RPG Game", sf::Style::Default, settings);
		sf::RectangleShape rect(sf::Vector2f(50, 100));
		rect.setFillColor(sf::Color::Blue);
		rect.setPosition(sf::Vector2f(1300, 700));

		std::vector<sf::CircleShape> bullets;

		float bulletSpeed = 0.3f;
		
		Player myPlayer;
		// ------------------------------- LOAD -----------------------------------------

		sf::Texture playerTexture;
		sf::Sprite playerCharacter;
		
		// main game loop
		while(window.isOpen()) // game loop is used to update and draw the game every frame
		{	
			// ------------------------------- UPDATE -----------------------------------------
			sf::Event event; // declaring an event
			while (window.pollEvent(event)) // event loop detects player activity on inputs
			{
				if (event.type == sf::Event::Closed) 
				{
					std::cout << "hello\n";
					window.close();
				}

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
			{
				auto position = rect.getPosition();
				rect.setPosition(position + sf::Vector2f(0.1, 0));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
			{
				auto position = rect.getPosition();
				rect.setPosition(position + sf::Vector2f(-0.1, 0));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
			{
				auto position = rect.getPosition();
				rect.setPosition(position + sf::Vector2f(0, 0.1));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
			{
				auto position = rect.getPosition();
				rect.setPosition(position + sf::Vector2f(0, -0.1));
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) 
			{
				bullets.push_back(sf::CircleShape(10.0f));

				int i = bullets.size() - 1;
				bullets[i].setPosition(playerCharacter.getPosition());
			}

			for (size_t i = 0; i < bullets.size(); i++) 
			{
				sf::Vector2f bulletDirection = rect.getPosition() - bullets[i].getPosition();
				bulletDirection = NormalizeVector(bulletDirection);
				bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
			}

			// -------------------------------  DRAW -------------------------------------------
			window.clear();
			// here is where we draw to the back buffer -- between clear and display
			window.draw(rect);
			
			for (size_t i = 0; i < bullets.size(); i++) 
			{
				window.draw(bullets[i]);
			}


			window.display(); // copies from back buffer to screen

		}

		return 0;
	} 