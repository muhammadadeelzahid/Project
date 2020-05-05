/*
 * Statistics.cpp
 *
 *  Created on: May 5, 2020
 *      Author: AdeelZahid
 */

#include "Statistics.h"

Statistics::Statistics() {
	// TODO Auto-generated constructor stub
	for (int i = 0 ;i<100; i++)
		scores[i] = 0 ;
}
void Statistics::fetchScores(Tank *tanks,int count)
{
	for (int i =0 ; i<count ;i++)
	{
		//scores[i] +=tanks[i].score  ;
	}
}
Statistics::~Statistics() {
	// TODO Auto-generated destructor stub
}

