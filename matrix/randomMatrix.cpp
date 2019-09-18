#include <iostream>

void randomMatrix(int** mtx, int n, int m, int d){
  srand(time(NULL));
  for(int i = 0; i != m;i++){
    for(int j = 0; j != n;j++){
      mtx[i][j] = rand() % d;
    }
  }
}

int main(){
  return 0;
}