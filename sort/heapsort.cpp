#include <iostream>
struct binarytreenode
{
  binarytreenode* left;
  binarytreenode* right;
  int elem;
};

void addToBinaryTree(binarytreenode *&root, int *n, int* m){  // добавление элемента в двоичное дерево
  binarytreenode* newnode = new binarytreenode;
  newnode->elem = m[*n]; 
  newnode->left = NULL;
  newnode->right = NULL;
  if(root->right == NULL){
    if(root->left == NULL){
      root->left = newnode;
      n++;
    } 
    root->right = newnode;
  }
  if(root->right != NULL){
    if(root->left != NULL){
      addToBinaryTree(root->left,n,m);
    }
     addToBinaryTree(root->right,n,m);
  }
}

int main(){
  binarytreenode* root = NULL;

  return 0;
}