#include "../include/UI/Menu.h"

Menu::Menu(sf::Font& font) {
	sf::Text start_txt("Start game", font);
	sf::Text exit_txt("Exit", font);

	start = new Button(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2, 100, 50, sf::Vector3i(168, 79, 79),
		sf::Vector3i(212, 73, 73), sf::Vector3i(255, 255, 255), start_txt);
	exit = new Button(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2 + 100, 100, 50, sf::Vector3i(168, 79, 79),
		sf::Vector3i(212, 73, 73), sf::Vector3i(255, 255, 255), exit_txt);

	title = new sf::Text("  PEOPLE\n           VS\nUNDEADS", font);
	title->setCharacterSize(70);
	title->setFillColor(sf::Color(224, 56, 76));
	title->setPosition(510, 100);
}

Menu::~Menu() {
	delete start;
	delete exit;
	delete title;
}

void Menu::Update(sf::RenderWindow& window) {
	start->Update(window);
	exit->Update(window);
}

void Menu::showMenu(sf::RenderWindow& window) {
	start->drawButton(window);
	exit->drawButton(window);
	window.draw(*title);
}

int Menu::checkClick(sf::RenderWindow& window, sf::Event& event) {
	if (start->checkClick(window, event)) {
		is_active = false;
		return 1;
	}
	if (exit->checkClick(window, event)) {
		return 0;
	}
	return 2;
}
