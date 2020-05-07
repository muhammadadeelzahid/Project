/*
 * stats.cpp
 *
 *  Created on: May 7, 2020
 *      Author: AdeelZahid
 */

#include "stats.h"

stats::stats() {
	currentScreen  = 1 ;
}

int stats::getCurrentScreen() const {
	return currentScreen;
}

void stats::setCurrentScreen(int currentScreen) {
	this->currentScreen = currentScreen;
}

stats::~stats() {
	// TODO Auto-generated destructor stub
}

