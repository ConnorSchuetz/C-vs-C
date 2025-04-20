#include "matrixOpp.h"


//Multiplies the matrix by a given integer rather than a matrix and returns new matrix
Matrix* matrixOpperation::matrixMult(Matrix m, int num) {
    //Resulting matrix will have same rows and columns
    Matrix* result = new Matrix(m.getRows(), m.getCols());
    //Loops through given matrix m rows
    for (int i = 0; i < m.getRows(); i++) {
        //Loops throiugh columns to get 
        for (int j = 0; j < m.getCols(); j++) {
            //Multiples the values by given num
            result->getMatrix()[i][j] = m.getMatrix()[i][j] * num;
        }
    }
    return result;
}
//Matrix multiply with another matrix returns result
Matrix* matrixOpperation::matrixMult(Matrix front, Matrix back) {
    //New matrix will have # of rows from front and # of columns from back
    Matrix* result = new Matrix(front.getRows(), back.getCols());
    //Keeps track of the sums
    int sum = 0;
    //Loops through rows of new matrix
    for (int i = 0; i < result->getRows(); i++) {
        //Loops through columns
        for (int j = 0; j < result->getCols(); j++) {
            //Loops throgh front and back to get sum
            for (int z = 0; z < front.getCols(); z++) {
                sum = sum + (front.getMatrix()[i][z] * back.getMatrix()[z][j]);
            }
            //Sum is value for result
            result->getMatrix()[i][j] = sum;
            //Resets sum
            sum = 0;
        }
    }
    return result;
}
//Matrix transpose
Matrix* matrixOpperation::matrixTranspose(Matrix m) {
    //The resulting matrix will have rows and columns fliped
    Matrix* result = new Matrix(m.getCols(), m.getRows());
    //Loop through the new matrix
    for (int i = 0; i < result->getRows(); i++) {
        for (int j = 0; j < result->getCols(); j++) {
            //Add the values to new matrix
            result->getMatrix()[i][j] = m.getMatrix()[j][i];
        }
    }
    //Return the result
    return result;
    }
//Matrix added
Matrix* matrixOpperation::matrixAddition(Matrix a, Matrix b) {
    //Resulting matrix has rows and columns equall to a and b
    Matrix* result = new Matrix(a.getRows(), a.getCols());
    //Loops through each spot in new matrix
    for (int i = 0; i < result->getRows(); i++) {
        for (int j = 0; j < result->getCols(); j++) {
            //Adds the matrix together
            result->getMatrix()[i][j] = a.getMatrix()[i][j] + b.getMatrix()[i][j];
        }
    }
    //Returns resulting matrix
    return result;
}
