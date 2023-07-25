#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "State.h"

enum Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	NONE,
};

class Character : public GameObject {
protected:
	int health;
	float angle = 0;
	Direction direction;

	Animation* idle_animation;
	Animation* run_animation;
	Animation* attack_animation;
public:
	virtual void checkCollision(std::vector<Object> objects);
	virtual void takeDamage(int damage);

	int getHP();
	float getAngle();
	Direction getDirection();

	void setDirection(Direction direction);
	void setAngle(float angle);
};

