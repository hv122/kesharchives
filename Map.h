#pragma once
#include <SFML\Graphics.hpp>
#include "Tile.h"

class Map

{
public:
	Map();
	~Map();

	void Initialize();
	void Load();
	void Update(double deltaTime);
	void Draw(sf::RenderWindow& window); 

private:
	sf::Texture tileSheetTexture;
	Tile* tiles;

	int tileWidth;
	int tileHeight;

	int totalTilesX;
	int totalTilesY;

	int mapNumbers[6] = { // stores index numbers of tiles
		7, 8, 9,
		7, 8, 9
	};

	sf::Sprite mapSprites[6]; // this is what stores the sprites to be drawn

};

