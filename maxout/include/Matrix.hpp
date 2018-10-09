#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <random>
#include <vector>
#include <iostream>

using namespace std;

class Matrix {
public:
	Matrix(int numRow, int numCol, bool isRandom);
	~Matrix();
	Matrix *transpose();
	double generateRandomNumber();

	void setValue(int r, int c, double v) { this->values.at(r).at(c) = v; }
	double getValue(int r, int c) { return this->values.at(r).at(c); }

	void printToConsole();

	int getNumRows() { return this->numRow; }
	int getNumCols() { return this->numCol; }


private:
	vector<vector<double>> values;
	int numRow;
	int numCol;
};

#endif // !_MATRIX_HPP_
