#include "util.h"

int main(){
	
	Node *head = NULL;
	
    //filling and printing the linked list
	fillLinkedList(&head);
	print_linked_list(head);

    //serializing and freeing the linked list
    serializeLinkedList(head);
    free_linked_list(head);

    head = NULL;
    //deserializing and printing the linked list
    deserializeLinkedList(&head);
    print_linked_list(head);

    //freeing the linked list after using
    free_linked_list(head);
	
	
	
	return (0);
}
