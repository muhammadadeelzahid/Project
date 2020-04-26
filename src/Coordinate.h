/*
 * Coordinate.h
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

class Coordinate {
	int x ;int y;
public:
	Coordinate();
	virtual ~Coordinate();
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
};

#endif /* COORDINATE_H_ */
