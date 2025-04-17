#include <stdio.h>


//Struct for the matrixes
typedef struct {
  int rows;
  int cols;
  int** matrix;
} Matrix;
//Prototypes
//Constructs Matrix
Matrix constructMatrix(int rows, int cols);
//Displays Matrix given
void display(Matrix m);
//Deallocates dynamic memory
void clean(Matrix m);
//Multiplies a matix variables by a number
void multMatrix(Matrix m, int num);
//Multiply with a matrix with a matrix
Matrix matrixMult(Matrix front, Matrix back);
//Returns a transposed matrix of the matrix provided
Matrix transpose(Matrix m);
//Creates a matrix of 2 mareixes added together
Matrix matrixAddition(Matrix a, Matrix b);

int main(void) {
  //Make the A B and C matrix
  //Makes A matrix
  Matrix A = constructMatrix(2, 2); 
  //Adds the given numbers to A matrix
  A.matrix[0][0] = 6;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 3;

  //Makes matrix B
  Matrix B = constructMatrix(2, 3);
 //Allocates B walues
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;

//Makes matrix C
  Matrix C = constructMatrix(2, 3);
  //Allocates C walues
  C.matrix[0][0] = 2;
  C.matrix[0][1] = 4;
  C.matrix[0][2] = 6;
  C.matrix[1][0] = 1;
  C.matrix[1][1] = 3;
  C.matrix[1][2] = 5;

  printf("C code output: \n");
  //Displays Matrix A B and C to user 
  printf("This program will calculate the D matrix with the given matrix A, B, and C: \n");
  display(A);
  display(B);
  display(C);
  //Step 1
  printf("First objective is to multiply the B matrix by 3 and we will get: \n");
  multMatrix(B, 3);
  display(B);
  //Step 2
  printf("Next due to it being next in precidence we will transpose C to: \n");
  Matrix transposed = transpose(C);
  display(transposed);
  //Step 3
  printf("Now it is possible to multiply the B and C matrix to produce BC: \n");
  Matrix BC = matrixMult(B, transposed);
  display(BC);
  //Step 4
  printf("Finally to get matrix D we add A to BC to get: \n");
  Matrix D = matrixAddition(A, BC);
  display(D);
  //Deallocate dynamic memory
  clean(A);
  clean(B);
  clean(C);
  clean(D);
  clean(BC);
  clean(transposed);
  return 0;
}

//Contructs a matrix given rows and colums
Matrix constructMatrix(int rows, int cols){
  Matrix m;
  m.rows = rows;
  m.cols = cols;
  //Allocates memory for matrix
  m.matrix =  (int**)malloc(m.rows * sizeof(int*));
  for(int i = 0; i < m.rows; i++){
    m.matrix[i] = (int*)malloc(m.cols * sizeof(int));
  }
  //Returns new matrix
  return m;
}

//Displays the given matrix
void display(Matrix m){
  //Loops through matrix line
  for(int i = 0; i < m.rows; i++){
    printf("|   ");
    //Loops through colomns in row
    for (int j = 0; j < m.cols; j++){
      //Prints the value and spaces them out
      printf("%d ", m.matrix[i][j]);
      printf("   ");
    }
    //Makes a new line
    printf("| \n");
  }
  //Last newline to make it look neat
  printf("\n");
}

//Used to deallocate matrix memory to avoid data leaks
void clean(Matrix m){
  //First deallocates rows
  for(int i = 0; i < m.rows; i++){
    free(m.matrix[i]);
  }
  //Then dallocates the matrix
  free(m.matrix);
  //Sets core variables to 0 for safety reasons
  m.rows = 0;
  m.cols = 0;
}

//Multiplies a matix by a single number
void multMatrix(Matrix m, int num){
  //Loops through given matrix m rows
  for(int i = 0; i < m.rows; i++){
    //Loops throiugh columns to get 
    for(int j = 0; j < m.cols; j++){
      //Multiples the values by given num
      m.matrix[i][j] = m.matrix[i][j] * num;
    }
  }
}

//Multiply with a matrix with a matrix and makes a new matix
Matrix matrixMult(Matrix front, Matrix back){
  //New matrix will have # of rows from front and # of columns from back
  Matrix result = constructMatrix(front.rows, back.cols);
  //Keeps track of the sums
  int sum = 0;
  //Loops through rows of new matrix
  for(int i = 0; i < result.rows; i++){
    //Loops through columns
    for(int j = 0; j < result.cols; j++){
      //Loops throgh front and back to get sum
      for(int z = 0; z < front.cols; z++){
        sum = sum + (front.matrix[i][z] * back.matrix[z][j]);
      }
      //Sum is value for result
      result.matrix[i][j] = sum;
      //Resets sum
      sum = 0;
    }
  }
  //returns new matrix
  return result;
}

//Returns a transposed matrix of the matrix provided
Matrix transpose(Matrix m){
  //The resulting matrix will have rows and columns fliped
  Matrix result = constructMatrix(m.cols, m.rows);
  //Loop through the new matrix
  for(int i = 0; i < result.rows; i++){
    for (int j = 0; j < result.cols; j++){
      //Add the values to new matrix
      result.matrix[i][j] = m.matrix[j][i];
    }
  }
  //Return the result
  return result;
}
//Creates a matrix of 2 mareixes added together
Matrix matrixAddition(Matrix a, Matrix b){
  //Resulting matrix has rows and columns equall to a and b
  Matrix result = constructMatrix(a.rows, a.cols);
  //Loops through each spot in new matrix
  for(int i = 0; i < result.rows; i++){
    for(int j = 0; j < result.cols; j++){
      //Adds the matrix together
      result.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
    }
  }
  //Returns resulting matrix
  return result;
}