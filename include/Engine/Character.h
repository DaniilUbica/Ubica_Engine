#pragma once

#include <SFML/Graphics.hpp>
#include <queue>

#include "GameObject.h"
#include "State.h"
#include "../UI/HealthBar.h"
#include "../Townhall.h"

enum UnitType {
	MELEE,
	RANGE,
	SUPPORT,
	TANK,
	TOWER,
	UPGRADE,
	NO_TYPE,
};

class Character : public GameObject {
protected:
	int damage;
	bool from_left;
	bool is_active = true;
	bool is_dead = false;
	int health;
	HealthBar* healthbar;
	State state;
	UnitType type;

	Animation* idle_animation;
	Animation* run_animation;
	Animation* attack_animation;
	Animation* death_animation;
public:
	virtual void takeDamage(int damage);
	virtual void Attack(Character* enemy);
	virtual void Attack(Townhall* th);
	void playDeathAnimation(float time);

	int getHP();
	bool getFromLeft();
	HealthBar getHealthbar();
	bool getActive();
	bool getDead();
	UnitType getType();

	inline bool operator==(const Character& rhs) {
		return this->getPosition().x == rhs.getPosition().x;
	}
};