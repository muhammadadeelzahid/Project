/*
 * stats.h
 *
 *  Created on: May 7, 2020
 *      Author: AdeelZahid
 */

#ifndef STATS_H_
#define STATS_H_

#include "Shape.h"

class stats: public Shape {
	int currentScreen ;
public:
	void draw(sf::RenderWindow &window) {;};
	stats();
	virtual ~stats();
	int getCurrentScreen() const;
	void setCurrentScreen(int currentScreen);
};

#endif /* STATS_H_ */
