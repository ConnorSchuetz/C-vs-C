//Driver file
//File is responsible for utilizing matrix file to calculate matrix operations
//Giving prebuilt matrix or user enterd matrix
//
#include <iostream>
#include "matrix.h"
#include "matrixOpp.h"
using namespace std;

int main(){
	cout << "C++ Code Output: " << endl;
	cout << "This program will calculate the D matrix with the given matrix A, B, and C: " << endl;
	//Creates the helper class to do the matrix operations
	matrixOpperation dSolution;
	//Creates Matrix A, B, and C
	Matrix a = Matrix(2, 2);
	a.set(0, 0, 6);
	a.set(0, 1, 4);
	a.set(1, 0, 8);
	a.set(1, 1, 3);
	Matrix b = Matrix(2, 3);
	b.set(0, 0, 1);
	b.set(0, 1, 2);
	b.set(0, 2, 3);
	b.set(1, 0, 4);
	b.set(1, 1, 5);
	b.set(1, 2, 6);
	Matrix c = Matrix(2, 3);
	c.getMatrix()[0] = new int[3] { 2, 4, 6 };
	c.getMatrix()[1] = new int[3] { 1, 3, 5 };
	c.set(0, 0, 2);
	c.set(0, 1, 4);
	c.set(0, 2, 6);
	c.set(1, 0, 1);
	c.set(1, 1, 3);
	c.set(1, 2, 5);
	//Displays the matrix
	a.display();
	b.display();
	c.display();
	//We multiply B matrix by 3
	cout << "First objective is to multiply the B matrix by 3 and we will get: " << endl;
	Matrix* b3 = dSolution.matrixMult(b, 3);
	b3->display();
	//Then we will Transpose C
	cout << "Next due to it being next in precidence we will transpose C to: " << endl;
	Matrix* cT = dSolution.matrixTranspose(c);
	cT->display();
	//Next we multiply the B and C matrix together
	cout << "Now it is possible to multiply the B and C matrix to produce BC: " << endl;
	Matrix* bc = dSolution.matrixMult(*b3, *cT);
	bc->display();
	cout << "Finally to get matrix D we add A to BC to get: " << endl;
	Matrix* d = dSolution.matrixAddition(a, *bc);
	d->display();
	delete b3;
	delete cT;
	delete bc;
	delete d;
	return 0;
}