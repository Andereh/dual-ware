#define JUEGO_H
#include <iostream>

using namespace std;

class Player
{
public:
	Player();
	bool wantToContinue();

	string getName();
	void setName(string);

	void resetStreak();
	int getStreak();

	int getWins();
	void addVictory();

	int getGamesPlayed();

private:
	string name;
	int streak;
	int wins;
	int gamesPlayed;
	string getRandMsg();
};

class Tablero
{
public:
	Tablero(); // constructor de clase
	void start();
	void showGame();
	void displayWarnings();
	void attempLetter(string);
	int theGameIsOver();

private:
	string choseWord();

	string warnings;
	string words[4] = {"carpincho", "capibara", "patilla", "sarten"};
	// luego lo hago para que use un archivo externo
	string actualWord;
	string unknownWord;
	string lettersUse;
	int lives;
};

