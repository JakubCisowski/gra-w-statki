#pragma once
#include "Statek.h"
#include <string>
class Dwumasztowiec : public Statek
{
private:
	int dlugosc = 2;
public:
	Dwumasztowiec(int id, std::string k1, std::string k2);
};
