//Struktura s³u¿¹ca do przechowywania i obs³ugi informacji o dostepnych pytaniach i postaciach.

#include <iostream>
#include <fstream>
#include <string>
#include "Rozgrywka.h"

using namespace std;

//Pobiera z pliku tekstowego pytania.

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

//Pobiera z pliku tekstowego nazwy postaci. 

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

//Wyœwietla w oknie konsoli dostêpne pytania. 

void Rozgrywka::WyswietlPytania()
{
	cout << endl << endl << "#################  PYTANIA  ####################" << endl << endl;
	for (int i = 0; i < iloscPytan; i++)
	{
		cout << pytania[i] << endl;
	}
}

//Wyœwietla w oknie konsoli dostêpne postacie. 

void Rozgrywka::WyswietlPostacie()
{
	cout << endl << endl << "#################  POSTACIE  ####################" << endl << endl;
	for (int i = 0; i < iloscPostaci; i++)
	{
		cout << postacie[i] << endl;
	}
}

//Sprawdza czy wpisana przez u¿ytkownika nazwa postaci istnieje. 

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
