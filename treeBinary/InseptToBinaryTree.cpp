#include <iostream>

struct binarytreenode //структура для бинарного дерева
{
  binarytreenode* left; //указатель на левый элемент
  binarytreenode* right;  //указатель на правй элемент
  int elem; //значение эля этого узла
};

void InseptToBinaryTree(binarytreenode *&root, int *n, int* m){  // добавление элемента в двоичное дерево  
  if(root->right != NULL){  //Если правый не указывает на NULL
    if(root->left != NULL){ //И если левый не какзывает на NULL
      InseptToBinaryTree(root->left,n,m); //Рекурсивно вызвать эту функцию для левого элемента корня
    } else {                           //Если левый указывает на ноль
      InseptToBinaryTree(root->right,n,m);//Рукурсивно вызвать функцию на правый элемент корня
    }
  } else {
    binarytreenode* newnode = new binarytreenode; //создаём новый узел дерева
    newnode->elem = m[*n];  //задаём ему значение
    newnode->left = NULL;   //обнуляем левую сторону
    newnode->right = NULL;  //обнуляем правую сторону

    if(root->right == NULL){
      if(root->left == NULL){
        root->left = newnode; //Если левый и правый элемент корня указывают на NULL, то довавить этот новый элемент с лево
        n++;                  //увеличиваем значение индекса массива с которого мы делаем дерево
      } else{ 
        root->right = newnode; //Если левый элемент не указывает на NULL, а правый указывает то добавить новый элемент с права
        n++;                   //увеличиваем значение индекса массива с которого мы делаем дерево
      }
    
    }    
  }
}

void printBinatyTree(binarytreenode* root);
void deleteNodeFromBinaryTree(binarytreenode* node);

int main(){
  binarytreenode* root = NULL;
  return 0;

}