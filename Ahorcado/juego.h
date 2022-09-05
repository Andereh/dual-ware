#define JUEGO_H
#include <iostream>

using namespace std;

class Player
{
public:
	Player(string); // constructor de clase
	bool wantToContinue();

	string getName();

	void addStreak();
	int getStreak();

	void getWins();
	void addVictory();

private:
	string name;
	int streak;
	int wins;
};

class Tablero
{
public:
	Tablero(); // constructor de clase
	void showGame();
	void displayWarnings();
	void attempLetter(string);
	int theGameIsOver();

private:
	void init();
	string choseWord();

	string warnings;
	string words[4] = {"carpincho", "capibara", "patilla", "sarten"};
	// luego lo hago para que use un archivo externo
	string actualWord;
	string unknownWord;
	string lettersUse;
	int lives;
};

