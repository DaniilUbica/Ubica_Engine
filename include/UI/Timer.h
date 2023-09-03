#pragma once

#include <SFML/Graphics.hpp>

class Timer {
private:
	sf::RectangleShape rect;
	int time;
	int max_time;
	float width;
	float height;
	float frame_size;
	const float BAR_HEIGHT = 15.0;
	sf::Sprite sprite;
	bool is_end;
	sf::Clock clock;
public:
	Timer(float time, float coordX, float coordY, float width, float height);

	void Update();
	void Restart();

	bool getEnd();
	sf::RectangleShape getRect();
	sf::Sprite getSprite();
};