#ifndef _UTIL_H_
#define _UTIL_H_

#include<stdio.h>
#include<stdlib.h>

struct Node {
    double Value;
    struct Node* LeftNode;
    struct Node* RightNode;
};

struct BST {
    struct Node* root;
};

struct Node* createNode(double value);

struct Node* insertNode(struct Node* currentNode, double value);

struct BST* generateBST(const char* filename);

void addNode(struct BST* bst, double value);

struct Node* findMinNode(struct Node* node);

struct Node* deleteNode(struct Node* root, double value);

void removeNode(struct BST* bst, double value);

int countNodes(struct Node* node);

struct Node* searchNode(struct Node* node, double value);

int getMaxDepth(struct Node* node);

int countLeafNodes(struct Node* node);

void printInOrder(struct Node* node);

void printPreOrder(struct Node* node);

void printPostOrder(struct Node* node);

void printTree(struct BST* bst);

#endif /* _UTIL_H_ */
