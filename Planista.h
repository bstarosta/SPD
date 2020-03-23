#pragma once
#include "Zadanie.h"
#include  <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <list>

class  Planista
{
	int n;				//liczba zadan do wykonania
	int cmax;
	Zadanie *zbior; //tablica przechowujaca informacje o zadaniach
	Zadanie *kolejnosc_optymalna;

public:

	//Metoda wczytujaca dane z pliku do planisty
	void wczytaj_dane_z_pliku(std::string plik);
	void sortowanieQ(Zadanie tab[], int rozmiar);
	void sortowanieR(Zadanie tab[], int rozmiar);
	void sortowaniePriorytet(Zadanie tab[], int rozmiar);
	void schrage();
	void magicznyAlgorytm(double waga);
	void najwiekszeQ();
	int wylicz_cmax(Zadanie tab[]);
	int wypisz();
};
