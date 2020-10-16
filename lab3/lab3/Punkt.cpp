#include"Punkt.h"



Punkt::Punkt(Punkt &p) {
	x = p.x;
	y = p.y;
}

Punkt::Punkt(float x_, float y_) {
	x = x_;
	y = y_;
}

void Punkt::dodaj(Punkt &p) {
	x += p.x;
	y += p.y;
}

void Punkt::dodaj(Punkt *p) {
	x += p->x;
	y += p->y;
}

void Punkt::drukuj() {
	cout << "Wspolzedne punktu: x: " << x << " y: " << y << endl;
}

float Punkt::getX() {
	return x;
}

float Punkt::getY() {
	return y;
}

void Punkt::setX(float x) {
	this->x = x;
}

void Punkt::setY(float y) {
	this->y = y;
}

