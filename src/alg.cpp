// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> stree;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
  }
  std::string word = "";
  while (!file.eof()) {
    char simb = file.get();
    if ((simb >= 'a' && simb <= 'z') || (simb >= 'A' && simb <= 'Z')) {
      if (temp >= 'A' && temp <= 'Z')
        simb += 'a' - 'A';
      word += simb;
    } else if (word != "") {
      stree.add(word);
      word = "";
    }
  }
  file.close();
  return stree;
}
