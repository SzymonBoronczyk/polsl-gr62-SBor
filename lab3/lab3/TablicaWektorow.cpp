#include"TablicaWektorów.h"

TablicaWektorow::TablicaWektorow(int dlugosc) {
	if (dlugosc < 0) {
		cout << "Tablica wektorow nie stworzona, ujemna dlugosc" << endl;
	}
	else {
		this->dlugosc = dlugosc;
		key = new Wektor[dlugosc];
	}

}

TablicaWektorow::TablicaWektorow(TablicaWektorow &tablicaWektorow) {
	this->dlugosc = tablicaWektorow.dlugosc;
	key = new Wektor[this->dlugosc];
	for (int i = 0; i < dlugosc; ++i) {
		this->key[i] = Wektor(tablicaWektorow.key[i].getX(),
			tablicaWektorow.key[i].getY());
	}
}

TablicaWektorow::TablicaWektorow(Wektor *key, int dlugosc) {
	this->dlugosc = dlugosc;
	this->key = new Wektor[this->dlugosc];
	for (int i = 0; i < dlugosc; ++i) {
		this->key[i] = Wektor(key[i].getX(), key[i].getY());
	}
}

TablicaWektorow::~TablicaWektorow() {
	delete key;
	key = nullptr;
}

void TablicaWektorow::dodaj(TablicaWektorow &tablicaWektorow) {
	if (this->dlugosc == tablicaWektorow.dlugosc) {
		for (int i = 0; i < this->dlugosc; ++i) {
			this->key[i].dodaj(tablicaWektorow.key[i]);
		}
	}
	else {
		cout << "Tablice roznej dlugosci!" << endl;
	}
}

bool TablicaWektorow::porownaj(TablicaWektorow &tablicaWektorow) {
	if (this->dlugosc == tablicaWektorow.dlugosc) {
		for (int i = 0; i < this->dlugosc; ++i) {
			if (!this->key[i].porownaj(tablicaWektorow.key[i])) return false;
		}
		return true;
	}	return false;
}

void TablicaWektorow::drukuj() {
	for (int i = 0; i < this->dlugosc; ++i) {
		cout << "Wektor " << i << ": x = " << this->key[i].getX() << " y = "
			<< this->key[i].getY() << " dlugosc = " << this->key[i].getDlugosc()
			<< " kierunek = " << this->key[i].getKierunek();
	}
}