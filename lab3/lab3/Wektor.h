#pragma once
#include<iostream>
#include"Punkt.h"


using namespace std;

class Wektor :public Punkt{

	float dlugosc;
	float kierunek;

public:
	Wektor(Punkt &punkt, float x , float y);
	Wektor(float x = 0, float y = 0);

	void dodaj(Wektor &wektor);
	void dodaj(Wektor *wektor);
	bool porownaj(Wektor &wektor);

	float getDlugosc();
	float getKierunek();


};