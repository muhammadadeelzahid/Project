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
#include <fstream>
#include <string>
class stats: public Shape {
	int currentScreen ;
	sf::Text text ;
	sf::Font font ;
	sf::Sprite s ;
	int scoret1 ,scoret2;
	string readScore1 , readScore2 ;
	sf::Texture icons ;
	Interface *game;
public:
	void draw(sf::RenderWindow &window) ;
	void draw2(sf::RenderWindow &window) ;
	stats();
	virtual ~stats();
	void setGame(Interface &game) ;
	int getCurrentScreen() const;
	void updateCurrentScreen() ;
	void readFromFile();
	void savetoFile();
	void setCurrentScreen(int currentScreen);
};

#endif /* STATS_H_ */
