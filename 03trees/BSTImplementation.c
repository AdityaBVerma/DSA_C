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

struct Node* getSuccessor (struct Node* curr) {
    curr = curr->right;
    while (curr!=NULL && curr->left!=NULL){
        curr = curr->left;
    }
    return curr;
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

struct Node* delNode ( struct Node* root, int x){
    if (root == NULL ) return root;
    
    if (root->key > x) {
        root->left = delNode(root->left, x);
    } else if (root->key < x) {
        root->right = delNode(root->right, x);
    } else {
        
        if ( root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        struct Node* succ = getSuccessor(root);
        root->key = succ->key;
        root->right = delNode(root->right, succ->key);
        
    }
    return root;
}

void inorder (struct Node* node) {
    if (node!=NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

int main() {
    
    struct Node* root = newNode(50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 10);
    root = insertNode(root, 60);
    root = insertNode(root, 70);
    root = insertNode(root, 40);
    root = insertNode(root, 80);
    inorder(root);
    root = delNode(root, 60);
    printf("\n");
    inorder(root);
    
    return 0;
}