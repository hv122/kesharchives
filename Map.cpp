#include "Map.h"
#include <iostream>

Map::Map() :
	tileWidth(16), 
	tileHeight(16),
	totalTilesX(0), 
	totalTilesY(0)
{

}

Map::~Map()
{
}

void Map::Initialize()
{
}

void Map::Load()
{
	if (tileSheetTexture.loadFromFile("Assets/Map/tilesheet.png")) 
	{

		totalTilesX = tileSheetTexture.getSize().x / tileWidth;
		totalTilesY = tileSheetTexture.getSize().y / tileHeight;
		std::cout << "Loaded tilesheet\n";

		for (size_t i = 0; i < 10; i++)
		{
			sprites[i].setTexture(tileSheetTexture);
			sprites[i].setTextureRect(sf::IntRect(i * tileWidth, 0 * tileHeight, tileWidth, tileHeight));
			sprites[i].setScale(sf::Vector2f(5, 5));
			sprites[i].setPosition(sf::Vector2f(100 + i * tileWidth * 5, 100));
		}
	}
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 10; i++)
		window.draw(sprites[i]);

}
