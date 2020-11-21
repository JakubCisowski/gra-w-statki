#include "Pieciomasztowiec.h"

Pieciomasztowiec::Pieciomasztowiec(int id, string k1, string k2, string k3, string k4, string k5)
{
	this->setID(id);
	this->dodajKoordynate(k1);
	this->dodajKoordynate(k2);
	this->dodajKoordynate(k3);
	this->dodajKoordynate(k4);
	this->dodajKoordynate(k5);
}