// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 private:
    struct Node {
        T value;
        int counter;
        int depthNode;
        Node* left;
        Node* right;
    };
    Node* root;
    int depthTree = -1;
    Node* addNode(Node* root, T value, int depth) {
        if (nullptr == root) {
            root = new Node;
            root->value = value;
            root->counter = 1;
            root->depthNode = depth;
            if (depth > depthTree) {
                depthTree = depth;
            }
            root->left = root->right = nullptr;
        } else if (value < root->value) {
            root->left = addNode(root->left, value, ++depth);
        } else if (value > root->value) {
            root->right = addNode(root->right, value, ++depth);
        } else {
            root->counter++;
        }
        return root;
    }

    int searchNode(Node* root, T value) {
        if (nullptr == root) {
            return -1;
        } else if (value == root->value) {
            return root->counter;
        } else if (value < root->value) {
            return searchNode(root->left, value);
        } else if (value > root->value) {
            return searchNode(root->right, value);
        }
        return -1;
    }

 public:
    BST() {
        root = nullptr;
    }

    void add(T value) {
        root = addNode(root, value, 0);
    }

    int depth() {
        return depthTree;
        //return root->depth;
    }

    int search(T value) {
        return searchNode(root, value);
    }
};
#endif  // INCLUDE_BST_H_
