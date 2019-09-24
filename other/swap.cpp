#include <iostream>
using namespace std;

void swap(int* x, int* y);                      //объявления функции для перемещения значений переменных друг между другом
void arrayPrint(int*, int);

int main(){
  int arr[5] = {1,2,3,4,5}; //создаём массив
  arrayPrint(arr,5);  //выводим его
  swap(&arr[0], &arr[4]); //меняем его первый и последний элемент 
  arrayPrint(arr,5); // выводим снова
  return 0;
}

void swap(int* x, int* y){  // реализаци функции обмена элементов
  int temp = *x;            // создаём буферную переменную
  *x = *y;                  // в ячейку x записываем значение y
  *y = temp;                // в ячейку y записываем значения временной переменной
}                           // конец функции

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