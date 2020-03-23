#include "pch.h"
#include "Planista.h"




int main()
{
	Planista Marek;
	double waga = 0.0001;
	int suma = 0;;
	for (int i = 1; i <= 4; ++i)
	{
		std::string nazwa = "data" + std::to_string(i) + ".txt";
		Marek.wczytaj_dane_z_pliku(nazwa);
		Marek.schrage();
		Marek.najwiekszeQ();
		Marek.magicznyAlgorytm(waga);
		suma=suma+Marek.wypisz();
	}

	std::cout <<std::endl << "Wykonanie wszystkich zadan zajmuje " << suma << std::endl;




	return 0;
}


