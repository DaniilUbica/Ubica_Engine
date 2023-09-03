#pragma once

#include "Button.h"
#include "../Engine/Globals.h"

class LoseScreen {
private:
	Button* to_menu;
	sf::Text* lose_text;
public:
	LoseScreen(sf::Font& font);
	~LoseScreen();

	void Update(sf::RenderWindow& window);
	void showLoseScreen(sf::RenderWindow& window, int winner);
	int checkClick(sf::RenderWindow& window, sf::Event& event);
};