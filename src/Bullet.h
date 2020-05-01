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
sf::Sprite bullet ;
sf::Texture t;
int RotationAngle;
public:
	friend class Interface;
	Bullet();
	~Bullet() { ;}//
	void draw(sf::RenderWindow &window);
	const sf::Sprite& getBullet() const;
	void setBullet(const sf::Sprite &bullet);
	int getRotationAngle() const;
	void setRotationAngle(int rotationAngle);
};

#endif /* BULLET_H_ */
