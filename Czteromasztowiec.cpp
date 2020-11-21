#include "Czteromasztowiec.h"

Czteromasztowiec::Czteromasztowiec(int id, std::string k1, std::string k2, std::string k3, std::string k4)
{
	this->setID(id);
	this->dodajKoordynate(k1);
	this->dodajKoordynate(k2);
	this->dodajKoordynate(k3);
	this->dodajKoordynate(k4);
}