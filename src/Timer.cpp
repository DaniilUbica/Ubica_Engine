#include "../include/UI/Timer.h"
#include "../include/Engine/Globals.h"

Timer::Timer(float time, float coordX, float coordY, float width, float height) {
	max_time = time;
	is_end = false;
	this->width = width;
	this->height = height;

	rect.setSize(sf::Vector2f(width, height));
	rect.setFillColor(sf::Color(255, 255, 255, 127));

	frame_size = height / time;

	sprite.setPosition(coordX, coordY);
	rect.setPosition(coordX, coordY + height);
}

void Timer::Update() {

	sf::Time timer;
	timer = clock.getElapsedTime();
	if (timer.asSeconds() >= max_time) {
		is_end = true;
	}

	if (timer.asSeconds() < max_time) {
		rect.setSize(sf::Vector2f(width, -height + frame_size * timer.asSeconds()));
	}
}

void Timer::Restart() {
	is_end = false;
	clock.restart();
}

bool Timer::getEnd() {
	return is_end;
}

sf::RectangleShape Timer::getRect() {
	return rect;
}

sf::Sprite Timer::getSprite() {
	return sprite;
}
