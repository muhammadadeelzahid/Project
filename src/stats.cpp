/*
 * stats.cpp
 *
 *  Created on: May 7, 2020
 *      Author: AdeelZahid
 */

#include "stats.h"

stats::stats() {
	music.openFromFile("music.ogg");
	music.setLoop(true);
	this->startMusic = 0;

	side.loadFromFile("stats.png");
	sp.setTexture(side);
	about.loadFromFile("about.png");
	currentScreen = 1;
	menueOption = 1;
	instruc.loadFromFile("Instructions.png");
	noResult = 0;
	if (!font.loadFromFile("font.ttf")) {
		cout << "Unable to load font" << endl;
	}
	text.setFont(font);
	/*
	 if (!icons.loadFromFile("menue.jpg")) {
	 cout << "Unable to load picture" << endl;
	 }
	 s.setTexture(icons);
	 */
	for (int i = 0; i < 3; i++) {
		readScore1[i] = "";
		readScore2[i] = "";
	}
	if (!option1.loadFromFile("menue (1).png"))
		cout << "Unable to load menue 1" << endl;

	if (!option2.loadFromFile("menue (2).png"))
		cout << "Unable to load menue 2" << endl;

	if (!option3.loadFromFile("menue (3).png"))
		cout << "Unable to load menue 3" << endl;
	if (!option4.loadFromFile("menue (4).png"))
		cout << "Unable to load menue 4" << endl;

	readWritePermission = 1;
	readWritePermission2 = 1;

}
void stats::setGame(Interface &game) {
	this->game = &game;
}

int stats::getCurrentScreen() const {
	return currentScreen;
}

void stats::updateCurrentScreen() {
	this->currentScreen = currentScreen + 1;
}
void stats::draw(sf::RenderWindow &window) {
	if (currentScreen != 3 )
	{
		if (startMusic == 0 )
			startMusic = 1;
	}
	else
	{
		if (startMusic == 2 )
			startMusic = 0;
	}
	if (startMusic == 1 ){
		music.play();
		startMusic = 2 ;
	}else if (startMusic == 0 )
	{
		music.stop();
		startMusic = 1 ;
	}

	if (currentScreen == 1) {
		s.setOrigin(sf::Vector2f(0, 3.5));
		if (menueOption == 1)
			s.setTexture(option1);
		else if (menueOption == 2)
			s.setTexture(option2);
		else if (menueOption == 3)
			s.setTexture(option3);
		else if (menueOption == 4)
			s.setTexture(option4);

		window.draw(s);
	}
	if (currentScreen == 2)
	{
		window.clear(sf::Color(225,225,225));
		s.setTexture(instruc);
		s.setPosition(1.5,0);
		window.draw(s);
	}
	if (currentScreen == 5)
	{
		window.clear(sf::Color(225,225,225));
		s.setTexture(about);
		s.setPosition(1.5,0);
		window.draw(s);

	}
	if (currentScreen == 4) {

		s.setPosition(sf::Vector2f(1, 0));
		window.clear(sf::Color(225, 225, 225));

		if (game->getTanks()[0].getScore() > game->getTanks()[1].getScore()) {
			end1.loadFromFile("end.A.png");
			s.setTexture(end1);
		} else if (game->getTanks()[0].getScore() < game->getTanks()[1].getScore())
		{
			end1.loadFromFile("end.B.png");
			s.setTexture(end1);
		}
		else
		{
			end1.loadFromFile("End.C.png");
			s.setTexture(end1);
		}
		text.setCharacterSize(36);
		text.setFillColor(sf::Color(46, 49, 146));
		window.draw(s);
		int z = 400;
		for (int i = 0; i < 3; i++, z += 100) {
			text.setString(readScore1[2 - i]);
			if (i == 0)
				text.setPosition(sf::Vector2f(222.533, (472.54 - 30)));
			if (i == 1)
				text.setPosition(sf::Vector2f(222.532, (539.917 - 30)));
			if (i == 2)
				text.setPosition(sf::Vector2f(223.55, (603.985 - 30)));

			window.draw(text);
		}

		z = 400;
		for (int i = 0; i < 3; i++, z += 100) {
			text.setString(readScore2[2 - i]);
			if (i == 0)
				text.setPosition(sf::Vector2f(534.708, (472.454 - 30)));
			if (i == 1)
				text.setPosition(sf::Vector2f(534.709, (541.835 - 30)));
			if (i == 2)
				text.setPosition(sf::Vector2f(534.709, (607.021 - 30)));

			window.draw(text);
		}

		/*
		 text.setString("Press T to Reset");
		 text.setPosition(sf::Vector2f(150, 500));

		 //		window.draw(text);
		 if (scoret1 >scoret2)
		 text.setString("Team A wins");
		 else if (scoret1 <scoret2)
		 text.setString("Team B wins");
		 else
		 text.setString("Draw");
		 text.setPosition(100,130);
		 window.draw(text);
		 */
		this->readWritePermission = 0;

	}
}

void stats::draw2(sf::RenderWindow &window) {
	if (currentScreen == 3 || currentScreen == 1 || currentScreen == 4) {
		window.clear(sf::Color::White);
		sp.setPosition(sf::Vector2f(-0.5,0));
		window.draw(sp);

		text.setCharacterSize(28);

		text.setString(to_string(game->getTanks()[0].getScore()));
		scoret1 = game->getTanks()[0].getScore();
		scoret2 = game->getTanks()[1].getScore();
		float height = 145;
		text.setFillColor(sf::Color::Red);
		text.setPosition(sf::Vector2f(130, height));
		window.draw(text);

		text.setCharacterSize(25);
		if (this->currentScreen == 4)
			text.setString(to_string(2));
		else
			text.setString(to_string(game->getTanks()[0].getLives()));
		text.setPosition(sf::Vector2f(130,height+47));
		window.draw(text);


		text.setCharacterSize(28);
		text.setString(to_string(game->getTanks()[1].getScore()));
		text.setFillColor(sf::Color::Blue);
		text.setPosition(sf::Vector2f(310, height));
		window.draw(text);

		text.setCharacterSize(25);
		text.setString(to_string(game->getTanks()[1].getLives()));
		text.setPosition(sf::Vector2f(310,height+47));
		window.draw(text);


		text.setFillColor(sf::Color(96,57,19));
		text.setCharacterSize(26);
		text.setString(to_string(game->getCurrentMaze()));
		text.setPosition(sf::Vector2f(130,232));
		window.draw(text);


		if (game->isGameOver() == true && game->getChangeStateDelay() == 4 && readWritePermission2 == 1) {
			//savetoFile() ;
			readFromFile();
			//cout << "This" << endl;
			readWritePermission2 = 0;
		}
	}
}

stats::~stats() {
	;
}
void stats::savetoFile() {
	if( noResult == 0){
	ifstream file;
	file.open("score.txt");
	if (!file.is_open()) {
		cout << "Unable to open file to write" << endl;
	}
	string stringtemp[3] = { "" };
	for (int i = 0; i < 3; i++) {
		getline(file, stringtemp[i]);
//		cout<<"HEre "<<stringtemp[i]<<endl;
	}
	file.close();

	for (int i = 1; i < 3; i++) {
		stringtemp[i - 1] = stringtemp[i];
	}
	stringtemp[2] = to_string(scoret1) + "-" + to_string(scoret2) + ">\n";

	ofstream file2;
	file2.open("score.txt");
	for (int i = 0; i < 3; i++) {
		//cout << "i: " << i << "  " << stringtemp[i] << endl;
		//file2 << stringtemp[i] << "\n";
		//cout<<"Writing this "<<stringtemp[i]<<endl;
	}
	file2.close();
	}
}
void stats::readFromFile() {
	ifstream file;
	file.open("score.txt");
	if (!file.is_open())
		cout << "Unable to open file to read" << endl;
	string score1[3] = { "" };
	string scoret[3] = { "" };
	for (int i = 0; i < 3; i++) {
		readScore1[i] = "";
		readScore2[i] = "";
	}
	int count = 0;
	for (; count < 3; count++) {
		getline(file, score1[count]);
		//	cout << "Length of this line : " << score1[count].length() << endl;
		if (score1[count].length() != 0)
			scoret[count] = score1[count];
	}
//	cout << endl << endl << "Scoret[k]" << endl;
	for (int k = 0; k < count; k++) {
		for (int i = 0; i < scoret[k].length(); i++) {
			if (scoret[k][i] == '-') {
				for (int j = 0; j < i; j++) {
					readScore1[k] += scoret[k][j];
				}
		//		cout << readScore1[k] << "|" << endl;
				for (int j = i + 1; j < scoret[k].length() - 1; j++) {
					readScore2[k] += scoret[k][j];
				}
	//			cout << readScore2[k] << "|" << endl;
			}
		}
	}
	//cout << endl << endl;
	for (int i = 0; i < 3; i++) {
	//	cout << "Score team 1: " << readScore1[i] << endl;
		//cout << "Score Team 2: " << readScore2[i] << endl;
	}

	file.close();
}
void stats::setCurrentScreen(int currentScreen) {
	this->currentScreen = currentScreen;
}

int stats::getReadWritePermission() const {
	return readWritePermission;
}

int stats::getMenueOption() const {
	return menueOption;
}

void stats::menueOptionReduce() {

	this->menueOption = menueOption - 1;
	if (menueOption <= 0)
		menueOption = 4;

}

int stats::getReadWritePermission2() const {
	return readWritePermission2;
}

void stats::setReadWritePermission2(int readWritePermission2) {
	this->readWritePermission2 = readWritePermission2;
}

void stats::menueOptionIncrement() {
	this->menueOption = menueOption + 1;
	if (menueOption > 4)
		menueOption = 1;
}

void stats::setReadWritePermission(int readWritePermission) {
	this->readWritePermission = readWritePermission;
}

int stats::getNoResult() const {
	return noResult;
}

void stats::setNoResult(int noResult) {
	this->noResult = noResult;
}

int stats::getStartMusic() const {
	return startMusic;
}

void stats::setStartMusic(int startMusic) {
	this->startMusic = startMusic;
}

void stats::setMenueOption(int menueOption) {
	this->menueOption = menueOption;
}
