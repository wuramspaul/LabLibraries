#include <iostream>

void deleteMatrix(int** mtx, int n, int m ){
  for(int i = 0; i != n; i++){
    mtx[i] = 0;
    delete [] mtx[i];
  }
  delete [] mtx;
  mtx = 0;
}

int main(){
  return 0;
}