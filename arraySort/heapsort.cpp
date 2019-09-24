#include <iostream>
using namespace std;

void heapify(int arr[], int len, int root){
  int max = root;         // считаем что самый больщой элемент это корень
  int left = 2*root + 1;  // индекс левого элемента
  int right = 2*root + 2; // индекс правого элемента
  if (left < len && arr[left] > arr[max])   // если левый элемент больше максимального, то
    max = left;                             // считаем что максимальный элемент левый 
  if (right < len && arr[right] > arr[max]) // если правый элемент больше маскимального, то
    max = right;                            // считаем что максимальный элемент правый 
  if (max != root){             // если максимальный элемент не корень, то
    swap(arr[root], arr[max]);  // меняем местами элементами, с большим и меньшим индексом
    heapify(arr, len, max);     // применяем эту функцию для для поддерева с бывшим максимальным элементом
  }
}


void heapSort(int arr[], int n){       // функция сортировки пирамидой
  for (int i = n / 2 - 1; i >= 0; i--) // создаём из массива кучу с большим элементом в корне
    heapify(arr, n, i);                // вызываем сортировку кучи для каждого iэлемента
  for (int i=n-1; i>=0; i--) { // цикл который проходит с конца массива и до начала
    swap(arr[0], arr[i]);      // перемещаем максимальный элемент в конец массива
    heapify(arr, i, 0);        // сортируем кучу с уменьшиным количество элементов
}
}

void arrayRandom(int* m, int len){  //Функция для заполнения массивва случайными числами
  srand(time(NULL));                //Иницеализация для функции rand()
  for(int i = 0; i != len; i++){    //Проходим по элементам от 0 до длинны (len-1)
    m[i] = rand() % 100;            //Найти остаток деления на 100 и записать в ячейку
  }                                 //Конец цикла
}                                   //Конец функции

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{   
    int len = 10;
    int* arr = new int[len];
    arrayRandom(arr,len);
    printArray(arr, len);
    heapSort(arr, len);
    printArray(arr, len);
}