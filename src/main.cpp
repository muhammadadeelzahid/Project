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
void move(string direction,Interface *game);
int main()
{
	//this is the main files
	int sizeScreen = 780 ;
	int sizeOfObject  =  30 ;
	Interface game(sizeScreen,sizeOfObject) ;
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
            //logic for movement starts

        	//make changes here below to control the movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
            	move("Up",&game);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
            	move("Down",&game);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
            	move("Right",&game);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
            	move("Left",&game);
            }



        }

        game.display(window) ;
    }
	return 0;
}
void move(string direction,Interface *game)
{
	sf::Sprite *temp = &game->getTanks()[0].getTank() ;
	int radian = temp->getRotation() * 3.14 /180 ; //rotation angle is converted from degrees to rotation
	 float distance = 10 ; //distance to be moved // controls the speed of movement

	 if (direction == "Up")
	 	 {
	 		 int angle = temp->getRotation() ;
	 		 switch (angle)
	 		 {
	 			 case 0:
	 					temp->move(+0,-distance) ;
	 					if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 						temp->move(0,+distance) ;
	 						break;
	 			 case 45:
	 						temp->move(+distance,-distance) ;
	 						if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 							temp->move(-distance,+distance) ;
	 						 break;
	 			 case 90:
	 				 temp->move(+distance, 0);
	 				 if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 					 temp->move(-distance, 0);
	 				 break;
	 			 case 135:
	 				 temp->move(+distance, distance);
	 				 if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 					 temp->move(-distance, -distance);
	 				 break;
	 			 case 180:
	 				 temp->move(0, distance);
	 				 if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 					 temp->move(0, -distance);
	 				 break;
	 			 case 225:
	 				 temp->move(-distance, distance);
	 				 if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 					 temp->move(distance, -distance);
	 				 break;
	 			 case 270:
	 				 temp->move(-distance, 0);
	 				 if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 					 temp->move(distance, 0);
	 				 break;
	 			 case 315:
	 				 temp->move(-distance, -distance);
	 				 if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 					 temp->move(distance, distance);
	 				 break;

	 		 }
	 	 }
	 	 else if (direction == "Down")
	 	 {
	 		 int angle = temp->getRotation();
	 		 switch (angle)
	 		 {
	 		 case 0:
	 			 temp->move(+0, distance);
	 			 if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(0, -distance);
	 			 break;
	 		 case 45:
	 			 temp->move(-distance, distance);
	 			 if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(distance, -distance);
	 			 break;
	 		 case 90:
	 			 temp->move(-distance, 0);
	 			 if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(distance, 0);
	 			 break;
	 		 case 135:
	 			 temp->move(-distance, -distance);
	 			 if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(distance, distance);
	 			 break;
	 		 case 180:
	 			 temp->move(0, -distance);
	 			 if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(0, distance);
	 			 break;
	 		 case 225:
	 			 temp->move(distance, -distance);
	 			 if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(-distance, distance);
	 			 break;
	 		 case 270:
	 			 temp->move(distance, 0);
	 			 if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(-distance, 0);
	 			 break;
	 		 case 315:
	 			 temp->move(distance, distance);
	 			 if (game->collisionTankWall()) // if colliding then do the reverse and move back to the same coordiantes
	 				 temp->move(-distance, -distance);
	 			 break;

	 		 }
	 	 }
	 else if ( direction == "Right")
	 {
		 temp->rotate(45) ;
		 if ((game->collisionTankWall()) )
			 temp->rotate(-45) ;
	 }
	 else if ( direction == "Left")
	 {
		 temp->rotate(-45) ;
		 if ((game->collisionTankWall()) )
			 temp->rotate(+45) ;
	 }
}
