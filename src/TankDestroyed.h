/*
 * TankDestroyed.h
 *
 *  Created on: May 5, 2020
 *      Author: AdeelZahid
 */

#ifndef TANKDESTROYED_H_
#define TANKDESTROYED_H_

#include "Shape.h"

class TankDestroyed: public Shape {
	int start ;
	sf::Sprite flames ;
	sf::Texture texture ;
public:
	friend class Interface;
	TankDestroyed();
	void draw(sf::RenderWindow &window);
	virtual ~TankDestroyed();
	int getStart() const;
	void setStart(int start);
};

#endif /* TANKDESTROYED_H_ */
