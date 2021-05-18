#include <iostream>
#include <stdlib.h>
#include "functions.h"

using namespace std;

int main() {
    int option;
    int size;
    int **mat1;
    int **mat2;
    int **soma;
    int **multi;
    int i, j;


  do{
    cout << "\n[1] soma de matrizes " << endl;
    cout << "[2] multiplicação de matrizes " << endl;
    cout << "[0] sair" << endl;
    cout << "Digite a opcao desejada: ";
    cin >> option;
    cout << endl;

    switch(option){
      case 0:
        cout << "Obrigado por usar minha calculadora de matrizes, volte sempre!!!" << endl;
        break;
      case 1: //soma  
        size = matrixSize();
        cout << endl;

        mat1 = alocMatrix(size);
        mat2 = alocMatrix(size);
        writeMatrix(size, mat1);
        writeMatrix(size, mat2);
        cout << endl;
        soma = sumMatrix(size, mat1, mat2);

        printMatrix(size, soma);
        

        break;
      case 2: //multiplicaçao
        size = matrixSize();
        mat1 = alocMatrix(size);
        mat2 = alocMatrix(size);
        writeMatrix(size, mat1);
        writeMatrix(size, mat2);
        cout << endl;
        multi = multMatrix(size, mat1, mat2);
        printMatrix(size, multi);
        break;
      default:
        cout << "\nDigito inválido, tente novamente." << endl;
    }
    
  } while(option != 0);

  freeMatrix(size, mat1);
  freeMatrix(size, mat2);

  

}