#include "../include/ReadGet/ReadData.hpp"
/* 
	do calkowitego przerobienia, aby czytalo wszystkie znaki
	z odpowiednio ustawionymi wartosciami
*/


ReadData::ReadData(string fileName) {
	this->nameData = fileName;
	setDataValue();
}

void ReadData::setDataValue(){
	int row = 0;
	int col = 0;
	double k = 0.00;
	
	ifstream plik;
	string linia;
	plik.open(this->nameData);
	if (plik.fail()){
		cerr << "File not exist, or bad name file \n";
		system("pause");
		exit(0);
	} 
	// Czytanie danych
		while(plik.good()) {
			while(getline(plik, linia)){
				vector<double> inValue;
				istringstream streamK(linia);
				col = 0;
				while(streamK >> k){
					inValue.push_back(k);
					col++;
				}
				this->inputValue.push_back(inValue);
				row++;
			}
			linia.clear();
		}
		plik.close();
		this->sizeRow = row;
		this->sizeCol = col;
}