/*
 * Interface.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 *///a

#ifndef INTERFACE_H_
#define INTERFACE_H_
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
	sf::Texture texture1 ;

public:
	//functions involving movement and collision of bricks
	void moveBullets() ;
	void BulletscollisionWithWalls();
	void BulletscollisionWithTank();
	void fire(int tankNumber);
	void destroyBullet();

	//functions involving movement and collision of bricks Ends

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
