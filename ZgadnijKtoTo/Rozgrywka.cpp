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
		for (int i = 0; i <= 12; i++)
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
		for (int i = 0; i <= 20; i++)
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
	for (int i = 0; i < 13; i++)
	{
		cout << pytania[i] << endl;
	}
}

void Rozgrywka::WyswietlPostacie()
{
	cout << endl << endl << "#################  POSTACIE  ####################" << endl << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << postacie[i] << endl;
	}
}

bool Rozgrywka::SprawdzCzyIstnieje(string szukanaPostac)
{
	for (int i = 0; i < 20; i++) 
	{
		if (szukanaPostac == postacie[i]) {
			return true;
		}
	}


	return false;

}
