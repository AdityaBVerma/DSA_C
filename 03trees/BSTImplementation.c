#include <stdio.h>
#include<stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode ( int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = item;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode (struct Node* node, int x){
    if (node == NULL) return newNode(x);
    
    if (node->key == x) return node;
    
    if (node->key > x ) {
        node->left = insertNode(node->left, x);
    } else if (node->key < x) {
        node->right = insertNode(node->right, x);
    }
    return node;
}

void inorder (struct Node* node) {
    if (node!=NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

int main() {
    // Write C code here
    struct Node* root = newNode(50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 10);
    root = insertNode(root, 60);
    root = insertNode(root, 70);
    root = insertNode(root, 40);
    root = insertNode(root, 80);
    inorder(root);

    return 0;
}