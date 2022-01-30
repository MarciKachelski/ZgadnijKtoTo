#include <iostream>
#include <fstream>
#include <string>
#include "Postac.h"

using namespace std;

int Postac::LosowaniePostaci()
{
	int numer;
	srand(time(NULL));
	numer = rand() % 16 + 1;
	return numer;
}

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

void Postac::Odpowiedz(int numer)
{
	cout << endl << "Odpowiedz to: " << endl;
	cout << odpowiedzi[numer - 1] << endl << endl;
}

bool Postac::SprawdzNazwe(string wpisanaNazwa)
{
	if(wpisanaNazwa==nazwa)
	{
		return true;
	}
	return false;
}
