#pragma once
#include "Statek.h"
#include <string>
class Jednomasztowiec : public Statek
{
private:
	int dlugosc = 1;
public:
	Jednomasztowiec(int id, std::string k1);
};
