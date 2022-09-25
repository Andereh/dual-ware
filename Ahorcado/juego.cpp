#include "juego.h"
#include <cstdlib>
#include <time.h>

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

Player::Player() 
{
	wins = 0;
	streak = 0;
	gamesPlayed = 0;
}

string Player::getRandMsg()
{
	string msgs[5] = 
	{
		"No creo que seas capaz de dejarme solo",
		"Ehhh pero que bueno es pasar tiempo contigo",
		"Oye no lo haces tan mal ehh",
		"Puff, que bueno eres conversando",
		"Si no traes cafe es mejor que no te vuelva a ver"
	};

	srand(time(NULL));
	int randVal = rand() % 5;
	return msgs[randVal];
}


bool Player::wantToContinue()
{
	string msg = getRandMsg();
	string opt;

	cout << "\n " << msg;
	cout << "\n\n Continuar? (Si == s / No == n): ";
	cin >> opt;

	return opt[0] == 's' || opt[0] == 'S';
}

string Player::getName() 
{
	return name;
}

void Player::setName(string _name)
{
	if (_name[0] >= 'a' && _name[0] <= 'z')
		_name[0] -= 32;
	name = _name;
}


void Player::resetStreak()
{
	gamesPlayed++;
	streak = 0;
}

int Player::getStreak()
{
	return streak;
}


int Player::getWins()
{
	return wins;
}

void Player::addVictory()
{
	wins++;
	streak++;
	gamesPlayed++;
}

int Player::getGamesPlayed()
{
	return gamesPlayed;
}


Tablero::Tablero() 
{
	lettersUse = " ";
}

void Tablero::start()
{
	srand(time(NULL));
	int randVal = rand() % 4;

	lives = 7;
	actualWord = words[randVal];
	lettersUse = " ";
	unknownWord = "";


	for (int i = 0; i < actualWord.size(); ++i) 
	{
		actualWord[i] -= 32; // convertimos sus letras a mayus
		unknownWord += "-";
	}
}


void Tablero::showGame()
{
	cout << " Vidas: ";
	short index = 7 - lives;

	cout << "<";
	for (int i = 0; i < 7; ++i) 
	{
		if (i < lives)
		{
			if (lives < 3)
				cout << "\033[1;31m"; // verde
			else if (lives < 4)
				cout << "\033[1;33m"; // verde
			else 
				cout << "\033[1;32m"; // verde
			cout << "==";
		}
		else 
			cout << "  ";
	}
	cout << "\033[0m>\n" ;

	cout << images[index > 6 ? 6 : index] << '\n';

	if (index == 7)
		cout << " \033[31m" << actualWord << "\033[0m\n";
	else
		cout << " " << unknownWord << '\n';
}

void Tablero::displayWarnings()
{
	if (warnings == "")
		cout << "\n";
	cout << "\033[1;33m\n " << warnings << "\033[0m" << '\n';
	warnings = "";
}

void Tablero::attempLetter(string str)
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

int Tablero::theGameIsOver()
{
	if (actualWord == unknownWord)
		return 1; // si acertaste la palabra
	if (lives < 1)
		return -1; // si te quedaste sin vidas

	return 0; // si no ha pasado nada
}

