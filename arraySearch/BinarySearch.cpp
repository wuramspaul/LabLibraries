#include <iostream>
using namespace std;
int BinarySearch(int* m, int key, int len){
  int left = 0;
  int right = len;
  int k = 1;
  int h = 0;
  while(k){
    int mid = (right + left)/2;
    if (m[mid] == key){
      k = 0;
      return mid;
    }
    if(m[mid] < key){
      left = mid;

    }
    if(m[mid] > key){
      right = mid;

    }
    std::cout << left << ":"<< right << std::endl;
  }
  return -1;
}

void printmass(int m[], int n){
    for(int i=0; i != n; i++){
        cout << m[i] << " ";
    }
    cout << endl;
}

int main(){
  int len = 10;
  int* m = new int[len];
  srand(time(NULL));
  for(int i = 0; i != len; i++){
    m[i] = rand() % 100;
  }
  int min;
  int tmp;
  for(int i = 0; i < len; i++){     
      min = i;                    
      for(int j = i; j < len; j++){ 
          if(m[min] > m[j]){      
              min = j;            
          }                       
      }                           
                                  
      tmp = m[min];               
      m[min] = m[i];              
      m[i] = tmp;                 
  }

  printmass(m,len);
  int key; std::cout << "введиле key" << std::endl; cin >> key;
  std::cout << BinarySearch(m,key,len) << std::endl;

  return 0;
}