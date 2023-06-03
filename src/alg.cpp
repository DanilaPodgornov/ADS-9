// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

bool isLetter(char c) {
    return c >= 'a' && c <= 'z';
}

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
  
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }

    while (!file.eof()) {
        char ch;
        std::string word;
        while (file.get(ch)) {
            if (ch >= 'A' && ch <= 'Z') {
                ch = tolower(ch);
            }
            if (isLetter(ch)) {
                word += ch;
            } else {
                tree.add(word);
                word.clear();
            }
        }
    }
    file.close();
    return tree;
}
