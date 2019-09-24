#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;   
// Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

   // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int arr[], int n)
{
  // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

   // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

void arrayRandom(int* m, int len){  //Функция для заполнения массивва случайными числами
  srand(time(NULL));                //Иницеализация для функции rand()
  for(int i = 0; i != len; i++){    //Проходим по элементам от 0 до длинны (len-1)
    m[i] = rand() % 100;            //Найти остаток деления на 100 и записать в ячейку
  }                                 //Конец цикла
}                                   //Конец функции

/* Вспомогательная функция для вывода на экран массива размера n*/
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