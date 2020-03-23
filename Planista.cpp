#include "pch.h"
#include "Planista.h"

void Planista::wczytaj_dane_z_pliku(std::string plik)
{
	int r, p, q;
	cmax = 10000000000;
	std::ifstream dane_wejsciowe(plik);
	dane_wejsciowe >> n;
	zbior = new Zadanie[n];
	kolejnosc_optymalna = new Zadanie[n];

	for (int i = 0; i < n; ++i)
	{
		dane_wejsciowe >> r >> p >> q;
		zbior[i].wczytaj(r, p, q, i);
	}
	dane_wejsciowe.close();
}

void Planista::sortowanieQ(Zadanie tab[], int rozmiar)
{
	int j;
	Zadanie pom;

	for (int i = 1; i < rozmiar; ++i)
	{
		pom = tab[i];

		for (j = i - 1; j >= 0 && tab[j].getQ() > pom.getQ(); --j)
			tab[j + 1] = tab[j];

		tab[j + 1] = pom;
	}
}

void Planista::sortowanieR(Zadanie tab[], int rozmiar)
{
	int j;
	Zadanie pom;

	for (int i = 1; i < rozmiar; ++i)
	{
		pom = tab[i];

		for (j = i - 1; j >= 0 && tab[j].getR() > pom.getR(); --j)
			tab[j + 1] = tab[j];

		tab[j + 1] = pom;
	}
}

void Planista::sortowaniePriorytet(Zadanie tab[], int rozmiar)
{
	int j;
	Zadanie pom;

	for (int i = 1; i < rozmiar; ++i)
	{
		pom = tab[i];

		for (j = i - 1; j >= 0 && tab[j].getPriorytet() > pom.getPriorytet(); --j)
			tab[j + 1] = tab[j];

		tab[j + 1] = pom;
	}
}


void Planista::schrage()
{
	int m = 0, k=0;
	Zadanie *kolejnosc = new Zadanie[n];
	std::list <Zadanie> N;
	std::list <Zadanie> G;
	Zadanie pom, *tab;
	sortowanieR(zbior, n);

	for (int i = 0; i < n; ++i)
		N.push_back(zbior[i]);

	
	
	while (!N.empty()||!G.empty())
	{
		
		
		//Dodawanie zadan gotowych do wykonania do listy G i usuwanie z listy N
		while (!N.empty() && N.front().getR() <= m)
		{
			pom = N.front();
			G.push_back(pom);
			N.pop_front();
		}

		if (G.empty())
		{
			m = N.front().getR();
		}
		else
		{

			int tab_rozmiar = G.size();
			//std::cout << G.size() << " ";
			tab = new Zadanie[tab_rozmiar];

			for (int j = 0; j < tab_rozmiar; ++j)
			{
				tab[j] = G.front();
				G.pop_front();
			}

			sortowanieQ(tab, tab_rozmiar);
			for (int j = tab_rozmiar - 1; j >= 0; --j)
				G.push_back(tab[j]);

			pom = G.front();
			G.pop_front();
			kolejnosc[k] = pom;
			m = m + pom.getP();
			++k;
			delete[] tab;
		}
	}
	//std::cout << wylicz_cmax(kolejnosc) << std::endl;
	if (wylicz_cmax(kolejnosc) < cmax)
	{
		delete[] kolejnosc_optymalna;
		kolejnosc_optymalna = kolejnosc;
		cmax = wylicz_cmax(kolejnosc);
	}
	else
		delete[] kolejnosc;
}

void Planista::magicznyAlgorytm(double waga)
{
	Zadanie *pom = new Zadanie[n];

	for (int i = 0; i < n; ++i)
	{
		zbior[i].oblicz_priorytet(waga);
		pom[i] = zbior[i];
	}
	
	sortowaniePriorytet(pom, n);
	//std::cout<< wylicz_cmax(pom)<<std::endl;

	if (wylicz_cmax(pom) < cmax)
	{
		delete[] kolejnosc_optymalna;
		kolejnosc_optymalna = pom;
		cmax = wylicz_cmax(pom);
	}
	else
		delete[] pom;
	
}

void Planista::najwiekszeQ()
{
	Zadanie *pom = new Zadanie[n];
	sortowanieQ(zbior, n);
	int t=0, k=2;
	while (t < zbior[n - 1].getQ())
	{
		t = t + zbior[n-(k++)].getP();
	}

	for (int i = 0; i < k; ++i)
		pom[i] = zbior[i];

	pom[n-k+1]=zbior[n-1];

	for (int j = n-k+2; j < n; ++j)
		pom[j] = zbior[j - 1];

	//std::cout << wylicz_cmax(pom) << std::endl;
	if (wylicz_cmax(pom) < cmax)
	{
		delete[] kolejnosc_optymalna;
		kolejnosc_optymalna = pom;
		cmax = wylicz_cmax(pom);
	}
	else
		delete[] pom;
}

int Planista::wylicz_cmax(Zadanie tab[])
{
	int m = 0, c = 0;
	for (int i = 0; i < n; ++i)
	{
		m = std::max(tab[i].getR(), m) + tab[i].getP();
		c = std::max(m + tab[i].getQ(), c);
	}

	return c;
}

int Planista::wypisz()
{
	int c = wylicz_cmax(kolejnosc_optymalna);
	for (int i = 0; i < n; ++i)
		std::cout << kolejnosc_optymalna[i].getNumer() << " ";
	std::cout<<"\n"<< "Czas wykonania zadan to " << c << "\n"<<"\n";
	return c;
}


