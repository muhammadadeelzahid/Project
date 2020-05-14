/*
 * Mines.cpp
 *
 *  Created on: May 6, 2020
 *      Author: AdeelZahid
 */

#include "Mines.h"
#include "Interface.h"
#include "Collision.hpp"
Mines::Mines() { // @suppress("Class members should be properly initialized")
	clock = new sf::Clock;
	clock->restart();
	CollisionWithTank = false;
	this->resetMines = true;
	if (!t.loadFromFile("mines 10.png")) {
		cout << "Mine image not found" << endl;
	}
	srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		mine[i].setTexture(t);
		mine[i].setPosition(sf::Vector2f(-1000, -1000));
	}

	/*mine[0].setTexture(t) ;
	 mine[0].setPosition(sf::Vector2f(-1000,-1000)) ;
	 mine[1].setTexture(t) ;
	 mine[1].setPosition(sf::Vector2f(-1000,-1000)) ;
	 */
}

void Mines::draw(sf::RenderWindow &window) {
	if (this->game->getChangeStateDelay() == 0) {
		if (this->CollisionWithTank == false) {
			for (int i = 0; i < 4; i++) {
				window.draw(mine[i]);
			}
			/*
			 window.draw(mine[0]);
			 window.draw(mine[1]);
			 */
		} else {

			for (int i = 0; i < 4; i++) {
				mine[i].setPosition(sf::Vector2f(-1000, -1000));
			}
		}
	}
}

sf::Clock* Mines::getClock() const {
	return clock;
}

sf::Sprite* Mines::getMine() {
	return mine;
}

const sf::Texture& Mines::getT() const {
	return t;
}

void Mines::setT(const sf::Texture &t) {
	this->t = t;
}

Mines::~Mines() {
	// TODO Auto-generated destructor stub
}

bool Mines::isCollisionWithTank() const {
	return CollisionWithTank;
}

void Mines::setCollisionWithTank(bool collisionWithTank) {
	CollisionWithTank = collisionWithTank;
}

bool Mines::isResetMines() const {
	return resetMines;
}

void Mines::setResetMines(bool resetMines) {
	this->resetMines = resetMines;
}

 Interface* Mines::getGame()  {
	return game;
}

void Mines::setGame( Interface *game) {
	this->game = game;
}
void Mines::setMineCoordinates() {
	Mines &mine = *this ;
	int x1, y1, x2, y2;
	bool status = true;
	int time = 3;

	for (int i = 0; i < game->tankcount; i++) {
		if (game->tanks[i].getStatus() == 0)
			setResetMines(true);
	}
	if (mine.getClock()->getElapsedTime() > sf::seconds(time) || mine.isResetMines() == true) {
		mine.getClock()->restart();
	for (int a = 0; a < 4; a++) {
			do {
				status = true;
				x2 = rand() % (game->screenFactor * game->sizeofcoordinates);
				y2 = rand() % (game->screenFactor * game->sizeofcoordinates);

				mine.getMine()[a].setPosition(sf::Vector2f(x2, y2));
				//checking collision with Tanks
				for (int i = 0; i < game->tankcount; i++) {
					if (Collision::PixelPerfectTest(mine.getMine()[a], game->tanks[i].getTank())) {
						status = false;
					}
				}
				//with walls
				for (int i = 0; i < game->brickcounter; i++) {
					game->temp1.setPosition(game->bricks.getBrick()[i].getPosition());
					if (Collision::PixelPerfectTest(mine.getMine()[a], game->temp1)) {
						status = false;
					}
				}
				//Most important check if two mines have exact same coordinates
				for (int g = 0; g < a; g++) {
					if (Collision::PixelPerfectTest(mine.getMine()[a], mine.getMine()[g]))
						status = false;
				}

			} while (status == false);
		}
		if (!(mine.getClock()->getElapsedTime() > sf::seconds(time)) && mine.isResetMines() == true) {
			mine.setResetMines(false);
		}

	}
}
