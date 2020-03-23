#pragma once

class Zadanie
{
	int R;
	int P;
	int Q;
	int Numer;
	double priorytet;

public:

	//Metoda pozwalajaca na odczytanie wartosci pola R
	int getR() const
	{
		return R;
	}

	//Metoda pozwalajaca na zapisanie wartosci do pola R
	void setR(int r)
	{
		R = r;
	}

	//Metoda pozwalajaca na odczytanie wartosci pola P
	int getP() const
	{
		return P;
	}

	//Metoda pozwalajaca na zapisanie wartosci do pola P
	void setP(int p)
	{
		P=p;
	}

	//Metoda pozwalajaca na odczytanie wartosci pola Q
	int getQ() const
	{
		return Q;
	}

	//Metoda pozwalajaca na zapisanie wartosci do pola Q
	void setQ(int q)
	{
		Q=q;
	}

	//Metoda pozwalajaca na odczytanie wartosci pola Numer
	int getNumer() const
	{
		return Numer;
	}

	//Metoda pozwalajaca na odczytanie wartosci pola priorytet
	double getPriorytet() const
	{
		return priorytet;
	}

	void wczytaj(int r, int p, int q, int i)
	{
		R = r;
		P = p;
		Q = q;
		Numer = i+1;
	}

	void oblicz_priorytet(double waga)
	{
		priorytet = (double)R/Q + R * waga;
	}
};