#pragma once

#ifndef Postacie_h
#define Postacie_h


struct Postac {

	std::string nazwa;
	std::string odpowiedzi[13] = {};

	int LosowaniePostaci();

	void PobierzDaneZPliku(int numerPostaci);

	void Odpowiedz(int numer);

	bool SprawdzNazwe(std::string wpisanaNazwa);

};


#endif
