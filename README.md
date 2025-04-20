# C-vs-C++
Repository for HW assignment 8 for CMSC313


AUTHORING: Connor Schuetz UMBC CMSC 313 4/19


PURPOSE OF SOFTWARE: To be able to preform Matrix Multiplication, Matrix Addition, and Matrix Transposing with any given matrix.


FILES:
# C++
1) driver.cpp - Drivers whole code printing to system steps to make D matrix with given A B C matrix
2) matrix.h - Header file for the matrix class shows the functions and member variables
3) matrix.cpp - Is the code that will display a matrix, construct a matrix, deallocate memory of matrix(error with double deletion), and set values for a matrix
4) matrixOpp.h - header file for the class responsible for matrix opperations
5) matrixOpp.cpp - Given matrixes will return a pointer to a new matrix after completeing a specified matrix operation to make a new matix. Opperations can be addition, multiplication, and transpose.
# C
matrixOpp.c - Able to complete matrix opperations with given matrixes made through the Struct. The code outputs the opperations A B C go through to make D matrix.


BUILD INSTRUCTIONS: This repository has 2 seperate programs, C and C++. C will only have matrixOpp.c . C++ needs driver.cpp, matrix.h, matrix.cpp, matrixOpp.h, matrixOpp.cpp . 


TESTING METHODOLOGY: Program should only run set print functions displaying how matrix D is built.



