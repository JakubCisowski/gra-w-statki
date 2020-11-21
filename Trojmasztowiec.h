#pragma once
#include "Statek.h"
#include <string>
class Trojmasztowiec : public Statek
{
private:
	int dlugosc = 3;
public:
	Trojmasztowiec(int id, std::string k1, std::string k2, std::string k3);
};
