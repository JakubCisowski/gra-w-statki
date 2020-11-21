#include "Gracz.h"
#include <iostream>

using namespace std;

Gracz::Gracz(int id)
{
	idGracza = id;
}

Gracz::~Gracz()
{
	while (pHeadStrzal)
	{
		auto p = pHeadStrzal->pNext;
		delete pHeadStrzal;
		pHeadStrzal = p;
	}

	while (pHeadStatek)
	{
		auto p = pHeadStatek->pNext;
		delete pHeadStatek->wartosc;
		delete pHeadStatek;
		pHeadStatek = p;
	}
}

void Gracz::dodajStatek(Statek* statek)
{
	if (pHeadStatek == nullptr)
	{
		pHeadStatek = new StatekGracza;
		pHeadStatek->wartosc = statek;
		pHeadStatek->pNext = nullptr;
	}
	else
	{
		StatekGracza* temp = pHeadStatek;
		while (temp->pNext != nullptr)
		{
			temp = temp->pNext;
		}
		temp->pNext = new StatekGracza;
		temp->pNext->wartosc = statek;
		temp->pNext->pNext = nullptr;
	}
}

void Gracz::dodajStrzal(std::string strzal)
{
	if (pHeadStrzal == nullptr)
	{
		pHeadStrzal = new Strzal;
		pHeadStrzal->wartosc = strzal;
		pHeadStrzal->pNext = nullptr;
	}
	else
	{
		Strzal* temp = pHeadStrzal;
		while (temp->pNext != nullptr)
		{
			temp = temp->pNext;
		}
		temp->pNext = new Strzal;
		temp->pNext->wartosc = strzal;
		temp->pNext->pNext = nullptr;
	}
}

bool Gracz::czyGraczStrzelil(std::string koor)
{
	Strzal* temp = pHeadStrzal;

	while (temp != nullptr)
	{
		if (temp->wartosc == koor)
		{
			return true;
		}
		temp = temp->pNext;
	}

	return false;
}

bool Gracz::czyGraczMaTuStatek(std::string koor)
{
	StatekGracza* temp = pHeadStatek;

	while (temp != nullptr)
	{
		if (temp->wartosc->czyZawieraKoordynate(koor))
		{
			return true;
		}

		temp = temp->pNext;
	}

	return false;
}

bool Gracz::sprawdzStrzal(std::string koor)
{
	// 1. Sprawdzenie czy strzal jest unikalny
	if (czyGraczStrzelil(koor))
	{
		std::cout << "Strzeliles juz w to pole! Prosze podac inne:" << std::endl;
		return false;
	}

	// 2. Sprawdzenie poprawnosci
	if (koor.size() == 3)
	{
		if (!((koor[0] == 'a' || koor[0] == 'b' || koor[0] == 'c' || koor[0] == 'd' || koor[0] == 'e' || koor[0] == 'f' ||
			koor[0] == 'g' || koor[0] == 'h' || koor[0] == 'i' || koor[0] == 'j') && koor[1] == '1' && koor[2] == '0'))
		{
			cout << "Niepoprawne pole, pamietaj o uzywaniu malych liter (a-j) oraz liczb (1-10) - na przyklad b4, c10." << endl;
			cout << "Prosze podac poprawne pole:" << endl;
			return false;
		}
	}
	else if (koor.size() == 2)
	{
		if (!((koor[0] == 'a' || koor[0] == 'b' || koor[0] == 'c' || koor[0] == 'd' || koor[0] == 'e' || koor[0] == 'f' ||
			koor[0] == 'g' || koor[0] == 'h' || koor[0] == 'i' || koor[0] == 'j') &&
			(koor[1] == '1' || koor[1] == '2' || koor[1] == '3' || koor[1] == '4' || koor[1] == '5' || koor[1] == '6' ||
				koor[1] == '7' || koor[1] == '8' || koor[1] == '9')))
		{
			cout << "Niepoprawne pole, pamietaj o uzywaniu malych liter (a-j) oraz liczb (1-10) - na przyklad b4, c10." << endl;
			cout << "Prosze podac poprawne pole:" << endl;
			return false;
		}
	}
	else
	{
		cout << "Niepoprawna dlugosc podanej koordynaty, pamietaj o uzywaniu malych liter (a-j) oraz liczb (1-10) - na przyklad b4, c10." << endl;
		cout << "Prosze podac poprawne pole:" << endl;
		return false;
	}

	return true;
}

bool Gracz::czyGraczPrzegral(Gracz* przeciwnik)
{
	StatekGracza* tempStatek = pHeadStatek;

	// Iterujemy sie przez statki gracza
	while (tempStatek != nullptr)
	{
		Koordynata* tempKoordynata = tempStatek->wartosc->getKoordynata();

		// Iterujemy sie przez koordynaty danego statku
		while (tempKoordynata != nullptr)
		{
			// I sprawdzamy czy sa zawarte w strzalach przeciwnika
			if (!(przeciwnik->czyGraczStrzelil(tempKoordynata->wartosc)))
			{
				// Nie strzelil, wiec gracz nie przegral
				return false;
			}

			tempKoordynata = tempKoordynata->pNext;
		}

		tempStatek = tempStatek->pNext;
	}

	return true;
}

ostream& operator<<(ostream& out, Gracz* gracz)
{
	if (gracz->pHeadStrzal != nullptr)
	{
		cout << "Poprzednie strzaly: ";
		Strzal* temp = gracz->pHeadStrzal;
		while (temp->pNext != nullptr)
		{
			cout << temp->wartosc << ", ";
			temp = temp->pNext;
		}
		cout << temp->wartosc << "." << endl;
	}
	return out;
}