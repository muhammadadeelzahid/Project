/*
 * Bullet.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#ifndef BULLET_H_
#define BULLET_H_
class Interface;
#include "Shape.h"
class Bullet: public Shape {
//sf::Sprite bullet ;
sf::Sprite bullet ;
sf::Texture t;
int RotationAngle;
sf::Clock clock ;
public:
	friend class Interface;
	void startTimer() ;
	bool CheckBulletTimeout() ;
	Bullet();
	~Bullet() { ;}//
	void draw(sf::RenderWindow &window);
	sf::Sprite& getBullet();
	void setBullet(const sf::Sprite &bullet);
};

#endif /* BULLET_H_ */
