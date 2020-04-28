//============================================================================
// Name        : Adeel.cpp
// Author      : Adeel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Interface.h"
#include "Brick.h" // most probably wont be used as it doesnt require any specialized function
#include "Bullet.h"
#include "Tank.h"
int main()
{
	//this is the main files
	int sizeScreen = 800 ;
	Interface game(sizeScreen) ;

	sf::RenderWindow window(sf::VideoMode(sizeScreen,sizeScreen), "Game");
	game.drawMaze() ;
	while (window.isOpen())
    {
		sf::Color background (220,220,220) ;
	 	window.clear(background);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        game.display(window) ;
        window.display() ;
    }



    return 0;
}
