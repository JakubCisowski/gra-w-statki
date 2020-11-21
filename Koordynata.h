#pragma once
#include <string>

// Lista jednokierunkowa koordynatow pojedynczego statku
struct Koordynata
{
	std::string wartosc;
	Koordynata* pNext;
};