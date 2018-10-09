#ifndef _MAX_OUT_UNIT_HPP_
#define _MAX_OUT_UNIT_HPP_

#include <iostream>
#include "Matrix.hpp"
#include "utils/MultiplyMatrix.hpp"
#include "MaxMinVec.hpp"


class MaxOutUnit {
public:
	MaxOutUnit(std::vector<std::vector<double>> inputValue);
	~MaxOutUnit();
	// Create random number for bias
	double generateBiasParametLearned();
	std::vector<double> max_zi() { return max_z; }
	std::vector<double> min_zi() { return min_z; }

	void Obliczenia();
	void printToConsole();

private:
	size_t sizeRow;
	size_t sizeCol;
	std::vector<std::vector<double>> inputValue;
	std::vector<double> max_z;
	std::vector<double> min_z;
};

#endif // !_MAX_OUT_UNIT_HPP_
