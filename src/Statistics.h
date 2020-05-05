/*
 * Statistics.h
 *
 *  Created on: May 5, 2020
 *      Author: AdeelZahid
 */

#ifndef STATISTICS_H_
#define STATISTICS_H_

#include "Shape.h"
#include "Tank.h"
class Statistics: public Shape {
	int scores [100] ;
public:
	void fetchScores(Tank *tanks,int count) ;
	Statistics();
	virtual ~Statistics();
};

#endif /* STATISTICS_H_ */
