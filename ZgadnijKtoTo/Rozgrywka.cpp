#include <iostream>
#include <fstream>
#include <string>
#include "Rozgrywka.h"

using namespace std;

void Rozgrywka::PobierzPytaniaZPliku()
{
	fstream plik;
	string linia;
	plik.open("Pytania.txt", ios::in);
	if (plik.good() == true)
	{
		for (int i = 0; i < iloscPytan; i++)
		{
			if (!plik.eof())
			{
				getline(plik, linia);
				pytania[i] = linia;
			}
		}

		plik.close();
	}
}

void Rozgrywka::PobierzPostacieZPliku()
{
	fstream plik;
	string linia;
	plik.open("Postacie.txt", ios::in);
	if (plik.good() == true)
	{
		for (int i = 0; i < iloscPostaci; i++)
		{
			if (!plik.eof())
			{
				getline(plik, linia);
				postacie[i] = linia;
			}
		}

		plik.close();
	}
}

void Rozgrywka::WyswietlPytania()
{
	cout << endl << endl << "#################  PYTANIA  ####################" << endl << endl;
	for (int i = 0; i < iloscPytan; i++)
	{
		cout << pytania[i] << endl;
	}
}

void Rozgrywka::WyswietlPostacie()
{
	cout << endl << endl << "#################  POSTACIE  ####################" << endl << endl;
	for (int i = 0; i < iloscPostaci; i++)
	{
		cout << postacie[i] << endl;
	}
}

bool Rozgrywka::SprawdzCzyIstnieje(string szukanaPostac)
{
	for (int i = 0; i < iloscPostaci; i++)
	{
		if (szukanaPostac == postacie[i]) {
			return true;
		}
	}


	return false;

}
