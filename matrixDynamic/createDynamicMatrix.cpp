#include <iostream>

int** createMatrix(int n, int m){
  int **matx = new int* [m]; 
  for (int i = 0; i < m; i++){
     matx[i] = new int [n]; 
  }
  return matx;
}

int main(){

  return 0;
}