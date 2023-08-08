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


void Map::Load()  // above is the lookup table for the corresponding tile to the index values
{
	if (tileSheetTexture.loadFromFile("Assets/Map/tilesheet.png"))
	{
		totalTilesX = tileSheetTexture.getSize().x / tileWidth;
		totalTilesY = tileSheetTexture.getSize().y / tileHeight;

		tiles = new Tile[totalTilesX * totalTilesY];
		// create array in the heap by declaring tiles as a pointer, that points to new array
		std::cout << "Loaded tilesheet\n";

		for (size_t y = 0; y < totalTilesY; y++)
		{

			for (size_t x = 0; x < totalTilesX; x++)
			{
				int i = x + y * totalTilesX;

				tiles[i].id = i;
				tiles[i].position = sf::Vector2i(x * tileWidth, y * tileHeight);
			}
		}
	}
	else
	{
		std::cout << "Tilesheet failed to load\n";
	}


	for (int y = 0; y < 2; y++) // actual map is drawn on the screen, using the lookup table
	{

		for (int x = 0; x < 3; x++)
		{
			int i = x + y * 3;
			int index = mapNumbers[i];

			mapSprites[i].setTexture(tileSheetTexture);

			mapSprites[i].setTextureRect(sf::IntRect(
				tiles[index].position.x,
				tiles[index].position.y,
				tileWidth,
				tileHeight));

			mapSprites[i].setScale(sf::Vector2f(5, 5));
			mapSprites[i].setPosition(sf::Vector2f(x * 16 * 5, 100 + y * 16 * 5));
		}

	}
}





void Map::Update(double deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 6; i++)
		window.draw(mapSprites[i]);

}
