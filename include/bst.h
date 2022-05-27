// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include<iostream>

template<typename T>
class BST {
 private:
  struct Node {
  T value;
  int count;
  Node *left;
  Node *right;
  };
  Node *root;
  Node* addNode(Node* root, T val) {
  if (root == nullptr) {
    root = new Node;
    root->value = val;
    root->count = 1;
    root->left = root->right = nullptr;
  } else if (root->value > val) {
    root->left = addNode(root->left, val);
  } else if (root->value < val) {
    root->right = addNode(root->right, val);
  } else {
    root->count++;
  }
  return root;
  }
  int searchNode(Node* root, T val) {
    if (root == nullptr)
      return 0;
    else if (root->value == val)
      return root->count;
    else if (root->value > val)
      return searchNode(root->left, val);
    else
      return searchNode(root->right, val);
  }
  int heightTree(Node* root) {
    if (root == nullptr) {
     return 0;
    } else {
     int L = heightTree(root->left);
     int R = heightTree(root->right);
     return ((L > R)? L:R)+1;
    }
  }
  void printTree(Node* root) {
    if (root == nullptr)
      return;
    printTree(root->left);
    for (int i =0; i < root->count; i++)
      std::cout << root->value << " ";
    printTree(root->right);
  }
  void delTree(Node* root) {
    if (root == nullptr) {
      return;
    } else {
      delTree(root->left);
      delTree(root->right);
      delete root;
    }
  }
  Node* delNode(Node* root, T value) {
    Node* p, * v;
    if (root == nullptr) {
      return root;
    } else if (value < root->value) {
      root->left = delNode(root->left, value);
    } else if (value > root->value) {
      root->right = delNode(root->right, value);
    } else {
      p = root;
      if (root->right == nullptr) {
       root = root->left;
      } else if (root->left == nullptr) {
        root = root->right;
      } else {
        v = root->left;
        if (v->right) {
          while (v->right->right)
            v = v->right;
          root->value = v->right->value;
          root->count = v->right->count;
          p = v->right;
          v->right = v->right->left;
        } else {
          root->value = v->value;
          root->count = v->count;
          p = v;
          root->left = root->left->left;
        }
      }
      delete p;
    }
    return root;
  }

 public:
  BST():root(nullptr) {}
  ~BST() {
  if (root)
    delTree(root);
  }
  void add(T val) {
    root = addNode(root, val);
  }
  int search(T value) {
    return searchNode(root, value);
  }
  int hight() {
    return heightTree(root);
  }
  void print() {
    printTree(root);
  }
};
#endif // INCLUDE_BST_H_
