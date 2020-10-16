#include"Wektor.h"

Wektor::Wektor(Punkt &punkt, float x=0, float y=0) {
	setX(x);
	setY(y);
	dlugosc = sqrt(pow((x+punkt.getX()),2) + pow((y+punkt.getY()),2));
	kierunek = y / x;
}

Wektor::Wektor(float x , float y) {
	setX(x);
	setY(y);
	dlugosc = sqrt(x*x + y * y);
	kierunek = y / x;
}


void Wektor::dodaj(Wektor &wektor) {
	setX(getX() + wektor.getX());
	setY(getY() + wektor.getY());
	dlugosc = sqrt(getX()*getX() + getY() * getY());
	kierunek = getY() / getX();
}

void Wektor::dodaj(Wektor *wektor) {
	setX(getX() + wektor->getX());
	setY(getY() + wektor->getY());
	dlugosc = sqrt(getX()*getX() + getY() * getY());
	kierunek = getY() / getX();
}

bool Wektor::porownaj(Wektor &wektor) {
	if (this->getX() == wektor.getX() &&
		this->getY() == wektor.getY() &&
		this->getDlugosc() == wektor.getDlugosc() &&
		this->getKierunek() == wektor.getKierunek()) return true;
	return false;
}



float Wektor::getDlugosc() {
	return this->dlugosc;
}

float Wektor::getKierunek() {
	return this->kierunek;
}