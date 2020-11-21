#include "Operacje.h"
#include "Statek.h"
#include <fstream>
#include <iostream>
#include "Pieciomasztowiec.h"
#include "Czteromasztowiec.h"
#include "Trojmasztowiec.h"
#include "Dwumasztowiec.h"
#include "Jednomasztowiec.h"
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

void Operacje::wyswietlStrzalyUzytkownika(Gracz* uzytkownik, Gracz* komputer)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "----------------------------" << endl << endl;
	cout << " Plansza twoich strzalow i trafien w przeciwnika: [o - strzal spudlowany, x - strzal trafiony]" << endl << endl;
	cout << "    A B C D E F G H I J" << endl;

	for (int i = 0; i < 10; i++)
	{
		if (i == 9)
		{
			cout << " " << i + 1 << " ";
		}
		else
		{
			cout << " " << i + 1 << "  ";
		}
		for (int j = 0; j < 10; j++)
		{
			string koordynata = "";
			char y = i + 49; // a - j
			char x = j + 97; // 1 - 10
			if (i == 9)
			{
				koordynata += x;
				koordynata += "10";
			}
			else
			{
				koordynata += x;
				koordynata += y;
			}

			if (uzytkownik->czyGraczStrzelil(koordynata))
			{
				if (komputer->czyGraczMaTuStatek(koordynata))
				{
					SetConsoleTextAttribute(hConsole, 10);
					cout << "x ";
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "o ";
				}
				SetConsoleTextAttribute(hConsole, 7);
			}
			else
			{
				cout << "- ";
			}
		}
		cout << endl;
	}
}

void Operacje::wyswietlStatkiUzytkownika(Gracz* uzytkownik, Gracz* komputer)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << " Twoja plansza statkow i ich stanu: [O - twoj statek, X - twoj trafiony statek]" << endl << endl;
	cout << "    A B C D E F G H I J" << endl;

	for (int i = 0; i < 10; i++)
	{
		if (i == 9)
		{
			cout << " " << i + 1 << " ";
		}
		else
		{
			cout << " " << i + 1 << "  ";
		}
		for (int j = 0; j < 10; j++)
		{
			string koordynata = "";
			char y = i + 49; // a - j
			char x = j + 97; // 1 - 10
			if (i == 9)
			{
				koordynata += x;
				koordynata += "10";
			}
			else
			{
				koordynata += x;
				koordynata += y;
			}

			if (uzytkownik->czyGraczMaTuStatek(koordynata))
			{
				if (komputer->czyGraczStrzelil(koordynata))
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "X ";
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 10);
					cout << "O ";
				}
				SetConsoleTextAttribute(hConsole, 7);
			}
			else
			{
				cout << "- ";
			}
		}
		cout << endl;
	}
	cout << endl;
	cout << "----------------------------" << endl;
	cout << endl;
}

bool Operacje::generujStatkiUzytkownika(Gracz* uzytkownik)
{
	ifstream plik;
	plik.open("Plansza.txt");

	if (!plik)
	{
		cout << "Nie udalo sie otworzyc pliku \"Plansza.txt\", prosze sprawdzic czy na pewno istnieje." << endl;
		cout << "Zamykam program." << endl;
		plik.close();
		return false;
	}

	string temp;
	string koordynaty[15];
	int index = 0;
	while (plik >> temp)
	{
		koordynaty[index++] = temp;
	}

	Statek* piecio = new Pieciomasztowiec(1, koordynaty[0], koordynaty[1], koordynaty[2], koordynaty[3], koordynaty[4]);
	uzytkownik->dodajStatek(piecio);

	Statek* cztero = new Czteromasztowiec(1, koordynaty[5], koordynaty[6], koordynaty[7], koordynaty[8]);
	uzytkownik->dodajStatek(cztero);

	Statek* troj = new Trojmasztowiec(1, koordynaty[9], koordynaty[10], koordynaty[11]);
	uzytkownik->dodajStatek(troj);

	Statek* dwu = new Dwumasztowiec(1, koordynaty[12], koordynaty[13]);
	uzytkownik->dodajStatek(dwu);

	Statek* jedno = new Jednomasztowiec(1, koordynaty[14]);
	uzytkownik->dodajStatek(jedno);

	cout << "Pomyslnie wczytano statki uzytkownika!" << endl << endl;

	return true;
}

void Operacje::generujStatkiKomputera(Gracz* komputer)
{
	srand(time(NULL));
	int set = rand() % 5; // Losuje jeden z 5 setow statkow komputera

	//set = 3; // USUNAC

	switch (set)
	{
	case 0: {
		Statek* piecio = new Pieciomasztowiec(1, "a4", "a5", "a6", "a7", "a8");
		komputer->dodajStatek(piecio);

		Statek* cztero = new Czteromasztowiec(1, "a1", "b1", "c1", "d1");
		komputer->dodajStatek(cztero);

		Statek* troj = new Trojmasztowiec(1, "f6", "g6", "h6");
		komputer->dodajStatek(troj);

		Statek* dwu = new Dwumasztowiec(1, "g7", "i7");
		komputer->dodajStatek(dwu);

		Statek* jedno = new Jednomasztowiec(1, "j8");
		komputer->dodajStatek(jedno);
		break;
	}

	case 1: {
		Statek* piecio = new Pieciomasztowiec(1, "j8", "j7", "j6", "j5", "j4");
		komputer->dodajStatek(piecio);

		Statek* cztero = new Czteromasztowiec(1, "e1", "f1", "g1", "h1");
		komputer->dodajStatek(cztero);

		Statek* troj = new Trojmasztowiec(1, "i5", "h5", "g5");
		komputer->dodajStatek(troj);

		Statek* dwu = new Dwumasztowiec(1, "a3", "b3");
		komputer->dodajStatek(dwu);

		Statek* jedno = new Jednomasztowiec(1, "f2");
		komputer->dodajStatek(jedno);
		break;
	}

	case 2: {
		Statek* piecio = new Pieciomasztowiec(1, "h5", "h4", "h3", "h2", "h1");
		komputer->dodajStatek(piecio);

		Statek* cztero = new Czteromasztowiec(1, "a1", "b1", "c1", "d1");
		komputer->dodajStatek(cztero);

		Statek* troj = new Trojmasztowiec(1, "f2", "f3", "f4");
		komputer->dodajStatek(troj);

		Statek* dwu = new Dwumasztowiec(1, "a5", "b5");
		komputer->dodajStatek(dwu);

		Statek* jedno = new Jednomasztowiec(1, "c7");
		komputer->dodajStatek(jedno);
		break;
	}

	case 3: {
		Statek* piecio = new Pieciomasztowiec(1, "c5", "d5", "e5", "f5", "g5");
		komputer->dodajStatek(piecio);

		Statek* cztero = new Czteromasztowiec(1, "a3", "b3", "c3", "d3");
		komputer->dodajStatek(cztero);

		Statek* troj = new Trojmasztowiec(1, "e10", "f10", "g10");
		komputer->dodajStatek(troj);

		Statek* dwu = new Dwumasztowiec(1, "a1", "a2");
		komputer->dodajStatek(dwu);

		Statek* jedno = new Jednomasztowiec(1, "e8");
		komputer->dodajStatek(jedno);
		break;
	}

	case 4: {
		Statek* piecio = new Pieciomasztowiec(1, "b2", "c2", "d2", "e2", "f2");
		komputer->dodajStatek(piecio);

		Statek* cztero = new Czteromasztowiec(1, "d3", "c3", "b3", "a3");
		komputer->dodajStatek(cztero);

		Statek* troj = new Trojmasztowiec(1, "f8", "f9", "f10");
		komputer->dodajStatek(troj);

		Statek* dwu = new Dwumasztowiec(1, "g2", "h2");
		komputer->dodajStatek(dwu);

		Statek* jedno = new Jednomasztowiec(1, "i7");
		komputer->dodajStatek(jedno);
		break;
	}
	}

	cout << "Wygenerowano plansze komputera!" << endl;
}

string Operacje::generujStrzalKomputera(Gracz* komputer)
{
	string strzal = "";
	do
	{
		strzal = "";
		srand(time(NULL));
		int pierwszy = rand() % 10 + 1;
		int drugi = rand() % 10 + 1;

		char p = pierwszy + 96; // a-j
		char d = drugi + 48; // 1-10
		if (drugi == 10)
		{
			strzal += p;
			strzal += "10";
		}
		else
		{
			strzal += p;
			strzal += d;
		}
	} while (komputer->czyGraczStrzelil(strzal));

	return strzal;
}

void Operacje::graj(Gracz* uzytkownik, Gracz* komputer)
{
	_getch();
	system("CLS");

	while (true)
	{
		//! TURA UZYTKOWNIKA

		Operacje::wyswietlStrzalyUzytkownika(uzytkownik, komputer);
		Operacje::wyswietlStatkiUzytkownika(uzytkownik, komputer);

		string strzal;
		cout << uzytkownik;
		cout << "Prosze podac koordynaty strzalu (np. a3, j10, e5):" << endl;
		cin >> strzal;
		while (!uzytkownik->sprawdzStrzal(strzal))
		{
			cin >> strzal;
		}
		uzytkownik->dodajStrzal(strzal);

		cout << endl << "----------------------------" << endl;
		cout << "Aby kontyunuowac rozgrywke wcisnij jakikolwiek klawisz." << endl;
		_getch();
		system("CLS");

		// Wyswietlenie planszy po strzale uzytkownika

		Operacje::wyswietlStrzalyUzytkownika(uzytkownik, komputer);
		Operacje::wyswietlStatkiUzytkownika(uzytkownik, komputer);

		if (komputer->czyGraczMaTuStatek(strzal))
		{
			cout << "Gratulacje! Trafiles w statek komputera!" << endl;
		}
		else
		{
			cout << "Pudlo!" << endl;
		}

		// Sprawdzenie czy uzytkownik wygral
		if (komputer->czyGraczPrzegral(uzytkownik))
		{
			cout << endl << "ZWYCIESTWO! Zestrzeliles wszystkie statki komputera!" << endl;
			cout << endl << "----------------------------" << endl;
			cout << "Aby zakonczyc rozgrywke wcisnij jakikolwiek klawisz." << endl;
			_getch();
			return;
		}

		cout << endl << "----------------------------" << endl;
		cout << "Aby kontyunuowac rozgrywke wcisnij jakikolwiek klawisz." << endl;
		_getch();
		system("CLS");

		//! TURA KOMPUTERA

		Operacje::wyswietlStrzalyUzytkownika(uzytkownik, komputer);
		Operacje::wyswietlStatkiUzytkownika(uzytkownik, komputer);

		string strzalKomputera = generujStrzalKomputera(komputer);
		cout << "Komputer strzelil w pole " << strzalKomputera << endl;
		komputer->dodajStrzal(strzalKomputera);

		cout << endl << "----------------------------" << endl;
		cout << "Aby kontyunuowac rozgrywke wcisnij jakikolwiek klawisz." << endl;
		_getch();
		system("CLS");

		Operacje::wyswietlStrzalyUzytkownika(uzytkownik, komputer);
		Operacje::wyswietlStatkiUzytkownika(uzytkownik, komputer);

		if (uzytkownik->czyGraczMaTuStatek(strzalKomputera))
		{
			cout << "Komputer trafil w twoj statek!" << endl;
		}
		else
		{
			cout << "Komputer spudlowal!" << endl;
		}

		// Sprawdzenie czy komputer wygral
		if (uzytkownik->czyGraczPrzegral(komputer))
		{
			cout << endl << "PORAZKA! Komputer zestrzelil wszystkie twoje statki!" << endl;
			cout << endl << "----------------------------" << endl;
			cout << "Aby zakonczyc rozgrywke wcisnij jakikolwiek klawisz." << endl;
			_getch();
			return;
		}

		cout << endl << "----------------------------" << endl;
		cout << "Aby kontyunuowac rozgrywke wcisnij jakikolwiek klawisz." << endl;
		_getch();
		system("CLS");
	}
}