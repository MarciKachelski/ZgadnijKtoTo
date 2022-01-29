#pragma once


#ifndef Rozgrywka_h
#define Rozgrywka_h


struct Rozgrywka
{
	std::string pytania[13];
	std::string postacie[20];



	void PobierzPytaniaZPliku();

	void PobierzPostacieZPliku();

	void WyswietlPytania();

	void WyswietlPostacie();

	bool SprawdzCzyIstnieje(std::string szukanaPostac);

};

#endif