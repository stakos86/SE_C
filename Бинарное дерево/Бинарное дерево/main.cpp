//
//  main.cpp
//  Бинарное дерево
//
//  Created by Станислав Егоров on 01.03.2024.
//

// Binary Tree in C++

#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinarySearchTree {};

// New node creation
Node* AddNode(int data) {
    Node* result = new Node;

    result->data = data;

    result->left = nullptr;
    result->right = nullptr;

    return result;
}

// Traverse Preorder
void TraversePreOrder(Node* temp) {
    if (temp != NULL)
    {
        cout << " " << temp->data; // вывод
        TraversePreOrder(temp->left); // левый отросток
        TraversePreOrder(temp->right); // правый отросток
    }
}

// Traverse Inorder

void TraverseInOrder(Node* temp) {
    if (temp != NULL)
    {
        cout << " " << temp->data; // вывод
        TraverseInOrder(temp->left); // левый отросток
        TraverseInOrder(temp->right); // правый отросток
    }
}

// Traverse Postorder
void TraversePostOrder(Node* temp) {
    if (temp != NULL)
    {
        cout << " " << temp->data; // вывод
        TraversePostOrder(temp->left); // левый отросток
        TraversePostOrder(temp->right); // правый отросток
    }
}

// Insert a node
Node* insert(struct Node* node, int key) {
    // Return a new node if the tree is empty
    if (node == NULL) return AddNode(key);

    // Traverse to the right place and insert the node
    if (key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

// Find the inorder successor
Node* MinValueNode(Node* node) {
    Node* current = node;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node* FindElement(Node* node, int data) {
    if (node == NULL) return NULL;
    if (node->data == data) return node;

    if (data < node->data)
        return FindElement(node->left, data);

    return FindElement(node->right, data);
}



int main() {
    Node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 11);
    root = insert(root, 9);

    Node* three = FindElement(root, 3);
    if (three == NULL)
    {
        std::cout << "\nElement 3 is not found\n";
    }
    else {
        std::cout << "\nElement 3 is at " << three << "\n";
    }
}
