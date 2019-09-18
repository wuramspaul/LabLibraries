#include <iostream>

//m-массив, n - размер, inx - индекс элемента на который которого нужно вставить, e - элемент 
void inseptElemMass(int* m, int* n, int idx, int e){
  *n = *n+1;                    //увеличиваем значение длины для исходного массива
  int* tempmass = new int[*n];  //создаём временый массив
  
  for(int i = 0; i < idx; i++){ // записываем элементы до индекса
    tempmass[i] = m[i];     
  }
  tempmass[idx] = e;            //записываем на место индекса значение элемента для вставки
  for(int i = idx; i < *n-1; i++){  //записываем значение после
    tempmass[i+1] = m[i];
  }
  for(int i = 0; i < *n; i++){  //перезаписываем исходный массив
    m[i] = tempmass[i];
  }
}

int main(){

  return 0;
}