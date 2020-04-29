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
//	Tank tanks ;

public:
	Interface(int,int) ;
	void drawMaze() ;
	void display(sf::RenderWindow &window) ;
	virtual ~Interface();
	int** getCoordinates() ;
	int getScore() const;
	void setScore(int score);
	int getSize() const;
};

#endif /* INTERFACE_H_ */
