#include <iostream>
#include <fstream>
using namespace std;

struct stack { // Обявление структуры с именем stack           
  int data;    // Обявление переменной данных 
  stack* next; // Обявление указателя на следующий элемент
};

stack* initStack();             // Функция создания стека
stack* pushStack(stack**);      // Функция добавление элемента
stack* popStack(stack** root);  // Функция извлечения элемента
void   printStack(stack* root); // Функция вывода стека
void   clearStack(stack** root); // Функция очистки стека
int    saveStack(stack* root);   // Функция сохранения стека
int    loatStack(stack** root);  // Функция загрузки стека
void   findPositive(stack* root); 

int inputMenu();  // Функция вызова ввода у пользователя
int menu();       // Функция вызова меню действий

int main(){
  system("clear");
  while(menu() != -1){
    cout << "\n";
  }
  return 0;
}

int inputMenu(){
  int num = 1;
  cout << num++ << ") " << "initStack" << endl;
  cout << num++ << ") " << "pushStack" << endl;
  cout << num++ << ") " << "popStack" << endl;
  cout << num++ << ") " << "printStack" << endl;
  cout << num++ << ") " << "saveStack" << endl;
  cout << num++ << ") " << "loadStack" << endl;
  cout << num++ << ") " << "clearStack" << endl;
  cout << num++ << ") " << "FundPizitive" << endl;
  cout << 0 << ") " << "exit" << endl;
  int res ;
  cin >> res;
  return res;
}

int menu(){
  static stack* stk = nullptr;
  static stack* tempnode;
  switch (inputMenu())
  {
  case 1:
    system("clear");
    cout << "INIT STACK\n";
    stk = initStack();  
    return 1;
    break;
  case 2:
    system("clear");
    cout << "PUSH TO STACK\n";
    if(stk == nullptr) {
      cout << "ERROR : NO INIT STACK\n";
      return -1;
    }
    int tempval;
    tempval = rand() % 20 - 10;
    stack* temp;
    temp = pushStack(&stk); 
    temp->data = tempval;
    cout << "Add to stack : " << tempval << "\n"; 
    return 1;
    break;
  case 3:
    if(stk == nullptr) {
      cout << "ERROR : NO INIT STACK\n";
      return -1;
    }
    system("clear");
    cout << "POP TO STACK\n";
    tempnode = popStack(&stk);
    cout << "VAL IS " << tempnode->data << "\n";
    free(tempnode);
    return 3;
    break;   
  case 4:
    if(stk == nullptr) {
      cout << "ERROR : NO INIT STACK\n";
      return -1;
    }
    cout << "PRINT STACK\n";
    printStack(stk);
    cout << "\n";
    return 4;
    break;   
  case 5:
    if(stk == nullptr) {
      cout << "ERROR : NO INIT STACK\n";
      return -1;
    }
    if (saveStack(stk) == 1 ){
      return 5;
    } else {
      return -1;
    }
    break;
  case 6:
    if (loatStack(&stk) == 1 ){
      return 6;
    } else {
      return -1;
    }
    break;
  case 7:
    cout << "CLEAR STACK\n";  
    clearStack(&stk);
    return 7;
    break;
  case 8:
    cout << "DELETE FIRST POZITIVE VALUE IN STACK\n";
    findPositive(stk);
    return 8;
    break;
  case 0:
    return -1;
    break;
  default:
    cout << "ERROR : NOCERECT INPUT\n"; 
    break;
    return -1;
  }
  return -1;
}

stack* initStack(){
  stack* root = new stack;
  cout << "Enter root val \n";
  cin >> root->data;
  root->next = nullptr;
  return root;
}

stack* pushStack(stack** root){
  stack* node = new stack;
  node->next = *root;
  (*root) = node;
  return node;
}

stack* popStack(stack** root){
  if(root == nullptr) return nullptr;
  stack* temp = *root;
  *root = (*root)->next;
  return temp;
}

void printStack(stack* root){
  if(root == nullptr) return;
  cout << " " << root->data;
  printStack(root->next);
}

int saveStack(stack* root){
  // Создаём файл stack и устанавливаем атрибут записи
  ofstream outFile("stack", ios::out);
  // Проходям по элементам стека и записываем их в стек
  while (root != nullptr){
    // Записываем значение в файл
    outFile.write((char *) &(root->data),sizeof(int));
    // Переходим к очередному элементы
    root = root->next;
  }
  // Закрываем файл
  outFile.close();
  return 1;
}

int loatStack(stack** root){
  // Очищаем стек
  clearStack(root);
  // Создаём временный указатель 
  // для считывание значений из файла
  stack* tempnode;
  // Создаём переменную для считывание
  // значений из файла
  int temp;
  // Открываем файл на запись
  ifstream inFile("stack", ios::in);
  // Пока не достигли конца файла
  while(!inFile.eof()){
    // Считываем значение а переменную
    inFile.read((char*)&temp, sizeof(int));
   
    // Создаём новый узел 
    tempnode = pushStack(root);
    
    // Присваиваем ему считанное значение 
    tempnode->data = temp; 
    cout << (*root)->data << "\n"; // выводим эту переменную
  }
  // Закрываем файл
  inFile.close();
  return 1;
}

// Очистка стека
void clearStack(stack** root){
  // Пока есть елементы
  while ((*root) != nullptr)
  {
    // Создаём указатель на элемент стека
    stack* temp;
    // Берерёём очередной элемент
    temp = popStack(root);
    // освобождаем память этого элемента
    delete temp;
  }
}


// Функция удаление первого положительного элемента стека
void findPositive(stack* root){
  // Елси 1 элемент отрицательный элемент
  // то удаляем его и возращаем функцию
  if(root->data > 0 ){
    *root = *(root->next);
    return;
  }
  // Создаём указатель на элемент стека
  // который будет использоватся для удаления элемента
  stack* temp;
  while (root->next != nullptr) // Проходим по стеку
  {
    // Если найдет отрицательный элемент
    if(root->next->data > 0){
     // Указатель укзывает на элемент с отрицательным значением
     temp = root->next; 
     // Передвигаем указатель на следующий элемент 
     (*root).next = root->next->next; 
     // Удаляем предыдущий элемент
     delete temp;
     // Возращаем функцию
     return; 
    }
    // Если этот элемент с положительным значением
    // переходим на следующий элемент
    root = root->next;
  }
}