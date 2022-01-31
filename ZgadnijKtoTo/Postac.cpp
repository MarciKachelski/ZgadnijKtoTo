//Struktura s³u¿¹ca do przechowywania i obs³ugi informacji na temat szukanej postaci.

#include <iostream>
#include <fstream>
#include <string>
#include "Postac.h"

using namespace std;

//Losuje jedn¹ z szesnastu postaci

int Postac::LosowaniePostaci()
{
	int numer;
	srand(time(NULL));
	numer = rand() % 16 + 1;
	return numer;
}

//Pobiera z pliku tekstowego wylosowanej postaci odpowiedzi na pytania oraz jej nazwe. 

void Postac::PobierzDaneZPliku(int numerPostaci)
{
	fstream plik;
	string linia;
	plik.open("Postac" + to_string(numerPostaci) + ".txt", ios::in);
	if (plik.good() == true)
	{
		getline(plik, linia);
		nazwa = linia;
		for (int i = 0; i < iloscOdpowiedzi; i++)
		{
			if (!plik.eof())
			{
				getline(plik, linia);
				odpowiedzi[i] = linia;
			}
		}

		plik.close();
	}

}

//Wypisuje odpowiedŸ a zadane pytanie.

void Postac::Odpowiedz(int numer)
{
	cout << endl << "Odpowiedz to: " << endl;
	cout << odpowiedzi[numer - 1] << endl << endl;
}

//Sprawdza czy wpisana odpowiedŸ jest prawid³owa.

bool Postac::SprawdzNazwe(string wpisanaNazwa)
{
	if(wpisanaNazwa==nazwa)
	{
		return true;
	}
	return false;
}
