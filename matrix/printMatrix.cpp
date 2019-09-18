#include <iostream>
using namespace std;

void printmatrix(int** mass, int n, int m){
  for(int i = 0; i != m;i++){
    for(int j = 0; j != n;j++){
      if(mass[i][j] > 10 || mass[i][j] == 10){
        cout << mass[i][j] << " "; 
      } else {
        cout <<" "<< mass[i][j] << " ";
      }
    }
    cout << "\n";
  }
}

int main(){

}