#include "include/MaxOutUnit.hpp"

//Bias
double MaxOutUnit::generateBiasParametLearned() {
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_real_distribution<> dis(0, 0.5);
	return dis(gen);
}

MaxOutUnit::MaxOutUnit(std::vector<std::vector<double>> inputValue) {
	this->inputValue = inputValue;
	// Zamiana wartosci wejsciowych z X na (X)T
	this->Obliczenia();
}

void MaxOutUnit::Obliczenia() {
	this->sizeRow = this->inputValue.size();

	// Zakladamy ze dane wejsciowe sa rozmiaru NxN 
	this->sizeCol = this->inputValue.at(0).size();
	Matrix *x_t = (Matrix*)malloc(sizeof(Matrix)*sizeRow);
	Matrix *W = (Matrix*)malloc(sizeof(Matrix)*sizeRow);
	Matrix *val = (Matrix*)malloc(sizeof(Matrix)*sizeRow);
	MaxMinVec *mmv = (MaxMinVec*)malloc(sizeof(MaxMinVec)*sizeRow);

	//Inicjacja macierzy bias NxN
	double b = generateBiasParametLearned();
	
	// Inicjacja wektorow max i min
	std::vector<vector<double>> vec_max;
	std::vector<vector<double>> vec_min;

	for (int k = 0; k < sizeRow; k++) {
		x_t = new Matrix((int)sizeCol, 1, false);

		for (int j = 0; j < sizeCol; j++) {
			x_t->setValue(j,
				0,
				inputValue.at(k).at(j));
		}

		W = new Matrix(1, (int)sizeCol, true);
		// Oblicznie mnozenia macierzy 
		val = (new utils::MultiplyMatrix(x_t, W))->execute(b);
		//Szukanie najwiekszej i najmniejszej wartosci
		mmv = new MaxMinVec(val);
		val->~Matrix();

		vec_max.push_back(mmv->getMaxA());
		vec_min.push_back(mmv->getMinA());
	}
	mmv->~MaxMinVec();

	Matrix *max = new Matrix((int)vec_max.size(), (int)vec_max.at(0).size(), false);
	Matrix *min = new Matrix((int)vec_max.size(), (int)vec_max.at(0).size(), false);
	for (int i = 0; i < vec_max.size(); i++) {
		for (int j = 0; j < vec_max.at(i).size(); j++) {
			max->setValue(i,
				j,
				vec_max.at(i).at(j));
		}
	}
	vec_max.clear();
	vec_max.shrink_to_fit();

	for (int i = 0; i < vec_min.size(); i++) {
		for (int j = 0; j < vec_min.at(i).size(); j++) {
			min->setValue(i,
				j,
				vec_min.at(i).at(j));
		}
	}
	vec_min.clear();
	vec_min.shrink_to_fit();

	MaxMinVec *h_max = new MaxMinVec(max);
	MaxMinVec *h_min = new MaxMinVec(min);

	for (int i = 0; i < h_max->getMaxA().size(); i++) {
		this->max_z.push_back(h_max->getMaxA().at(i));
	}

	// Wybranie z nich najwiekszego i najmniejszego 
	for (int i = 0; i < h_min->getMinA().size(); i++) {
		this->min_z.push_back(h_min->getMinA().at(i));
	}

	h_max->~MaxMinVec();
	h_min->~MaxMinVec();
}

MaxOutUnit::~MaxOutUnit() {
	max_z.clear();
	min_z.clear();
	max_z.shrink_to_fit();
	min_z.shrink_to_fit();
}

void MaxOutUnit::printToConsole() {
	for (int i = 0; i < max_z.size(); i++) {
		std::cout << max_z.at(i) << " ";
	}
}