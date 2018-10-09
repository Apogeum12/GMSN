#include "include/MaxMinVec.hpp"

MaxMinVec::MaxMinVec(Matrix *A) {
	this->A = A;
	this->searchMaxMinA();
}

void MaxMinVec::searchMaxMinA() {
	size_t size_row = A->getNumRows();
	std::vector<double> max_a;
	std::vector<double> min_a;
	double compare1, compare2;
	double sum1 = 0, sum2 =0;
	int ite1 = 0, ite2 = 0;
	for (int i = 0; i < size_row; i++) {
		size_t size_col = A->getNumCols();
		for (int j = 0; j < size_col; j++) {
			sum1 += A->getValue(i, j)*A->getValue(i, j);
			sum2 += A->getValue(i, j)*A->getValue(i, j);
		}
		max_a.push_back(sum1);
		min_a.push_back(sum2);
		sum1 = 0;
		sum2 = 0;
	}
	compare1 = sqrt(max_a.at(0));
	for (int i = 0; i < max_a.size(); i++) {
		if (compare1 >= sqrt(max_a.at(i))) ite1;
		else { ite1 = i; compare1 = sqrt(max_a.at(i)); }
	}

	compare2 = sqrt(min_a.at(0));
	for (int i = 0; i < min_a.size(); i++) {
		if (compare2 <= sqrt(min_a.at(i))) ite2;
		else { ite2 = i; compare2 = sqrt(min_a.at(i)); }
	}

	for (int i = 0; i < A->getNumCols(); i++) {
		this->MaxA.push_back(A->getValue(ite1, i));
		this->MinA.push_back(A->getValue(ite2, i));
	}
	max_a.clear();
	min_a.clear();
}

MaxMinVec::~MaxMinVec() {
	this->A->~Matrix();
	this->getMaxA().clear();
	this->getMaxA().shrink_to_fit();
	this->getMinA().clear();
	this->getMinA().shrink_to_fit();
}

void MaxMinVec::printToConsole() {

	for (int i = 0; i < this->getMaxA().size(); i++) {
		std::cout << this->getMaxA().at(i) << " ";
	}
	std::cout << "\n";

	for (int i = 0; i < this->getMinA().size(); i++) {
		std::cout << this->getMinA().at(i) << " ";
	}
	std::cout << "\n";
}