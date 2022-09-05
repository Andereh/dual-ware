#include <cstdio>
#include <iostream>
#include "juego.h"

using namespace std;


int main(int argc, char *argv[])
{
	Tablero tablero;
	Player player;
	string userName;
	string letter;


	system("clear");
	cout << "Antes de comenzar deberias darme tu nombre\n";
	cout << "Tu nombre es: ";
	cin >> userName;

	player.setName(userName);

	do 
	{

		tablero.start();
		while (!tablero.theGameIsOver()) // main loop
		{
			system("clear");
			cout << " Vamos " << player.getName() << " tu puedes\n\n";
			tablero.showGame();
			tablero.displayWarnings();

			cout << " Intente una letra: \033[3m"; // setteamos la fuente italica
			cin >> letter;
			cout << "\033[0m"; // la quitamos xD

			tablero.attempLetter(letter);
		}

		system("clear");



		if (tablero.theGameIsOver() == 1)
		{
			player.addVictory();
			cout << " Lo sabia " << player.getName() << " SABIA QUE GANARIAS\n\n";
		}
		else 
		{
			player.resetStreak();
			cout << " COMO QUE PERDISTE!? PATAN!\n\n";
		}


		tablero.showGame();

		cout << "\n Partidas jugadas: " << player.getGamesPlayed() << "\n";
		cout << "\n Victorias: " << player.getWins();
		cout << "\n Racha actual: " << player.getStreak();
		cout << "\n Win rate: " << player.getWins() / (float)player.getGamesPlayed() * 100 << "%\n";

	} while (player.wantToContinue());

	cout << " Has terminado el juego con " << player.getWins() << " victorias\n";
	return 0;
}

