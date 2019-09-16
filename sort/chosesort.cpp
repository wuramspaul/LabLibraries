#include <iostream>
using namespace std;

void printmass(int m[], int n){
    for(int i=0; i != n; i++){
        cout << m[i] << " ";
    }
    cout << endl;
}

int main(){
  int tmp = 0;      
  int min = 0;      
  int n   = 0;        
  cout << "Введите размер массива: "; cin >> n;
  int* m = new int[n];  

  srand(1);
  for(int i=0; i != n; i++){
    m[i] = rand() % 100;
  }
  printmass(m,n);
  for(int i = 0; i < n; i++){     
      min = i;                    
      for(int j = i; j < n; j++){ 
          if(m[min] > m[j]){      
              min = j;            
          }                       
      }                           
                                  
      tmp = m[min];               
      m[min] = m[i];              
      m[i] = tmp;                 
  }
  
  printmass(m,n);
  delete[] m;
  m = 0;  
  return 0;
}