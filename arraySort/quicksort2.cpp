#include <iostream> //подключение библиотеки ввода/вывода
using namespace std;//задаём пространство для поиска имён

void arrayPrint(int* m, int n);                 //объявления функции для вывода массива
void arrayRandom(int* m, int len);              //объявления функции для заполнения массива случайными числами
void quicksort(int* arr, int left, int right);  //объявления функции для быстрой сортировки
void swap(int* x, int* y);                      //объявления функции для перемещения значений переменных друг между другом

int main(){
  int len; cout << "Введите количества элементов массива : "; cin >> len; //иницализируем переменную для длинны массива и задаём ей значения
  int* arr = new int[len]; arrayRandom(arr,len);                          //создаём динамический массив и заполняем его случайными элементами
  cout << "Массив до сортировки                 : "; arrayPrint(arr,len); //выводим массива до сортировки 
  quicksort(arr,0,len-1);                                                 //сортируем массив
  cout << "Массив после сортировки              : "; arrayPrint(arr,len); //выводим массив после сортировки
  return 0;
}

void quicksort(int* arr, int left, int right){  //реализациия функции быслтой сортировки
  if(!(left < right)) return; //если меньше 2 возращаем функциию 
  int key = right;           // ключевой элемент, относительно которого будет происходить сортировка 
  int k = left;             // индекс элемента в который будем записывать все элементы меньше ключевого
  int i = left;             // итератор для прохода по элементам массива
  while(i != right){        // цикл прохода элементов массива 
    if(arr[i] < arr[key]){  // если элемент элемент меньше ключевого, то
      swap(&arr[i],&arr[k]);// записываем его в конец массива 
      k++;                  // увеличеваем значения индекса для записи элемента
    }                       //конец условия
    i++;                    // переходим на следущий элемент
  }                         //конец цикла
  swap(&arr[key],&arr[k]);  //перемещаем ключевой элемент на место разделения больших и меньших элементов 
  quicksort(arr,left,k-1);  //рекурсивно вызываем эту функцию для левого подмассива 
  quicksort(arr,k+1,right); //рекурсивно вызываем эту фунцию для правого подмассива
}

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

void arrayRandom(int* m, int len){  //Функция для заполнения массивва случайными числами
  srand(time(NULL));                //Иницеализация для функции rand()
  for(int i = 0; i != len; i++){    //Проходим по элементам от 0 до длинны (len-1)
    m[i] = rand() % 10;            //Найти остаток деления на 100 и записать в ячейку
  }                                 //Конец цикла
}                                   //Конец функции

void swap(int* x, int* y){  // реализаци функции обмена элементов
  int temp = *x;  // создаём буферную переменную
  *x = *y;  // в ячейку x записываем значение y
  *y = temp; // в ячейку y записываем значения временной переменной
} // конец функции