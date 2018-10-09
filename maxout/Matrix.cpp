#include "include/Matrix.hpp"

// For Weights
double Matrix::generateRandomNumber() {
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_real_distribution<> dis(0, 1);
	return dis(gen);
}

// Check on console search error or bug
void Matrix::printToConsole() {
	std::cout << "Sprawdzenie wyniku: \n";
	for (int i = 0; i < numRow; i++) {
		for (int j = 0; j < numCol; j++) {
			std::cout << this->values.at(i).at(j) << " \t";
		}
		std::cout << std::endl;
	}
}

Matrix::Matrix(int numRow, int numCol, bool isRandom) {
	this->numRow = numRow;
	this->numCol = numCol;

	for (int i = 0; i < numRow; i++) {
		vector<double> colValues;
		for (int j = 0; j < numCol; j++){
			double r = 0.00;
			if (isRandom) {
				r = this->generateRandomNumber();
			}
			colValues.push_back(r);
		}
		this->values.push_back(colValues);
		colValues.clear();
		colValues.shrink_to_fit();
	}
}

Matrix::~Matrix() {
	values.clear();
	values.shrink_to_fit();
}

Matrix *Matrix::transpose() {
	Matrix *m = new Matrix(this->numCol, this->numRow, false);

	for (int i = 0; i < numRow; i++) {
		for (int j = 0; j < numCol; j++) {
			m->setValue(j, i, this->getValue(i, j));
		}
	}
	return m;
}