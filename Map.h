#pragma once
#include <SFML\Graphics.hpp>

class Map

{
public:
	Map();
	~Map();


	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	sf::Texture tileSheetTexture;
	sf::Sprite sprites [10];

	int tileWidth;
	int tileHeight;

	int totalTilesX;
	int totalTilesY;
};

