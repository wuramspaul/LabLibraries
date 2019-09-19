#include <iostream>
using namespace std;

void printmass(int m[], int n){
    for(int i=0; i != n; i++){
        cout << m[i] << " ";
    }
    cout << endl;
}

int main(){
  int temp;
  int n;
  cout << "Введите размер массива: "; cin >> n;
  int* m = new int[n];  

  srand(1);
  for(int i=0; i != n; i++){
    m[i] = rand() % 100;
  }
  printmass(m,n);

  for(int i = 0; i != n; i++){              
      if(m[i] > m[i+1]){                    
          for(int j = i+1; j != 0; j--){    
              if(m[j] < m[j-1]){            
                  temp = m[j];              
                  m[j] = m[j-1];            
                  m[j-1] = temp;            
              }                             
          }                                 
      }                                     
  } 
  printmass(m,n);                                        
  return 0;
}