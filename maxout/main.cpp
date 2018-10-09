#include <iostream>
#include "include/ReadGet/ReadData.hpp"
#include "include/Matrix.hpp"
#include "include/MaxOutUnit.hpp"
#include "include/MaxOutNet.hpp"

int main()
{	
	// Wpisanie nazwy // dane musza byc bez znakow i zakonczone enterem z pusta linia
	printf("====Write File Name With Extension To Read==== \n");
	std::string nazwa;
	getline(cin, nazwa);

	printf("====Enter number Unit Maxout: \n");
	int numU;
	std::cin >> numU;
	//Pobranie danych z pliku wielkosc wierszy/ kolumn/ i caly wektor wartosci
	ReadData *rd = new ReadData(nazwa);
	MaxOutNet *mo = new MaxOutNet(rd->readInputValue(), numU);

	system("pause");
	return 0;
}
