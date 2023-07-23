#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() : 
	timer(0) // when setting a variable in a constructor, use list initialisation
{

}

FrameRate::~FrameRate()
{
}

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
	if (font.loadFromFile("Assets/Fonts/Consolas.ttf"))
	{
		std::cout << "Font assets loaded successfully\n";
		frameRateText.setFont(font);
	}
	else
	{
		std::cout << "Failed to load font assets successfully\n";
	}
}

void FrameRate::Update(float deltaTime) // update this once a second for readability
{	
	timer += deltaTime;

	if (timer >= 100.0f) 
	{
		float fps = 1000.0f / deltaTime;
		frameRateText.setString("FPS: " + std::to_string((int)fps) + " Frametime: " + std::to_string((int)deltaTime));
		timer = 0;
	}

}

void FrameRate::Draw(sf::RenderWindow& window)
{
	window.draw(frameRateText);
}
