#include <iostream>
using namespace std;

void arrayRandom(int* m, int len){  //Функция для заполнения массивва случайными числами
  srand(time(NULL));                //Иницеализация для функции rand()
  for(int i = 0; i != len; i++){    //Проходим по элементам от 0 до длинны (len-1)
    m[i] = rand() % 100;            //Найти остаток деления на 100 и записать в ячейку
  }                                 //Конец цикла
}                                   //Конец функции

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


// m - массив, n - кол-во элементов, idx - индекс удоляемого элемента
void arrayDeleteElem(int* m, int* n, int idx){ 
  int* tempmass = new int[*n-1];  //создаём временный массив размером меньше одного элемента из исходного
  for(int i = 0; i != idx; i++){  //записываем элементы в временный массив до индекса элемента для удоления
    tempmass[i] = m[i]; 
  }
  for(int j = idx+1; j != *n; j++){ // пропускаем 1 элемент и записываем дальше
    tempmass[j-1] = m[j];
  }
  for(int i = 0; i != *n-1; i++){ //перезаписываем исходный массив
    m[i] = tempmass[i];
  }
  delete[] tempmass; //удоляем временный массив
  *n = *n-1;  //уменьшаем значение длинны для исходного массива
}

int main(){
  int len = 10;
  int* m = new int[len];
  arrayRandom(m,len);
  arrayPrint(m,len);
  cout << "Массив после удоления :" << endl;
  arrayDeleteElem(m,&len,0);     // Удаляем первый
  arrayDeleteElem(m,&len,len-1); // Удаляем последний
  arrayPrint(m,len);
  return 0;
}
