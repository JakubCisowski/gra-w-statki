#pragma once
#include "Gracz.h"

class Operacje
{
public:
	// Wyswietla plansze strzalow uzytkownika
	static void wyswietlStrzalyUzytkownika(Gracz* uzytkownik, Gracz* komputer);

	// Wyswietl plansze statkow uzytkownika
	static void wyswietlStatkiUzytkownika(Gracz* uzytkownik, Gracz* komputer);

	// Generuje plansze statkow uztykownika
	static bool generujStatkiUzytkownika(Gracz* uzytkownik);

	// Generuje plansze statkow komputera
	static void generujStatkiKomputera(Gracz* komputer);

	// Generuje strzal komputera
	static std::string generujStrzalKomputera(Gracz* komputer);

	// Symuluje przebieg rozgrywki
	static void graj(Gracz* uzytkownik, Gracz* komputer);
};
