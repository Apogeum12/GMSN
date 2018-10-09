#include "../include/utils/MultiplyMatrix.hpp"

utils::MultiplyMatrix::MultiplyMatrix(Matrix *a, Matrix *b) {
	this->a = a;
	this->b = b;

	if (a->getNumCols() != b->getNumRows()) {
		cerr << " A_Rows: " << a->getNumRows() << " != "
			" B_cols: " << b->getNumCols() << endl;
	}
	this->c = new Matrix(a->getNumRows(),
						b->getNumCols(),
						false);
}

// Do przerobienia na GPU mnozenie macierzy Nx1 X 1xN
Matrix *utils::MultiplyMatrix::execute(double bias) {
	for (int i = 0; i < a->getNumRows(); i++) {
		for (int j = 0; j < b->getNumCols(); j++) {
			double p = this->a->getValue(i, 0) * this->b->getValue(0, j);
			double newVal = this->c->getValue(i, j) + p + bias;
			this->c->setValue(i, j, newVal);
		}
	}

	return this->c;
}