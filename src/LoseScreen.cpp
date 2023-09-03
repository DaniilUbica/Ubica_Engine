#include "../include/UI/LoseScreen.h"
// Button(float x, float y, float w, float h, sf::Vector3i border_color, sf::Vector3i button_color, sf::Vector3i text_color, sf::Text text)
LoseScreen::LoseScreen(sf::Font& font) {
	sf::Text to_menu_txt("Back to menu", font);

	to_menu = new Button(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2, 100, 50, sf::Vector3i(168, 79, 79),
		sf::Vector3i(212, 73, 73), sf::Vector3i(255, 255, 255), to_menu_txt);

	lose_text = new sf::Text("", font);
	lose_text->setCharacterSize(70);
	lose_text->setFillColor(sf::Color(224, 56, 76));
	lose_text->setPosition(510, 100);
}

LoseScreen::~LoseScreen() {
	delete to_menu;
	delete lose_text;
}

void LoseScreen::Update(sf::RenderWindow& window) {
	to_menu->Update(window);
}

void LoseScreen::showLoseScreen(sf::RenderWindow& window, int winner) {
	if (winner == 1) {
		lose_text->setString("You   lose!");
	}
	else if (winner == 0) {
		lose_text->setString("You   win!");
	}

	to_menu->drawButton(window);
	window.draw(*lose_text);
}

int LoseScreen::checkClick(sf::RenderWindow& window, sf::Event& event) {
	if (to_menu->checkClick(window, event)) {
		return 1;
	}
	return 0;
}
