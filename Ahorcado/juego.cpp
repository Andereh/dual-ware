#include "juego.h"
#include <cstdlib>

using namespace std;

string images[7] = {
"   +---+\n"
"   |   |\n"
"       |\n"
"       |\n"
"       |\n"
"       |\n"
" ========="
,

"   +---+\n"
"   |   |\n"
"   O   |\n"
"       |\n"
"       |\n"
"       |\n"
" ========="
,

"   +---+\n"
"   |   |\n"
"   O   |\n"
"   |   |\n"
"       |\n"
"       |\n"
" ========="
,

"   +---+\n"
"   |   |\n"
"   O   |\n"
"  /|   |\n"
"       |\n"
"       |\n"
" ========="
,

"   +---+\n"
"   |   |\n"
"   O   |\n"
"  /|\\  |\n"
"       |\n"
"       |\n"
" ========="
,

"   +---+\n"
"   |   |\n"
"   O   |\n"
"  /|\\  |\n"
"  /    |\n"
"       |\n"
" ========="
,

"   +---+\n"
"   |   |\n"
"   O   |\n"
"  /|\\  |\n"
"  / \\  |\n"
"       |\n"
" ========="
};

Juego::Juego() {
	init();
	lettersUse = " ";
}

void Juego::init()
{
	int randVal = rand() % words->size();
	actualWord = words[randVal];
	lives = 7;


	for (int i = 0; i < actualWord.size(); ++i) 
	{
		actualWord[i] -= 32; // convertimos sus letras a mayus
		unknownWord += "-";
	}
}


void Juego::showGame()
{
	system("clear");
	cout << " Vidas: ";

	if (lives <= 3)
		cout << "\033[1;5;31m" << lives << "\033[0m\n" ; // rojo
	else
		cout << "\033[1;32m" << lives << "\033[0m\n" ; // verde

	cout << images[7 - lives] << '\n';
	cout << " " << unknownWord << '\n';
}

void Juego::displayWarnings()
{
	if (warnings == "")
		cout << "\n";
	cout << "\033[1;33m\n " << warnings << "\033[0m" << '\n';
	warnings = "";
}

void Juego::attempLetter(string str)
{
	if (str.size() > 1) 
	{
		warnings = "Solo debes insertar UN caracter\n";
		return;
	}

	char ch = str[0];
	bool youHitALetter = false; // nombre bien klero


	if (ch >= 'a' && ch <= 'z')
		ch -= 32; // pasamos a mayusculas

	if (ch < 'A' || ch > 'Z')
	{
		warnings = "Parece que nos has introducido un caracter\n";
		return;
	}

	for (int i = 0; i < lettersUse.size(); ++i) 
	{
		if (lettersUse[i] == ch)
		{
			warnings = "Ya has usado esa letra papu\n";
			return;
		}
	}

	lettersUse += ch;

	for (int i = 0; i < actualWord.size(); ++i) 
	{
		if (ch == actualWord[i])
		{
			unknownWord[i] = ch;
			youHitALetter = true;
		}

	}


	if (!youHitALetter) // si no le atinaste a una letra
		lives--;
}

int Juego::theGameIsOver()
{
	if (actualWord == unknownWord)
		return 1; // si acertaste la palabra
	if (lives < 1)
		return -1; // si te quedaste sin vidas

	return 0; // si no ha pasado nada
}

