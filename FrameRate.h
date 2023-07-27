#pragma once
#include <SFML/Graphics.hpp>

class FrameRate
{

public:
	FrameRate();
	~FrameRate();
	void Initialize();
	void Load();
	void Update(double DeltaTime);
	void Draw(sf::RenderWindow& window);




private:
	sf::Text frameRateText;
	sf::Font font; // textures

	float timer; //
};

