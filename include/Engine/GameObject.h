#pragma once

#include <SFML/Graphics.hpp>

#include "Animation.h"
#include "MapObject.h"
#include "../Sound/SoundManager.h"

class GameObject {
protected:
	float coordX, coordY, width, height;
	sf::Sprite sprite;
public:
	virtual void Update() = 0;

	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	sf::Vector2f getSize();

	void setPosition(int coordX, int coordY);
};

