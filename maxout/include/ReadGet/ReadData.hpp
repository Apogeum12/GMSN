#ifndef _READ_DATA_HPP_
#define _READ_DATA_HPP_

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> // wszytywanie znakow
#include <string>

using namespace std;

class ReadData {
public:
	ReadData(string fileName);

	void setDataValue();

	vector < vector<double>> readInputValue() { return this->inputValue; }
	int sizeDataRow() { return this->sizeRow; }
	int sizeDataCol() { return this->sizeCol; }

private:
	string nameData;
	int sizeRow;
	int sizeCol;
	vector< vector<double>> inputValue;
};
#endif // !_READ_DATA_HPP_
