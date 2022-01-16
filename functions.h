#include <iostream>
#include <stdlib.h>

using namespace std;

struct Matrix{
  int tam_linhas, tam_colunas;
  vector<vector<float>> valores;
  

  Matrix(int tam_linhas=0, int tam_colunas=0){
    valores.resize(tam_linhas);
    for (int i; i < tam_linhas; i++){
      valores[i].resize(tam_colunas);
    }
  }
  
};

void resizeMatrix(Matrix *m){
	(*m).valores.resize((*m).tam_linhas);
	for(int i = 0; i < (*m).tam_linhas; i++){
		(*m).valores[i].resize((*m).tam_colunas);
	}		
}

void matrixSize(Matrix *m){
  int tam_linhas, tam_colunas;
  cout << "Digite o número de linhas e colunas da sua matriz: ";
  cin >> tam_linhas >> tam_colunas;

  (*m).tam_linhas = tam_linhas;
  (*m).tam_colunas = tam_colunas;
}

void writeMatrix(Matrix *m){

  int i, j;

  cout << "Digite a matriz: \n";
  for(i = 0; i < (*m).tam_linhas; i++){
    for(j = 0; j < (*m).tam_colunas; j++){
      cin >> (*m).valores[i][j];
    }
  } 

}

void sumMatrix(Matrix mat1, Matrix mat2, Matrix *soma){

  int i, j;

  if(mat1.tam_linhas != mat2.tam_linhas || mat1.tam_colunas != mat2.tam_colunas){
    cout << "Não foi possível realizar a operação - Matrizes de tamanhos diferentes";
    return;
  }

  (*soma).tam_linhas = mat1.tam_linhas;
  (*soma).tam_colunas = mat1.tam_colunas;

  resizeMatrix(&(*soma));

  for(i=0; i < (*soma).tam_linhas; i++){
    for(j=0; j < (*soma).tam_colunas; j++){
      (*soma).valores[i][j] = mat1.valores[i][j] + mat2.valores[i][j];
    }
  }

}

void multMatrix(Matrix mat1,Matrix mat2, Matrix *multi){
  int i, j, k;

  if(mat1.tam_colunas != mat2.tam_linhas){
    cout << "Não foi possível realizar a operação - num. de linhas diferente do num. de colunas" << endl;
    return;
  }

  (*multi).tam_linhas = mat1.tam_linhas;
  (*multi).tam_colunas = mat2.tam_colunas;

  resizeMatrix(&(*multi));

  for(i = 0; i < (*multi).tam_linhas; i++){
    for(j = 0; j < (*multi).tam_colunas; j++){
      for(k = 0; k < mat1.tam_colunas; k++){
        (*multi).valores[i][j] += mat1.valores[i][k] * mat2.valores[k][j]; 
      }
    }
  }


}

void printMatrix(Matrix m){
  int i, j;
  for(i=0; i < m.tam_linhas; i++){
    for(j=0; j < m.tam_colunas; j++){
      cout << m.valores[i][j] << " ";
    }
    cout << endl;
  }
}
