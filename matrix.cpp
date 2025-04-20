#include "matrix.h"

//Default constructor

//Matrix Constructor
Matrix::Matrix(int row, int col) {
	//Set member variables
	rows = row;
	cols = col;
	//Makes the matrix
	matrix = new int*[row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new int[col];
	}
}
//Copy Constructor
Matrix::Matrix(const Matrix& other) {
	//Copies the rows and columns
	rows = other.rows;
	cols = other.cols;
	//Makes the new matrix
	matrix = new int* [rows];
	//Loops through the matrix
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = other.matrix[i][j];
		}
	}
}
//Matrix Deconstructor
Matrix::~Matrix() {
	//Deallocating all matrixes made
	if (matrix != nullptr) {
		for (int i = 0; i < rows; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
		matrix = nullptr;
	}
	//Makes core variables 0 for safety
	rows = 0;
	cols = 0;
}
//Displays Matrix
void Matrix::display() {
	//Prints matrix
	for (int i = 0; i < rows; i++) {
		cout << "|  ";
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << "  ";
		}
		cout << "|" << endl;
	}
}

//Gets the matrix
int** Matrix::getMatrix() {
	return matrix;
}
//Get the rows of matrix
int Matrix::getRows() {
	return rows;
}
//Get the columns
int Matrix::getCols() {
	return cols;
}
//Sets the value
void Matrix::set(int row, int col, int value) {
	matrix[row][col] = value;
}
