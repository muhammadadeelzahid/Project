/*
 * Timer.h
 *
 *  Created on: May 5, 2020
 *      Author: AdeelZahid
 */

#ifndef TIMER_H_
#define TIMER_H_
#include <SFML/Graphics.hpp>
class Timer {
	sf::Clock mC;
	float runTime;
	bool bPaused;
public:
	Timer();

	void Reset();

	void Start();

	void Pause();

	float GetElapsedSeconds();
};
#endif /* TIMER_H_ */
