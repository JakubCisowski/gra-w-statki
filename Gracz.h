#pragma once
#include "Listy.h"
#include <iostream>
using namespace std;

class Gracz
{
private:
	int idGracza; // Id gracza - 0 to komputer, 1 to gracz
	StatekGracza* pHeadStatek; // Lista jednokierunkowa statkow gracza
	Strzal* pHeadStrzal; // Lista jednokierunkowa strzalow gracza
public:
	// Konstruktor
	Gracz(int id);

	// Destruktor
	~Gracz();

	// Dodaje statek do listy statkow gracza
	void dodajStatek(Statek* statek);

	// Dodaje strzal do listy strzalow gracza
	void dodajStrzal(std::string strzal);

	// Sprawdza czy gracz strzelil w dana koordynate
	bool czyGraczStrzelil(std::string koor);

	// Sprawdza czy gracz posiada statek na danej koordynacie
	bool czyGraczMaTuStatek(std::string koor);

	// Sprawdza czy strzal jest unikalny i poprawny
	bool sprawdzStrzal(std::string koor);

	// Sprawdza czy gracz przegral
	bool czyGraczPrzegral(Gracz* przeciwnik);

	// Operator wypisania strzalow gracza
	friend ostream& operator<<(ostream& out, Gracz* gracz);
};
