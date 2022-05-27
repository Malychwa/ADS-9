// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

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
  Node* addNode(Node*, T&);
  int searchNode(Node*, T&);
  int heightTree(Node*);
  void printTree(Node*);
  void delTree(Node*);
  Node* delNode(Node*, T&);
 
 public:
  BST();
  ~BST();
  void add(T&);
  int search(T&) {
    return searchNode(root, value);
  }
  int hight() {
    return heightTree(root);
  }
  void print();
};

template <typename T>
BST<T>::BST():root(nullptr) {}

template<typename T>
BST<T>::~BST() {
  if (root)
    delTree(root);
}

template<typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, T& val) {
  if (root == nullptr) {
    root = new Node;
    root −> value = val;
    root −> count = 1;
    root −> left = root −> right = nullptr;
  } else if (root −> value > val) {
    root −> left = addNode(root −> left, val);
  } else if (root −> value < val) {
    root −> right = addNode(root −> right, val);
  } else {
    root −> count++;
  }
  return root;
}

template<typename T>
  void BST<T>::add(T& val) {
    root = addNode(root, val);
  }

template<typename T>
  int BST<T>::searchNode(Node* root, T& val) {
    if (root == nullptr)
      return 0;
    else if (root -> value == val)
      return root -> count;
    else if (root -> value > val)
      return searchNode(root -> left, val);
    else
      return searchNode(root -> right, val);
  }

template<typename T>
int BST<T>::heightTree(Node* root) {
  if (root == nullptr)
    return 0;
  else {
    int L = heightTree(root -> left);
    int R = heightTree(root -> right);
    return ((L > R)? L:R)+1;
  }
}

template<typename T>
  void BST<T>::printTree(Node* root) {
    if (root == nullptr)
      return;
    printTree(root −> left);
    for (int i =0; i < root −> count; i++)
      std::cout<<root −> value<<" ";
    printTree(root −> right);
  }

template<typename T>
  void BST<T>::print() {
    printTree(root);
  }

template<typename T>
  void BST<T>::delTree(Node* root) {
    if (root == nullptr)
      return;
    else {
      delTree(root −> left);
      delTree(root −> right);
      delete root;
    }
  }

template<typename T>
  typename BST<T>::Node* BST<T>::delNode(typename BST<T>::Node* root,T& value) {
    Node* p,* v;
    if (root == nullptr)
      return root;
    else if (value < root −> value)
      root −> left = delNode(root −> left,value);
    else if (value > root −> value)
      root −> right = delNode(root −> right,value);
    else {
      p = root;
      if (root −> right == nullptr)
        root = root −> left;
      else if (root −> left == nullptr)
        root = root −> right;
      else {
        v = root −> left;
        if (v −> right) {
          while (v −> right −> right)
            v = v −> right;
          root −> value = v −> right −> value;
          root −> count = v −> right −> count;
          p = v −> right;
          v −> right = v −> right −> left;
        } else {
          root −> value = v −> value;
          root −> count = v −> count;
          p = v;
          root −> left = root −> left −> left;
        }
      }
      delete p;
    }
    return root;
  }


#endif  // INCLUDE_BST_H_
