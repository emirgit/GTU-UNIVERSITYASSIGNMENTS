#include "util.h"

int main() {
	//creating a root BST
    struct BST* bst = generateBST("input.txt");
    
    if (bst == NULL) {
        printf("Failed to generate BST.\n");
        return 0;
    }

    
    int choice, value;
    
    do {
        printf("\nBinary Search Tree Menu\n");
        printf("1. Add Node\n");
        printf("2. Remove Node\n");
        printf("3. Search Node\n");
        printf("4. Count Nodes\n");
        printf("5. Get Max Depth\n");
        printf("6. Count Leaf Nodes\n");
        printf("7. Print Tree\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                addNode(bst, value);
                break;
            case 2:
                printf("Enter the value to remove: ");
                scanf("%d", &value);
                removeNode(bst, value);
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                struct Node* foundNode = searchNode(bst->root, value);
                if (foundNode == NULL) {
                    printf("Node not found.\n");
                } 
				else {
                    printf("Node found.\n");
                }
                break;
            case 4:
                printf("Total number of nodes: %d\n", countNodes(bst->root));
                break;
            case 5:
                printf("Maximum depth: %d\n", getMaxDepth(bst->root));
                break;
            case 6:
                printf("Number of leaf nodes: %d\n", countLeafNodes(bst->root));
                break;
            case 7:
                printTree(bst);
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 8);
    
    return 0;
}
