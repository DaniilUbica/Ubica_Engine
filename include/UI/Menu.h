#pragma once

#include "../Engine/Globals.h"
#include "./Button.h"

class Menu {
private:
	Button* start, * exit;
	sf::Text* title;
	bool is_active = true;
public:
	Menu(sf::Font& font);
	~Menu();

	void Update(sf::RenderWindow& window);
	void showMenu(sf::RenderWindow& window);
	int checkClick(sf::RenderWindow& window, sf::Event& event);
};