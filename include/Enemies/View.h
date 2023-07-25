#pragma once

#include <SFML/Graphics.hpp>

#include "../Engine/MapObject.h"
#include "../Engine/Character.h"

const static int ACCURACY = 32;

class View {
private:
	sf::RectangleShape sticks[ACCURACY];
	float range;
	float max_range;
public:
	View(float range, float max_range);

	void Update(float x, float y, std::vector<Object>& objects);

	bool isIntersects(Character* player);

	sf::RectangleShape* getSticks();
};