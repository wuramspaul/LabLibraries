#include <iostream>
using namespace std;

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
void swap(int* m, int n, int k){
  int temp = m[n];
  m[n] = m[k];
  m[k] = temp;
}

void maxElem(int* m, int root, int left, int right){
  if( m[left] > m[root]){
    swap(m,left,root); 
    
  }
  if( m[right] > m[root]){
    swap(m,right,root); 
    
  }
}

void arrayRandom(int* m, int len){  //Функция для заполнения массивва случайными числами
  srand(time(NULL));                //Иницеализация для функции rand()
  for(int i = 0; i != len; i++){    //Проходим по элементам от 0 до длинны (len-1)
    m[i] = rand() % 100;            //Найти остаток деления на 100 и записать в ячейку
  }                                 //Конец цикла
}                                   //Конец функции


void printB(int* m, int n, int len){
  cout << m[2*n+1] << " " <<  m[2*n+2]<< "   ";
}

void Heapsort(int* m, int len){

}

void treeP(int* m, int n, int len){
  cout<< m[n] << endl;
  printB(m,n,len);
  cout << endl;
  printB(m,n+1,len);
  printB(m,n+2,len);
  cout << endl;
}
int main(){
  int len = 8;
  int* m = new int[len];  
  arrayRandom(m,len);
  treeP(m,0,len);
  

  
  return 0;
}