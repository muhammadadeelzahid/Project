/*
 * Interface.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Interface.h"

Interface::Interface() {
	score = 0 ;
	int size = 250 ;
	coordinates = new int*[size] ;
	for(int i = 0 ; i<250 ; i++)
	{
		coordinates[i] = new int[size] ;
	}

}

int** Interface::getCoordinates()  {
	return coordinates;
}

int Interface::getScore() const {
	return score;
}

void Interface::setScore(int score) {
	this->score = score;
}

Interface::~Interface() {
	// TODO Auto-generated destructor stub
}

