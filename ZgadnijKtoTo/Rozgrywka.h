//Struktura s³u¿¹ca do przechowywania i obs³ugi informacji o dostepnych pytaniach i postaciach.

#pragma once


#ifndef Rozgrywka_h
#define Rozgrywka_h


struct Rozgrywka
{
	std::string pytania[12];
	std::string postacie[16];

	int iloscPytan = 12;
	int iloscPostaci = 16;

	void PobierzPytaniaZPliku();

	void PobierzPostacieZPliku();

	void WyswietlPytania();

	void WyswietlPostacie();

	bool SprawdzCzyIstnieje(std::string szukanaPostac);

};

#endif