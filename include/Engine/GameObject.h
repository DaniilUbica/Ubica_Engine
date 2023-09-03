#pragma once

#include <SFML/Graphics.hpp>

#include "Animation.h"
#include "../Sound/SoundManager.h"

class GameObject {
protected:
	float coordX, coordY, width, height;
	sf::Sprite sprite;
public:
	sf::Sprite getSprite();
	sf::Vector2f getPosition() const;
	sf::Vector2f getSize();

	void setPosition(int coordX, int coordY);
};