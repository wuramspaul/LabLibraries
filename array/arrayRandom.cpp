#include <iostream>
using namespace std;

void arrayRandom(int* m, int len){  //Функция для заполнения массивва случайными числами
  srand(time(NULL));                //Иницеализация для функции rand()
  for(int i = 0; i != len; i++){    //Проходим по элементам от 0 до длинны (len-1)
    m[i] = rand() % 100;            //Найти остаток деления на 100 и записать в ячейку
  }                                 //Конец цикла
}                                   //Конец функции

int main(){
  int len = 10;
  int* m = new int[10];
  arrayRandom(m,len);
  for(int i = 0; i != len; i++){
    cout << m[i] << " ";
  }
  cout << endl;
  return 0;
}