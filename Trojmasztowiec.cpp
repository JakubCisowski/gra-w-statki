#include "Trojmasztowiec.h"

Trojmasztowiec::Trojmasztowiec(int id, std::string k1, std::string k2, std::string k3)
{
	this->setID(id);
	this->dodajKoordynate(k1);
	this->dodajKoordynate(k2);
	this->dodajKoordynate(k3);
}