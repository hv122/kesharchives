#include "player.h" // double quotes denote that this file exists in my project
#include "skeleton.h"
#include <iostream>
// we include player.h as it reduces the size of the exe, it doesn't need to be executed or compiled


	int main() 
	
	{

		// ------------------------------- INITIALIZE -----------------------------------------
		sf::ContextSettings settings;
		settings.antialiasingLevel = 4;
		sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
		window.setFramerateLimit(60); // to stop jitter due to v small deltaTime


		
		Player myPlayer; // declaring using the library we created
		Skeleton skeleton;


		myPlayer.Initialize();
		skeleton.Initialize();

		myPlayer.Load();
		skeleton.Load();

		sf::Clock clock;

		// main game loop
		while(window.isOpen()) // game loop is used to update and draw the game every frame
		{	
			sf::Time deltaTimeTimer = clock.restart();
			float deltaTime = deltaTimeTimer.asMilliseconds();

			// ------------------------------- UPDATE -----------------------------------------
			sf::Event event; // declaring an event
			while (window.pollEvent(event)) // event loop detects player activity on inputs
			{
				if (event.type == sf::Event::Closed) 
				{
					window.close();
				}

			}

			skeleton.Update();
			myPlayer.Update(deltaTime, skeleton);


			// -------------------------------  DRAW -------------------------------------------
			window.clear(sf::Color::Black);
			// here is where we draw to the back buffer -- between clear and display
			myPlayer.Draw(window);
			skeleton.Draw(window);
			window.display(); // copies from back buffer to screen

		}

		return 0;
	} 