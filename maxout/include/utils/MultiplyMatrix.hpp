#ifndef _MULTIPLY_MATRIX_HPP_
#define _MULTIPLY_MATRIX_HPP_

#include <assert.h>
#include "../Matrix.hpp"

using namespace std;

namespace utils {
	class MultiplyMatrix {
	public:
		MultiplyMatrix(Matrix *a, Matrix *b);

		// b - bias learned paramets between 0 to 0.5
		Matrix *execute(double bias);
	private:
		Matrix *a;
		Matrix *b;
		Matrix *c;
	};
}
#endif // !_MULTIPLY_MATRIX_HPP_
