#pragma once
#include<iostream>


using namespace std;

class Punkt {
	float x;
	float y;
public:
	Punkt(Punkt &p);
	Punkt(float x_ = 0, float y_ = 0);
	void dodaj(Punkt &p);//dodaje do siebie wsp�rz�dne punktu p (dodawanie wektor�w w przestrzeni 2d )
	void dodaj(Punkt *p);
	void drukuj();// drukuje swoje wsp�rz�dne

	float getX();	// dodalem getery i setery aby m�c si� dosta� do zmiennych x i y
	float getY();
	void setX(float x);
	void setY(float y);

};