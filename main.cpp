
#include "bits/stdc++.h"
#include <stdlib.h>
#include "functions.h"

using namespace std;



int main() {
    int option;
    int tam_linhas, tam_colunas;

    Matrix mat1(0,0);
    Matrix mat2(0,0);

    Matrix soma(0,0);
    Matrix multi(0,0);
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
        matrixSize(&mat1);

        resizeMatrix(&mat1);

        matrixSize(&mat2);
        resizeMatrix(&mat2);


        mat2.valores.resize(mat2.tam_linhas);
        for(int i = 0; i < mat2.tam_linhas; i++){
          mat2.valores[i].resize(mat2.tam_colunas);
        }

        writeMatrix(&mat1);

        writeMatrix(&mat2);



    

        sumMatrix(mat1, mat2, &soma);
        printMatrix(soma);



        break;
      case 2: //multiplicaçao
        matrixSize(&mat1);
        resizeMatrix(&mat1);

        matrixSize(&mat2);
        resizeMatrix(&mat2);

        writeMatrix(&mat1);
        writeMatrix(&mat2);
        
      
        multMatrix(mat1, mat2, &multi);

        printMatrix(multi);
        break;
      default:
        cout << "\nDigito inválido, tente novamente." << endl;
    }
    
  } while(option != 0);

 
  

}