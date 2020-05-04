/*
 * Interface.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 *///a

#ifndef INTERFACE_H_
#define INTERFACE_H_
//#include "Collision.hpp"
#include <iostream>
#include "Wall.h"
#include "Tank.h"
using namespace std ;
class Interface {
	//basic array that identifies with each token of the object
	int **coordinates ;//set the size in the constructor
	int score ;
	int sizeofcoordinates ; // size of screen /screenFactor
	int screenFactor ; //Walls and spaces will be of 15x15
	int brickcounter ;
	//all the arrays of the Game objects we will use
	Wall bricks ;
	Tank *tanks ;
	int tankcount; //number of tanks
	sf::Texture texture1 ; //texture for tank1
	sf::Texture texture2 ;//texture for tank2

	//temporary stuff
	sf::Image img ;
	sf::Sprite temp1 ;
	sf::Texture temp;
public:
	//functions involving movement and collision of Bullets
	void moveBullets() ;
	void BulletscollisionWithWalls();
	void BulletscollisionWithTank();
	void fire(int tankNumber);
	void destroyBullet();

	//functions involving movement and collision of Bullets Ends

	void StopGame(); // detect if one of the tanks are shot

	void moveTank(string direction,int tankNumber) ;
	bool collisionTankWall(int tankNumber) ;
	Interface(int,int) ;
	void drawMaze() ;
	void display(sf::RenderWindow &window) ;
	virtual ~Interface();
	int** getCoordinates() ;
	int getScore() const;
	void setScore(int score);
	int getSize() const;
	 Tank*& getTanks() ;
};

#endif /* INTERFACE_H_ */
