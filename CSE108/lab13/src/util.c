#include "util.h"

//create note function creats a node for ease
struct Node* createNode(double value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->Value = value;
    newNode->LeftNode = NULL;
    newNode->RightNode = NULL;
    
	return newNode;
}

//insert node function append node to root respection to its values
struct Node* insertNode(struct Node* currentNode, double value) {
    //if root is null create value and return it
    if (currentNode == NULL) {
        return createNode(value);
    }
    
    //if value is smaller than current value , it will be putted left
    if (value < currentNode->Value) {
        currentNode->LeftNode = insertNode(currentNode->LeftNode, value);
    } 
    //if value is greather than current value , it will be putted right
    else if (value > currentNode->Value) {
        currentNode->RightNode = insertNode(currentNode->RightNode, value);
    }
    
    return currentNode;
}

struct BST* generateBST(const char* filename) {
    FILE* file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("file not found .\n");
        return NULL;
    }
	
	//creating bst
	struct BST* bst;
    int value;
    
    //reading first character
    fscanf(file, "%d", &value);

	//creating with malloc
	bst = (struct BST*)malloc(sizeof(struct BST));
    bst->root = createNode(value);

	//reading int by int and insert it to root
    while (fscanf(file, "%d", &value) != EOF) {
        insertNode(bst->root, value);
    }

	//close and return
    fclose(file);
    return bst;
}

//add node adds Node to root
void addNode(struct BST* bst, double value) {
    bst->root = insertNode(bst->root, value);
}

// basically find minNode it wil lgo to left
struct Node* findMinNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->LeftNode != NULL) {
        current = current->LeftNode;
    }
    return current;
}

//deleteNode uses the deleting method
struct Node* deleteNode(struct Node* root, double value) {
    if (root == NULL) {
        return root;
    }
    // finding the falues
    if (value < root->Value) {
        root->LeftNode = deleteNode(root->LeftNode, value);
    }
    else if (value > root->Value) {
        root->RightNode = deleteNode(root->RightNode, value);
    }
    else {
    //after fanding checking wheter there is child or not
        if (root->LeftNode == NULL) {
        //if there is one child returning the child
            struct Node* temp = root->RightNode;
            free(root);
            return temp;
        }
        else if (root->RightNode == NULL) {
            struct Node* temp = root->LeftNode;
            free(root);
            return temp;
        }
        
        //else it has twho child 
        struct Node* temp = findMinNode(root->RightNode);
        root->Value = temp->Value;
        root->RightNode = deleteNode(root->RightNode, temp->Value);
    }
    
    return root;
}

//it calling deleteNode directly
void removeNode(struct BST* bst, double value) {
    bst->root = deleteNode(bst->root, value);
}

//it counting all nodes (meaning integer in the list)
int countNodes(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + countNodes(node->LeftNode) + countNodes(node->RightNode);
}

//it is searching like adding by checking its value
struct Node* searchNode(struct Node* node, double value) {
    if (node == NULL || node->Value == value) {
        return node;
    }
    
    if (value < node->Value) {
        return searchNode(node->LeftNode, value);
    }
    else {
        return searchNode(node->RightNode, value);
    }
}

//it goes throgh nodes recursively and count depth
//it is like backtracking algorithm
int getMaxDepth(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    else {
        int leftDepth = getMaxDepth(node->LeftNode);
        int rightDepth = getMaxDepth(node->RightNode);

        if (leftDepth > rightDepth) {
            return leftDepth + 1;
        }
        else {
            return rightDepth + 1;
        }
    }
}

//all childless are leaf
int countLeafNodes(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    
    if (node->LeftNode == NULL && node->RightNode == NULL) {
        return 1;
    }
    
    return countLeafNodes(node->LeftNode) + countLeafNodes(node->RightNode);
}

//printing in order
void printInOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    
    printInOrder(node->LeftNode);
    printf("%.2lf ", node->Value);
    printInOrder(node->RightNode);
}

//pringing pre order
void printPreOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    
    printf("%.2lf ", node->Value);
    printPreOrder(node->LeftNode);
    printPreOrder(node->RightNode);
}

//printing post order
void printPostOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    
    printPostOrder(node->LeftNode);
    printPostOrder(node->RightNode);
    printf("%.2lf ", node->Value);
}

//print Tree menu
void printTree(struct BST* bst) {
    int choice;
    printf("Choose the mod of printing:\n");
    printf("\t1. In-order\n");
    printf("\t2. Pre-order\n");
    printf("\t3. Post-order\n");
    printf("\t4. Level-order\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("In-order traversal: ");
            printInOrder(bst->root);
            break;
        case 2:
            printf("Pre-order traversal: ");
            printPreOrder(bst->root);
            break;
        case 3:
            printf("Post-order traversal: ");
            printPostOrder(bst->root);
            break;
        case 4:
            printf("Level-order traversal: ");
            //printLevelOrder(bst->root);
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }
    
    printf("\n");
}
