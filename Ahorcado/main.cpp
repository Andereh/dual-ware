#include <iostream>
#include "juego.h"

using namespace std;

int main(int argc, char *argv[])
{
	Juego juego;
	std::string str;

	while (!juego.theGameIsOver()) 
	{
		juego.showGame();
		juego.displayWarnings();
		cout << " Intente una letra: \033[3m"; // setteamos a italica
		cin >> str;
		cout << "\033[0m"; // la quitamos
		juego.attempLetter(str);
	}

	if (juego.theGameIsOver() == 1)
		cout << " Cooonchale vale pero este muchacho sabe mas que pescao frito\n";
	else 
	{
		cout << " Verga hermano, tenias que metele mas ganas\n";
	}


	return 0;
}

