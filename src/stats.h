/*
 * stats.h
 *
 *  Created on: May 7, 2020
 *      Author: AdeelZahid
 */

#ifndef STATS_H_
#define STATS_H_

#include "Shape.h"
#include "Interface.h"
class stats: public Shape {
	int currentScreen ;
	sf::Text text ;
	sf::Font font ;
	sf::Sprite s ;
	sf::Texture icons ;
	Interface *game;

public:
	void draw(sf::RenderWindow &window) ;
	stats();
	virtual ~stats();
	void setGame(Interface &game) ;
	int getCurrentScreen() const;
	void updateCurrentScreen() ;
	void setCurrentScreen(int currentScreen);
};

#endif /* STATS_H_ */
