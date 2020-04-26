/*
 * Shape.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: AdeelZahid
 */

#include "Shape.h"

Shape::Shape() {

}

const string& Shape::getName() const {
	return name;
}

void Shape::setName(const string &name) {
	this->name = name;
}

const Coordinate& Shape::getPosition() const {
	return position;
}

void Shape::setPosition(const Coordinate &position) {
	this->position = position;
}

int Shape::getSpeedOfMovement() const {
	return speedOfMovement;
}

void Shape::setSpeedOfMovement(int speedOfMovement) {
	this->speedOfMovement = speedOfMovement;
}

int Shape::getTokenValue() const {
	return tokenValue;
}

void Shape::setTokenValue(int tokenValue) {
	this->tokenValue = tokenValue;
}

Shape::~Shape() {
	// TODO Auto-generated destructor stub
}

