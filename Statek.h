#pragma once
#include "Koordynata.h"

class Statek
{
private:
	int idWlasciciela; // Id wlasciciela statku - 0 to komputer, 1 to gracz
	Koordynata* pHeadKoordynata = nullptr; // Lista jednokierunkowa koordynatow polozenia
public:
	// Destruktor
	~Statek();

	// Ustawia id gracza do ktorego nalezy statek
	void setID(int id);

	// Dodaje koordynate do statku
	void dodajKoordynate(std::string koor);

	// Sprawdza czy statek zawiera koordynate
	bool czyZawieraKoordynate(std::string koor);

	// Zwraca koordynaty
	Koordynata* getKoordynata();
};
