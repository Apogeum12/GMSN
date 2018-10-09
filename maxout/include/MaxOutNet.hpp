#ifndef _MAX_OUT_NET_HPP_
#define _MAX_OUT_NET_HPP_

#include <iostream>
#include "Matrix.hpp"
#include "MaxMinVec.hpp"
#include "MaxOutUnit.hpp"

class MaxOutNet {
public:
	MaxOutNet(std::vector < std::vector<double>> inputData, int numUnit);

	void outputFunctionActivation();
private:
	int numUnit;
	std::vector < std::vector<double>> inputData;
};

#endif // !_MAX_OUT_NET_HPP_
