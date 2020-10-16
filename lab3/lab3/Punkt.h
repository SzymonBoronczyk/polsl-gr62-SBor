#pragma once
#include<iostream>


using namespace std;

class Punkt {
	float x;
	float y;
public:
	Punkt(Punkt &p);
	Punkt(float x_ = 0, float y_ = 0);
	void dodaj(Punkt &p);//dodaje do siebie wspó³rzêdne punktu p (dodawanie wektorów w przestrzeni 2d )
	void dodaj(Punkt *p);
	void drukuj();// drukuje swoje wspó³rzêdne

	float getX();	// dodalem getery i setery aby móc siê dostaæ do zmiennych x i y
	float getY();
	void setX(float x);
	void setY(float y);

};