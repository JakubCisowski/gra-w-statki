#include "Dwumasztowiec.h"

Dwumasztowiec::Dwumasztowiec(int id, std::string k1, std::string k2)
{
	this->setID(id);
	this->dodajKoordynate(k1);
	this->dodajKoordynate(k2);
}