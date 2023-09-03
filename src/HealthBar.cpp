#include "../include/UI/HealthBar.h"
#include <iostream>

HealthBar::HealthBar(float coordX, float coordY, int hp, int width) {
	this->hp = hp;
	health.setPosition(coordX, coordY - 15.0);
	health.setSize(sf::Vector2f(width, BAR_HEIGHT));
	health.setFillColor(sf::Color(21, 208, 30));

	background.setPosition(coordX - BACKGROUND_OFFSET, coordY - 15.0 - BACKGROUND_OFFSET);
	background.setSize(sf::Vector2f(width + BACKGROUND_OFFSET*2, BAR_HEIGHT + BACKGROUND_OFFSET * 2+1.0));
	background.setFillColor(sf::Color(96, 127, 97));

	frame_size = float(width) / float(hp);
}

void HealthBar::Update(float coordX, float coordY, int hp) {
	health.setPosition(coordX, coordY - 10.0);
	background.setPosition(coordX - BACKGROUND_OFFSET, coordY - 10.0 - BACKGROUND_OFFSET);
	if (hp < 0) {
		hp = 0;
	}
	if (health.getSize().x > 0) {
		health.setSize(sf::Vector2f(frame_size * hp, BAR_HEIGHT));
	}
}

void HealthBar::drawHealthBar(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(health);
}

sf::RectangleShape HealthBar::getRect() {
	return health;
}
