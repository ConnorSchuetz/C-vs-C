#ifndef MATRIXOPP_H
#define MATRIXOPP_H
#include <iostream>
#include <string>
#include "math.h"
#include "matrix.h"
using namespace std;


class matrixOpperation {

public:
	//Multiplies the matrix by a given integer rather than a matrix
	Matrix* matrixMult(Matrix m, int num);
	//Matrix multiply with another matrix
	Matrix* matrixMult(Matrix front, Matrix back);
	//Matrix transpose
	Matrix* matrixTranspose(Matrix m);
	//Matrix added
	Matrix* matrixAddition(Matrix a, Matrix b);
	
};

#endif
