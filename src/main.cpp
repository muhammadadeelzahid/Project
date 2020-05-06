//============================================================================
// Name        : Adeel.cpp
// Author      : Adeel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <cmath>
#include "Interface.h"
#include "Bullet.h"
#include "Tank.h"
#include "Wall.h" // most probably wont be used as it doesnt require any specialized function
void MoveBulletsTimed(sf::Clock &clock, Interface &game);
void timedIncrement(sf::Clock &clock2, Interface &game);
void ChangeStateDelay(sf::Clock &clock3, Interface &game);
int main() {
	sf::Clock clock;
	sf::Clock clock2;
	sf::Clock clock3;

	//this is the main files
	int sizeScreen = 780;
	int sizeOfObject = 26;
	int sizeForBar = 780;
	Interface game(sizeForBar, sizeOfObject);

	sf::RenderWindow stats(sf::VideoMode(400, 250), "Game Stats");
	stats.setPosition(sf::Vector2i(10, 200));
	game.drawMaze();
	sf::RenderWindow window(sf::VideoMode(sizeForBar, sizeScreen), "Game");
	window.setPosition(sf::Vector2i(window.getPosition().x + 100, window.getPosition().y));

	while (window.isOpen()) {
		sf::Color background(220, 220, 220);
		window.clear(background);

		sf::Event event;
		if (game.getPause() == 1) {
			//window.clear(background);
		}
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (game.getPause() == 0 && game.getChangeStateDelay() == 0) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
						game.fire(0);
						cout << "Fire tank 1" << endl;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
						game.fire(1);
						cout << "Fire Tank 2" << endl;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
						game.moveTank("Up", 1); // Move tank Number 1 upwards //index of arrays start from 0
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
						game.moveTank("Down", 1); // Move tank Number 1 Down
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
						game.moveTank("Right", 1); // Move tank Number 1 Right
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
						game.moveTank("Left", 1); // Move tank Number 1 Left
					}
					//logic for movement starts

					//make changes here below to control the movement
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
						game.moveTank("Up", 0); // Move tank Number 1 upwards //index of arrays start from 0
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
						game.moveTank("Down", 0); // Move tank Number 1 Down
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
						game.moveTank("Right", 0); // Move tank Number 1 Right
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
						game.moveTank("Left", 0); // Move tank Number 1 Left
					}
				}
				//for pause
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
					game.setPause(1 - game.getPause());
					//cout<<"Pause status: "<<game.getPause()<<endl;
				}

			}

		}
		if( game.getPause() == 1 )
			game.Maze_Change_And_Pause_Message(window);
		if (game.getPause() == 0 || game.getChangeStateDelay() != 0) {
			game.setMineCoordinates();
			MoveBulletsTimed(clock, game);
			game.BulletscollisionWithTank();
		}
		game.display(window);
		if (game.getChangeStateDelay() != 0) {
			game.Maze_Change_And_Pause_Message(window);
		}




		ChangeStateDelay(clock3, game);
		window.display();
		timedIncrement(clock2, game);
	}
	return 0;
}
void timedIncrement(sf::Clock &clock2, Interface &game) {
	if (clock2.getElapsedTime() > sf::milliseconds(100)) {
		if (game.getDestruction().getStart() == 1) {
			cout << "Destruction start" << endl;
			clock2.restart();
			//		game.getDestruction().setStart(game.getDestruction().getStart()+1) ;
			return;
		}
		if (game.getDestruction().getStart() > 0) {
			game.getDestruction().setStart(game.getDestruction().getStart() + 1);
			clock2.restart();
		}
	}
}
void MoveBulletsTimed(sf::Clock &clock, Interface &game) {

	if (clock.getElapsedTime() > sf::milliseconds(25)) {
		game.moveBullets();
		clock.restart();
	}
}
void ChangeStateDelay(sf::Clock &clock3, Interface &game) {
	if (game.getChangeStateDelay() == 1) {
		clock3.restart();
		game.setChangeStateDelay(2);
		return;
	}
	if (clock3.getElapsedTime() > sf::seconds(2) && game.getChangeStateDelay() == 2) {
		game.setChangeStateDelay(4);
	}
}

