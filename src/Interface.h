/*
 * Interface.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_
#include <iostream>
using namespace std ;
#include <SFML/Graphics.hpp>
class Interface {
	int **coordinates ;//set the size in the constructor
	int score ;
	int size ;
public:
	Interface();
	Interface(int) ;
	void drawMaze() ;
	void display(sf::RenderWindow &window) ;
	virtual ~Interface();
	int** getCoordinates() ;
	int getScore() const;
	void setScore(int score);
	int getSize() const;
};

#endif /* INTERFACE_H_ */
