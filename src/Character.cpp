#include "../include/Engine/Character.h"

void Character::takeDamage(int damage) {
	health -= damage;
	sprite.setColor(sf::Color::Red);
	sprite.setColor(sf::Color::White);
}

Direction Character::getDirection() {
	return direction;
}

int Character::getHP() {
	return health;
}

float Character::getAngle() {
	return angle;
}

void Character::setDirection(Direction direction) {
	this->direction = direction;
}

void Character::setAngle(float angle) {
	this->angle = angle;
}

void Character::checkCollision(std::vector<Object> objects) {
	sf::FloatRect rect = this->sprite.getGlobalBounds();
	for (Object obj : objects) {
		sf::FloatRect o_rect = obj.r.getGlobalBounds();
		if (rect.intersects(obj.r.getGlobalBounds())) {
			if (obj.type == SOLID) {
				float overlapX = std::min(rect.left + rect.width, o_rect.left + o_rect.width) - std::max(rect.left, o_rect.left);
				float overlapY = std::min(rect.top + rect.height, o_rect.top + o_rect.height) - std::max(rect.top, o_rect.top);
				if (overlapX < overlapY) {
					if (rect.left < o_rect.left) {
						coordX = o_rect.left - rect.width / 2;
					}
					else {
						coordX = o_rect.left + o_rect.width + rect.width / 2;
					}
				}
				else {
					if (rect.top < o_rect.top) {
						coordY = o_rect.top - rect.height / 2;
					}
					else {
						coordY = o_rect.top + o_rect.height + rect.height / 2;
					}
				}
			}
		}
	}
}