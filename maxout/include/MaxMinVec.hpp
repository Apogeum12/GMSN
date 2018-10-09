#ifndef _MAX_MIN_VEC_HPP_
#define _MAX_MIN_VEC_HPP_

#include <iostream>
#include <vector>
#include <cmath>
#include "Matrix.hpp"


// Klasa max min vektor
class MaxMinVec {
public:
	//Konstruktor
	MaxMinVec(Matrix *A);
	~MaxMinVec();
	// wyciaganie najwiekszego i najmniejszego wektora
	std::vector<double> getMaxA() { return MaxA; }
	std::vector<double> getMinA() { return MinA; }

	void searchMaxMinA();
	//Dla sprawdzenia czy dzila
	void printToConsole();

private:
	Matrix *A;
	std::vector<double> MaxA;
	std::vector<double> MinA;
};


#endif // !_MAX_MIN_VEC_HPP_
