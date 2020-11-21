#include "Statek.h"

Statek::~Statek()
{
	while (pHeadKoordynata)
	{
		auto p = pHeadKoordynata->pNext;
		delete pHeadKoordynata;
		pHeadKoordynata = p;
	}
}

void Statek::setID(int id)
{
	idWlasciciela = id;
}

void Statek::dodajKoordynate(std::string koor)
{
	if (pHeadKoordynata == nullptr)
	{
		pHeadKoordynata = new Koordynata;
		pHeadKoordynata->wartosc = koor;
		pHeadKoordynata->pNext = nullptr;
	}
	else
	{
		Koordynata* temp = pHeadKoordynata;
		while (temp->pNext != nullptr)
		{
			temp = temp->pNext;
		}
		temp->pNext = new Koordynata;
		temp->pNext->wartosc = koor;
		temp->pNext->pNext = nullptr;
	}
}

bool Statek::czyZawieraKoordynate(std::string koor)
{
	Koordynata* temp = pHeadKoordynata;

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

Koordynata* Statek::getKoordynata()
{
	return pHeadKoordynata;
}