#pragma once
#include "Statek.h"
#include <string>
class Czteromasztowiec :public Statek
{
private:
	int dlugosc = 4;
public:
	Czteromasztowiec(int id, std::string k1, std::string k2, std::string k3, std::string k4);
};
