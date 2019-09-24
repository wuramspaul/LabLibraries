#include <iostream>
using namespace std;

//Функция вывода элементов массива
//с облостью определения 0..99
void arrayPrint(int*, int);
void arrayPrint(int* m, int n){  
  for(int i= 0; i != n; i++){
    if(m[i] > 10 || m[i] == 10 ){   //Если элемент больше 10
      cout << m[i] <<  " ";         //просто выводим значение с после него ставим пробелом
    
    } else {                        //Если элемент меньше нуля
      cout << " " << m[i] <<  " ";  //выводим сначало дополнительный символ впереди
    }
    
  }
  cout << "\n"; //После вывода массива переводим курсор на следующую строку
}

int main(){
  int len = 10;
  int* m = new int[10];
  srand(time(NULL));
  for(int i = 0; i != len; i++){
    m[i] = rand()%100;
  }
  arrayPrint(m,len);
  
  return 0;
}