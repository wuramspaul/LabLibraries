#include <iostream>
using namespace std;

int Linearsearch(int m[], int n, int key){
  int k;    // 
  for(int i = 0;i != n; i++){
    if (m[i] == key){
      k = i;
    }
  }   //Итерация i
  return k;
}

int main(){
  int m[10] = {1,2,3,4,5,6,7,8,9,10};
  cout << Linearsearch(m,10,4) << endl; 

  return 0;
}