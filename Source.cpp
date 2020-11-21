#include <iostream>
#include "Statek.h"
#include "Gracz.h"
#include "Operacje.h"
#include "Pieciomasztowiec.h"
using namespace std;

int main()
{
	// Tworzenie obiektow graczy
	Gracz* uzytkownik = new Gracz(1);
	Gracz* komputer = new Gracz(0);

	cout << "GRA W STATKI" << endl;
	cout << "----------------------------" << endl;
	cout << "Wczytuje statki uzytkownika (z pliku \"Plansza.txt\")." << endl;
	if (Operacje::generujStatkiUzytkownika(uzytkownik) == false)
	{
		return 0;
	}

	cout << "Generuje statki komputera." << endl;
	Operacje::generujStatkiKomputera(komputer);

	cout << "----------------------------" << endl;
	cout << "Aby kontyunuowac rozgrywke wcisnij jakikolwiek klawisz." << endl;

	Operacje::graj(uzytkownik, komputer);

	// Zwalnianie pamieci
	delete uzytkownik;
	delete komputer;

	return 0;
}