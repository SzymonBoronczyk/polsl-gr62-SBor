#pragma once
#include"Wektor.h"



class TablicaWektorow {
	Wektor *key;
	int dlugosc;
public:
	TablicaWektorow(int dlugosc);
	TablicaWektorow(TablicaWektorow &tablicaWektorow);
	TablicaWektorow(Wektor *key, int dlugosc);

	~TablicaWektorow();

	void dodaj(TablicaWektorow &tablicaWektorow);
	bool porownaj(TablicaWektorow &tablicaWektorow);
	void drukuj();

};