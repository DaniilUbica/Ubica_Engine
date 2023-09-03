#include "../include/Engine/Character.h"

void Character::takeDamage(int damage) {
	health -= damage;
}

void Character::Attack(Character* enemy) {
	if (roundf(this->attack_animation->currentFrame) == this->attack_animation->frames.size()) {
		enemy->takeDamage(this->damage);
		this->attack_animation->currentFrame = 0.0;
	}
}

void Character::Attack(Townhall* th) {
	if (roundf(this->attack_animation->currentFrame) == this->attack_animation->frames.size()) {
		th->takeDamage(1);
		this->attack_animation->currentFrame = 0.0;
	}
}

void Character::playDeathAnimation(float time) {
	if (roundf(this->death_animation->currentFrame) != death_animation->frames.size()) {
		this->sprite = death_animation->Tick(time, !from_left);
	}
	else {
		is_dead = true;
	}
}

bool Character::getFromLeft() {
	return from_left;
}

HealthBar Character::getHealthbar() {
	return *healthbar;
}

bool Character::getActive() {
	return is_active;
}

bool Character::getDead() {
	return is_dead;
}

UnitType Character::getType() {
	return type;
}

int Character::getHP() {
	return health;
}
