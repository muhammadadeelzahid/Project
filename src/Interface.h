/*
 * Interface.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 *///a

#ifndef INTERFACE_H_
#define INTERFACE_H_
#include <iostream>
using namespace std ;
#include <SFML/Graphics.hpp>
class Interface {
	//basic array that identifies with each token of the object
	int **coordinates ;//set the size in the constructor
	int score ;
	int screensize ;
	int screenFactor = 25;
	//all the arrays of the Game objects we will use
	sf::Sprite *Brick ;
	sf::Texture BrickTexture ;
public:
	Interface(int) ;
	void drawMaze() ;
	void display(sf::RenderWindow &window) ;
	void BrickInitialise() ;
	virtual ~Interface();
	int** getCoordinates() ;
	int getScore() const;
	void setScore(int score);
	int getSize() const;
};

#endif /* INTERFACE_H_ */
