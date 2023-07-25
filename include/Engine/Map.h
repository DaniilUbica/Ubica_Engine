#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

#include "Globals.h"
#include "MapObject.h"

class Map {
private:
	std::vector<Object> objects;
	std::map<char, sf::Texture> tiles_textures;
	std::map<char, sf::Vector2i> tiles_textures_coords;
	std::map<char, Type> tiles_types;
	int map_index = 1;
	int prev_map = 1;

	std::string maps[MAPS_AMOUNT][MAP_WIDTH] = {
		// declare all maps here
	};

	void fillMap();
	void fillObjects();
	void fillTexturesCoords();
	void fillObjectTypes();
public:
	void changeMap();
	void setMap(sf::Texture& range_enemy_texture, sf::Texture& melee_enemy_texture);
	void drawMap(sf::RenderWindow& window);

	std::vector<Object> getObjects();
	int getIndex();
};

