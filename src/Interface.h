/*
 * Interface.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

class Interface {
	int **coordinates ;//set the size in the constructor
	int score ;
public:
	Interface();
	virtual ~Interface();
	int** getCoordinates() ;
	int getScore() const;
	void setScore(int score);
};

#endif /* INTERFACE_H_ */
