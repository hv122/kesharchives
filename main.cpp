#include <vector>
#include <math.h> // angled brackets denote that the file exists on my computer
#include <iostream>

#include "player.h" // double quotes denote that this file exists in my project
#include "skeleton.h"
// we include player.h as it reduces the size of the exe, it doesn't need to be executed or compiled


	int main() 
	
	{

		// ------------------------------- INITIALIZE -----------------------------------------
		sf::ContextSettings settings;
		settings.antialiasingLevel = 4;

		sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);


		
		Player myPlayer; // declaring using the library we created
		skeleton skeleton;


		myPlayer.Initialize();
		skeleton.Initialize();

		myPlayer.Load();
		skeleton.Load();

		// main game loop
		while(window.isOpen()) // game loop is used to update and draw the game every frame
		{	
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
			myPlayer.Update(skeleton);


			// -------------------------------  DRAW -------------------------------------------
			window.clear(sf::Color::Black);
			// here is where we draw to the back buffer -- between clear and display

			myPlayer.Draw(window);
			skeleton.Draw(window);
			

			window.display(); // copies from back buffer to screen

		}

		return 0;
	} 