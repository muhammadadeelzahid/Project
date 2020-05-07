/*
 * stats.cpp
 *
 *  Created on: May 7, 2020
 *      Author: AdeelZahid
 */

#include "stats.h"

stats::stats() {
	currentScreen = 1;
	if (!font.loadFromFile("font.ttf")) {
		cout << "Unable to load font" << endl;
	}
	text.setFont(font);

	if (!icons.loadFromFile("menue.jpg")) {
		cout << "Unable to load picture" << endl;
	}
	s.setTexture(icons);

}
void stats::setGame(Interface &game) {
	this->game = &game;
}

int stats::getCurrentScreen() const {
	return currentScreen;
}

void stats::updateCurrentScreen() {
	this->currentScreen = currentScreen + 1;
}
void stats::draw(sf::RenderWindow &window) {
	if (currentScreen == 1) {
		window.clear(sf::Color(120, 120, 120, 0));
		text.setString("Tank Attack Maze");
		text.setColor(sf::Color::Black);
		text.setCharacterSize(50);
		text.setPosition(sf::Vector2f(200, 100));
//		window.draw(s) ;
		window.draw(text);
	}
	if (currentScreen == 4) {
		window.clear(sf::Color(120, 120, 120, 0));
		text.setString("Game Over R to reset");
		text.setColor(sf::Color::Black);
		text.setCharacterSize(50);
		text.setPosition(sf::Vector2f(100, 100));
//		window.draw(s) ;
		window.draw(text);
	}
}

void stats::draw2(sf::RenderWindow &window) {
	if (currentScreen == 3 || currentScreen == 1) {
		window.clear(sf::Color::White);

		text.setColor(sf::Color::Black);
		text.setCharacterSize(20);

		text.setString("Scores");
		text.setPosition(sf::Vector2f(150, 50));
		window.draw(text);

		text.setString("Team 1:");
		text.setPosition(sf::Vector2f(10, 80));
		window.draw(text);

		text.setString("Team 2:");
		text.setPosition(sf::Vector2f(250, 80));
		window.draw(text);

		text.setString(to_string(game->getTanks()[0].getScore())) ;;
		text.setColor(sf::Color::Red);
		text.setPosition(sf::Vector2f(100, 80));
		window.draw(text);

		text.setString(to_string(game->getTanks()[1].getScore())) ;;
		text.setColor(sf::Color::Red);
		text.setPosition(sf::Vector2f(350, 80));
		window.draw(text);



	}
}

stats::~stats() {
	// TODO Auto-generated destructor stub
}

void stats::setCurrentScreen(int currentScreen) {
	this->currentScreen = currentScreen;
}
