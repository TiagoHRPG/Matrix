#include <iostream>
#include <stdlib.h>

using namespace std;

int matrixSize(){
  int size;
  std::cout << "Digite a ordem da sua matriz quadrada: ";
  std::cin >> size;
  return size;
}

int **alocMatrix(int size){
  int i;
  int **mat;

  mat = (int **) malloc (size*sizeof(int *));
  if(mat == NULL){
    std::cout << "erro de alocação" << std::endl;
    return (NULL);
    
  }
  for(i = 0; i < size; i++){
    mat[i] = (int *) malloc (size*sizeof(int));
    if(mat[i] == NULL){
      cout << "erro de alocação" << endl;
      return(NULL);
    }
  }
  return(mat);

}

void freeMatrix(int size, int **mat){
  int i;
  for(i=0; i < size; i++){
    free(mat[i]);
  }
  free(mat);
}

void writeMatrix(int size, int **mat){
  int i, j;


  cout << "Digite a matriz: \n";
  for(i=0; i < size; i++){
    for(j=0; j < size; j++){
      cin >> mat[i][j];
    }
  } 

}

int **sumMatrix(int size, int **mat1, int **mat2){
  int i, j;
  int **sum;

  sum = alocMatrix(size);


  for(i=0; i < size; i++){
    for(j=0; j < size; j++){
      sum[i][j] = mat1[i][j] + mat2[i][j];
    }
  }

  return (sum);
}

int **multMatrix(int size,int **mat1,int **mat2){
  int i, j, k;
  int **mult;
  mult = alocMatrix(size);
  for(i = 0; i < size; i++){
    for(j = 0; j < size; j++){
      mult[i][j] = 0;
    }
  }
  for(i = 0; i < size; i++){
    for(j = 0; j < size; j++){
      for(k = 0; k < size; k++){
        mult[i][j] += mat1[i][k]*mat2[k][j]; 
      }
    }
  }

  return (mult);
}

void printMatrix(int size, int **mat){
  int i, j;
  for(i=0; i < size; i++){
    for(j=0; j < size; j++){
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}