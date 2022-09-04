#define JUEGO_H
#include <iostream>

using namespace std;

class Juego
{
public:
	Juego ();
	void showGame();
	void displayWarnings();
	void attempLetter(string);
	int theGameIsOver();

private:
	string choseWord();
	void update();
	void init();

	string warnings;
	string words[3] = {"carpincho", "capibara"};
	string actualWord;
	string unknownWord;
	string lettersUse;
	int lives;
};
