#include <iostream>
#include <string>
#include "Rozgrywka.h"
#include "Postac.h"

using namespace std;


bool SprawdzCzyToLiczba(string wpisanaWartosc) 
{
	for (int i = 0; i < wpisanaWartosc.size(); i++)
	{
		if (wpisanaWartosc[i] < 48 || wpisanaWartosc[i] > 57)
		{
			return false;
		}
	}
	return true;
}

void ZmienNaDuzaLitera(string &_pytanie) {

	if (_pytanie[0] > 96 && _pytanie[0] < 123) {
		_pytanie[0] = _pytanie[0] - 32;
	}
}

void WyczyscKonsole(Rozgrywka _rozgrywka) {
	system("cls");
	_rozgrywka.WyswietlPytania();
	_rozgrywka.WyswietlPostacie();
}

void ZadajPytanie(Postac postac, Rozgrywka rozgrywka, bool &_czyKoniec,int &_punkty) {

	string pytanie;
	cout << endl << "Podaj nr pytania lub wpisz odzpowiedz/wynik:  " << endl << endl;
	cin >> pytanie;
	ZmienNaDuzaLitera(pytanie);
	WyczyscKonsole(rozgrywka);

	if (SprawdzCzyToLiczba(pytanie) == true) {
		if (stoi(pytanie) > 0 && stoi(pytanie) < 14) {

			postac.Odpowiedz(stoi(pytanie));
			_punkty++;

		}
		else {
			cout << endl << "Nie ma pytanie o takim numerze." << endl << endl;
		}
	}
	else 
	{
		
		if (rozgrywka.SprawdzCzyIstnieje(pytanie) == true) 
		{
			
			if (postac.SprawdzNazwe(pytanie) == true)
			{
				_czyKoniec = true;
				cout << endl << "Udalo ci sie. Twoje punkty to: "<< _punkty << endl << endl;
			}
			else
			{
				cout << endl << "Zla odpowiedz." << endl << endl;
				_punkty++;
			}
		}
		else {
			cout << endl << "Wprowadzono bledne dane.Nie ma takiego numeru pytania ani postaci." << endl << endl;
		}
	}
}


int main()
{
	string nick;
	Postac postac;
	int punkty = 0;
	Rozgrywka rozgrywka;
	bool czyKoniec = false;



	cout << "Zgadnij Kto To?" << endl << endl << endl;
	cout << " Wpisz poprawnie szukana postac sposrod dostepnych.\n Do osiagniecia tego mozesz zadawac wyswietlone pytania.\n Po wpisaniu numeru pytania i klinieciu ENTER, wyswietli sie odpowiedz TAK, badz NIE.\n W kazdym momencie mozesz probowac zgadnac postac, poprzez wpisanie jego pseudonimu.\n Czym mniej zadales pytan tym lepiej.\n POWODZENIA !" << endl;
	cout << endl << "Wpisz nick i kliknij ENTER by rozpoczac gre: " << endl << endl << endl;
	cin >> nick;

	
	
	postac.PobierzDaneZPliku(postac.LosowaniePostaci());

	rozgrywka.PobierzPostacieZPliku();
	rozgrywka.PobierzPytaniaZPliku();

	rozgrywka.WyswietlPytania();
	rozgrywka.WyswietlPostacie();

	while (czyKoniec == false) 
	{
		
		ZadajPytanie(postac, rozgrywka, czyKoniec, punkty);
	}


	return 0;
}
