#pragma once
#include <string>
#include "Statek.h"

// Listy jedonkierunkowe przechowujace odpowiednio:

// Statki gracza
struct StatekGracza
{
	Statek* wartosc;
	StatekGracza* pNext;
};

// Strzaly gracza
struct Strzal
{
	std::string wartosc;
	Strzal* pNext;
};