#pragma once

#include "./Timer.h"
#include "../Engine/Character.h"
#include "../UI/Menu.h"

class Canvas {
private:
	int money;
	sf::Text money_txt;
	std::map<Button*, UnitType> units;
	std::map<Button*, Timer*> buttons_timers;
	Timer* money_tick;
	int tower_updates_counter = 0;
	Menu* menu;
	bool is_playing = false;
public:

	Canvas(sf::Font& font);
	~Canvas();

	void drawButtons(sf::RenderWindow& window);
	void drawTimers(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);
	void addButton(float x, float y, float w, float h, sf::Vector3i border_color, sf::Vector3i button_color, sf::Vector3i text_color, sf::Text text, float time, UnitType type);
	UnitType checkClick(sf::RenderWindow& window, sf::Event& event);
	void addMoney(int money);

	int getTowerUpdatesCounter();
	bool getIsPlaying();
};