#include "../include/Engine/Map.h"

void Map::fillMap() {
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (!tiles_textures.count(maps[map_index][i][j])) {
				sf::Texture tile_texture;
				tile_texture.loadFromFile("assets/Tiles.png", sf::IntRect(tiles_textures_coords[maps[map_index][i][j]].x, tiles_textures_coords[maps[map_index][i][j]].y, TILE_SIZE, TILE_SIZE));
				tile_texture.setRepeated(true);
				std::pair<char, sf::Texture> elem = { maps[map_index][i][j], tile_texture };
				tiles_textures.insert(elem);
			}
			else {
				continue;
			}	
		}
	}
}

void Map::fillObjects() {
	for (int i = 0; i < MAP_HEIGHT; i++) {
		int count = 0;
		int startX = 0;
		int startY = i;
		for (int j = 0; j < MAP_WIDTH; j++) {
			char next = maps[map_index][i][j + 1];
			if (maps[map_index][i][j] != next || next == '\0') {
				count++;

				sf::RectangleShape r;
				r.setPosition(startX * TILE_SIZE, startY * TILE_SIZE);
				r.setSize(sf::Vector2f(count * TILE_SIZE, 1 * TILE_SIZE ));
				r.setTexture(&tiles_textures[maps[map_index][i][j]]);
				r.setTextureRect(sf::IntRect(0, 0, count * TILE_SIZE, TILE_SIZE));

				Object obj = { tiles_types[maps[map_index][i][j]], maps[map_index][i][j], r};
				objects.push_back(obj);

				startX = j + 1;
				count = 0;
			}
			else {
				count++;
			}
		}
	}
}

void Map::fillTexturesCoords() {
	sf::Vector2i coords;
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			// Take coordinates from "Tiles.png"
			switch (maps[map_index][i][j]) {
			case 'F':
				coords = { 2 * TILE_SIZE, 0 * TILE_SIZE };
				break;
			case 'L':
				coords = { 0 * TILE_SIZE, 6 * TILE_SIZE };
				break;
			case 'R':
				coords = { 2 * TILE_SIZE, 6 * TILE_SIZE };
				break;
			case 'S':
				coords = { 4 * TILE_SIZE, 0 * TILE_SIZE };
				break;
			case 'T':
				coords = { 1 * TILE_SIZE, 2 * TILE_SIZE };
				break;
			case 'W':
				coords = { 0 * TILE_SIZE, 3 * TILE_SIZE };
				break;
			case ' ':
				coords = { 0 * TILE_SIZE, 1 * TILE_SIZE };
				break;
			}
			tiles_textures_coords.insert(std::make_pair(maps[map_index][i][j], coords));
		}
	}
}

void Map::fillObjectTypes() {
	Type type;
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			switch (maps[map_index][i][j]) {
			case 'F':
				type = SOLID;
				break;
			case 'L':
				type = SOLID;
				break;
			case 'R':
				type = SOLID;
				break;
			case 'S':
				type = SOLID;
				break;
			case 'T':
				type = TRAP;
				break;
			case 'W':
				type = SOLID;
				break;
			case ' ':
				type = SPRITE;
				break;
			}
			tiles_types.insert(std::make_pair(maps[map_index][i][j], type));
		}
	}
}

void Map::changeMap() {
	srand(time(NULL));
	while (map_index == prev_map) {
		map_index = rand() % (MAPS_AMOUNT-1) + 1;
	}
	prev_map = map_index;
}

void Map::setMap(sf::Texture& range_enemy_texture, sf::Texture& melee_enemy_texture) {

	objects.clear();
	tiles_textures.clear();
	tiles_textures_coords.clear();
	tiles_types.clear();

	fillTexturesCoords();
	fillObjectTypes();
	fillMap();
	fillObjects();
}

void Map::drawMap(sf::RenderWindow& window) {
	for (Object obj : objects) {
		window.draw(obj.r);
	}
}

std::vector<Object> Map::getObjects() {
	return objects;
}

int Map::getIndex() {
	return map_index;
}
