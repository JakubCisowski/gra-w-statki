#pragma once
#include "Statek.h"
#include <string>
using namespace std;

class Pieciomasztowiec : public Statek
{
private:
	int dlugosc = 5;
public:
	Pieciomasztowiec(int id, string k1, string k2, string k3, string k4, string k5);
};
