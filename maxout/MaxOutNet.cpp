#include "include/MaxOutNet.hpp"

MaxOutNet::MaxOutNet(std::vector<std::vector<double>> inputData, int numUnit) {
	this->inputData = inputData;
	this->numUnit = numUnit;
	this->outputFunctionActivation();
}

void MaxOutNet::outputFunctionActivation() {
	MaxOutUnit *mu = (MaxOutUnit*)malloc(sizeof(MaxOutNet)*numUnit);
	std::vector<std::vector<double>> z_i_max;
	std::vector<std::vector<double>> z_i_min;
	if (numUnit == 0) cerr << "Error minimuim 1 units: \n";
	for (int i = 0; i < numUnit; i++) {
		mu = new MaxOutUnit(this->inputData);
		z_i_max.push_back(mu->max_zi());
		z_i_min.push_back(mu->min_zi());
		mu->~MaxOutUnit();
	}

	Matrix *max = new Matrix((int)numUnit, (int)inputData.at(0).size(), false);
	Matrix *min = new Matrix((int)numUnit, (int)inputData.at(0).size(), false);
	for (int i = 0; i < numUnit; i++) {
		for (int j = 0; j < z_i_max.at(i).size(); j++) {
			max->setValue(i,
				j,
				z_i_max.at(i).at(j));
		}
	}
	z_i_max.clear();
	z_i_max.shrink_to_fit();
	for (int i = 0; i < numUnit; i++) {
		for (int j = 0; j < z_i_min.at(i).size(); j++) {
			min->setValue(i,
				j,
				z_i_min.at(i).at(j));
		}
	}
	z_i_min.clear();
	z_i_min.shrink_to_fit();


	MaxMinVec *h_max = new MaxMinVec(max);
	MaxMinVec *h_min = new MaxMinVec(min);
	max->~Matrix();
	min->~Matrix();

	std::cout << "h(x) max: \n";
	for (int i = 0; i < h_max->getMaxA().size(); i++) {
		std::cout << h_max->getMaxA().at(i)<<" ";
	}

	std::cout << "\n h(x) min: \n";
	for (int i = 0; i < h_min->getMinA().size(); i++) {
		std::cout << h_min->getMinA().at(i) << " ";
	}

	std::cout << "\n\n g(x) = h1(x) - h2(x) \n";
	// Nasza funkcja aktywacji:
	for (int i = 0; i < h_max->getMaxA().size(); i++) {
		std::cout << h_max->getMaxA().at(i) - h_min->getMinA().at(i) << " ";
	}
}