#include<iostream>

using namespace std;

class Punkt
{
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




////////////////////////////////////////////////////////////////////
class Tablica
{
	Punkt * w;
	int dl; // dlugoœæ Tablicy
public:
	Tablica(int dl = 0); // tworzy Tablice o zadanej d³ugoœci i wype³nia punktami (0,0)
	Tablica(Tablica &w_); //inicjalizacja za pomoc¹ Tablicy w_
	Tablica(float *x, float *y, int dl); // inicjalizacja tablicy punktów tablicami x -ów i y -ów

	~Tablica();

	void dodaj(Tablica &w_);// dodaje do siebie Tablice w_

	bool porownaj(Tablica &w);// porownnaie z Tablica w_;

	void drukuj();
	
};

Tablica::Tablica(int dl){
	if (dl <= 0) {
		cout << "Klasa nie stworzona, dlugosc nie moze byc ujemna"<<endl;
	}
	else {
		this->dl = dl;
		w = new Punkt[dl];
	}
}

Tablica::Tablica(Tablica &w_) {

	if (w_.dl < 0) cout << "Klasa nie stworzona, dlugosc nie moze byc ujemna";
	else {
		dl = w_.dl;

		w = new Punkt[w_.dl];
		for (int i = 0; i < dl; ++i) {
			w[i] = w_.w[i];
		}
	}
}

Tablica::Tablica(float *x, float *y, int dl) { 
	this->dl = dl;
	w = new Punkt[dl];
	for (int i = 0; i < dl; ++i) {
		Punkt punkt(x[i], y[i]);
		w[i] = punkt;
	}
}

Tablica::~Tablica() {
	delete w;
	w = nullptr;
}

void Tablica::dodaj(Tablica &w_) {
	if (dl == w_.dl) {
		for (int i = 0; i < dl; ++i) {
			w[i].setX(w[i].getX() + w_.w[i].getX());
			w[i].setY(w[i].getY() + w_.w[i].getY());
		}
	}
	else {
		cout << "Tablice musza byc rownej dlugosci"<<endl;
	}

}

bool Tablica::porownaj(Tablica &w) {
	if (dl == w.dl) {
		for (int i = 0; i < dl; ++i) {
			if (this->w[i].getX() != w.w[i].getX()) return false;
			if (this->w[i].getY() != w.w[i].getY()) return false;
		}
	} else {
		return false;
	}
	return true;
}


void Tablica::drukuj() {
	for (int i = 0; i < dl; ++i) {
		cout << "x: " << w[i].getX() << " y: " << w[i].getY();
		cout << endl;
	}
}





int main() {

	// kod ktory sprawdza czy metody z zadania 1. dzia³aj¹
	Punkt a, b(1,3), c(8,4);
	a.drukuj();
	b.drukuj();
	c.drukuj();
	Punkt d(b);
	d.drukuj();
	b.dodaj(c);
	c.dodaj(d);
	b.drukuj();
	c.drukuj();
	Punkt *p;
	p = &d;
	p->dodaj(d);
	p->drukuj();

	cout << "Sprawdzenie statyczne" << endl;
	d.drukuj();

	a.dodaj(p);
	a.drukuj();

	cout << "=== Zad 2 ===" << endl << endl;
	Tablica tablica(5), tab0;
	cout << "Tablica zer: "<<endl;
	tablica.drukuj();
	tab0.drukuj();
	cout << endl;

	float *x = new float[5];
	float *y = new float[5];
	x[0] = 5;
	x[1] = 4;
	x[2] = 6;
	x[3] = -2;
	x[4] = -8;
	y[0] = -7;
	y[1] = 2;
	y[2] = 4;
	y[3] = 7;
	y[4] = 4;
	Tablica tab(x, y, 5);
	tab.drukuj();
	float *x1 = new float[3];
	float *x2 = new float[3];
	float *y1 = new float[3];
	float *y2 = new float[3];
	
	x1[0] = 4;
	x1[1] = 6;
	x1[2] = -3;
	x2[0] = 1;
	x2[1] = 3;
	x2[2] = 2;
	y1[0] = -5;
	y1[1] = -7;
	y1[2] = 8;
	y2[0] = -4;
	y2[1] = -12;
	y2[2] = 99;


	Tablica tab1(x1, y1, 3), tab2(x2, y2, 3);
	cout << "tab1: "<<endl;
	tab1.drukuj();
	cout << "tab2: "<<endl;
	tab2.drukuj();


	tab1.dodaj(tab2);
	cout << "Suma tablic tab1 i tab2: " << endl;
	tab1.drukuj();

	Tablica tab3(tab1);
	cout << "tab3: " << endl;
	tab3.drukuj();

	cout<<"Czy tab3 i  tab1 sa rowne? bool: " <<tab3.porownaj(tab1)<<endl;
	cout << "Czy tab3 i tab2 sa rowne? bool: " << tab3.porownaj(tab2);
	delete x, y, x1, x2, y1, y2;
	x = nullptr;
	y = nullptr;
	x1 = nullptr;
	x2 = nullptr;
	y1 = nullptr;
	y2 = nullptr;


	return 0;
}