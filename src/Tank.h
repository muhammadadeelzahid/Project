/*
 * Tank.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#ifndef TANK_H_
#define TANK_H_
class Interface ;
#include "Shape.h"
#include "Bullet.h"
#include "Wall.h"
class Tank: public Shape {
	sf::Sprite tank ;
	int status; //if tank has been destroyed or not
	int score ;
	Bullet bullets[50]  ;
	int firedbullets ;

public:
	friend class Interface ;
	~Tank() { ; }
	Tank() ;
	void setTexture(sf::Texture &texture) ;
	void draw(sf::RenderWindow &object) ;
	void initialiseTank(int) ;

	 sf::Sprite& getTank() ;
	int getFiredbullets() ;
	void setFiredbullets(int firedbullets);
};

#endif /* TANK_H_ */
