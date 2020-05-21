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
	int lives; //if tank has been destroyed or not
	int score ;
	Bullet bullets[50]  ;
	int firedbullets ;
	int status ;

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
	int getStatus() const;
	void setStatus(int status);
	int getScore() const;
	void setScore(int score);
	int getLives() const;
	void setLives(int lives);
};

#endif /* TANK_H_ */
