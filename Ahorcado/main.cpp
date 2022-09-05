#include <iostream>
#include "juego.h"

using namespace std;

bool wantToContinue()
{
	string message[] = {"Sabes? Me gusta pasar tiempo contigo", 
						"Ehhhh casi la adivinas, no te rindas carajo"};
	cout << "\n\n";

	return false;
}


int main(int argc, char *argv[])
{
	Tablero tablero;
	std::string str;

	do {

	while (!tablero.theGameIsOver()) 
	{
		tablero.showGame();
		tablero.displayWarnings();

		cout << " Intente una letra: \033[3m"; // setteamos la fuente italica
		cin >> str;
		cout << "\033[0m"; // la quitamos xD

		tablero.attempLetter(str);
	}

	system("clear");

	tablero.showGame();
	if (tablero.theGameIsOver() == 1)
		cout << " Cooonchale vale pero este muchacho sabe mas que pescao frito\n";
	else 
		cout << " Verga hermano, tenias que metele mas ganas\n";

	} while (wantToContinue();)
	return 0;
}

