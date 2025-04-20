#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include "math.h"
using namespace std;


class Matrix{

public:
	
	//Matrix Constructor
	Matrix(int rows, int cols);
	//Deallocate dynamic memory
	~Matrix();
	//Displays Matrix
	void display();
	//Gets the matrix
	int** getMatrix();
	//Get the rows of matrix
	int getRows();
	//Get the columns
	int getCols();
	//Sets matrix value
	void set(int row, int col, int value);

private:
	//Core variables
	int** matrix;
	int rows; 
	int cols;

};


#endif
