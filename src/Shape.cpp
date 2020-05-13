/*
 * Shape.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Shape.h"

Shape::Shape() {

}



int Shape::getObjectsize() const {
	return objectsize;
}

void Shape::setObjectsize(int objectsize) {
	this->objectsize = objectsize;
}
