#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define VIP 4
#define OD 3
#define VETERAN 2
#define NORMAL 1
#define DATABASE "customer.txt"


typedef struct Customer {
    char name[50];
    int age;
    char priority_group_name[20];
    int priority_level;
    struct Customer* prev;
    struct Customer* next;
}Customer ;

Customer* insert_Customer(Customer *root,char name[], int age, char priority_group_name[]);
Customer* create_Customer(char name[], int age, char priority_group_name[], int priority_level);
Customer* remove_Customer(Customer* root, char name[]);
Customer* changePriority(Customer *root, char name[], int new_plevel);
void display_Customers(Customer* root);
Customer* search_Customer(Customer* root, char name[]);
void print_file(Customer * root);

int main() {
	int choice, new_plevel;
	char name[50];
    int age;
    char priority_group_name[20];
	Customer *root;
	root = NULL;
	
	do {
		printf("***********************************\n");
		printf("Welcome to the ABC Bank\n\n");
		printf("1-Insert new customer\n");
		printf("2-Remove customer\n");
		printf("3-Display customers in order\n");	
		printf("4-Search a customer\n");
		printf("5-Change priority settings\n");
		printf("6-Exit\n\n");
		
		printf("Please select an option: ");
		scanf("%d",&choice); 
		
		switch (choice) {
			case 1:
                printf("Please enter customer's Name: ");
                scanf("%s", name);
                    printf("Please enter customer Age: ");
                scanf("%d", &age);
                printf("Please enter customer's Priority Group(VIP, OD, VETERAN, NORMAL): ");
                scanf("%s", priority_group_name);
				root = insert_Customer(root,name,age,priority_group_name);
				print_file(root);
				break;
				
			case 2:
				printf("Please enter the name of the customer to remove: ");
    			scanf("%s", name);
				root = remove_Customer(root, name);
                print_file(root);
				break;
			case 3:
    			display_Customers(root);
    			break;
    			
    		case 4:
    			printf("Please enter the name of the customer to remove: ");
    			scanf("%s", name);
    			search_Customer(root, name);
    			
    			break;
    			
    		case 5:
				printf("Please enter the name of the customer to change priority: ");
    			scanf("%s", name);
    			printf("Please enter the new priority level: ");
    			scanf("%d", &new_plevel);
    			root = changePriority(root, name, new_plevel);
    			print_file(root);
    			break;
			case 6:
				printf("Program Terminated...\n");
				
				break;
			default:
				printf("Invalid choice \n");
		}
		
	}while (choice != 6);
	
	return (0);
}

Customer * insert_Customer(Customer *root,char name[], int age, char priority_group_name[]){
	FILE *fp;
	Customer *n_Customer;
    int priority_level;
    
    if (strcmp(priority_group_name, "VIP") == 0) {
        priority_level = VIP;
    } 
	else if (strcmp(priority_group_name, "OD") == 0) {
        priority_level = OD;
    } 
	else if (strcmp(priority_group_name, "VETERAN") == 0) {
        priority_level = VETERAN;
    } 
	else if (strcmp(priority_group_name, "NORMAL") == 0) {
        priority_level = NORMAL;
    } 
    
    
    n_Customer = create_Customer(name, age, priority_group_name, priority_level);
    
    if (root == NULL){
    	root = n_Customer;
	}
	else {
		Customer * temp = root;
		while (temp->next != NULL && temp->priority_level >= n_Customer->priority_level){
			temp = temp->next;
		}

		if (temp->next == NULL) {
			n_Customer->prev = temp;
			temp->next = n_Customer;
        } 
		else if (temp == root) {
        	root = n_Customer;
            n_Customer->next = temp;
            temp->prev = n_Customer;
		}
		else {
			Customer * prev_temp = temp->prev;
			
			n_Customer->next = temp;
			temp->prev = n_Customer;
			n_Customer->prev = prev_temp;
			prev_temp->next = n_Customer;
		}
	}
	return (root);
}

Customer *create_Customer(char name[], int age, char priority_group_name[], int priority_level){
	Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    strcpy(newCustomer->name, name);
    newCustomer->age = age;
    strcpy(newCustomer->priority_group_name, priority_group_name);
    newCustomer->priority_level = priority_level;
    newCustomer->prev = NULL;
    newCustomer->next = NULL;
    return newCustomer;
}

Customer* remove_Customer(Customer* root, char name[]) {
    if (root == NULL) {
        printf("No customers in the database.\n");
        return root;
    }

    Customer* current = root;
    Customer* prev = NULL;

    // Search for the customer with the given name
    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Customer not found.\n");
        return root;
    }

    // Remove the customer from the linked list
    if (prev == NULL) {
        // Removing the first customer
        root = current->next;
        if (root != NULL) {
            root->prev = NULL;
        }
    } else {
        prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = prev;
        }
    }

    // Free the memory of the removed customer
    free(current);
    printf("Customer '%s' has been removed.\n", name);
    
    return root;
}

void display_Customers(Customer* root) {
    if (root == NULL) {
        printf("No customers in the database.\n");
        return;
    }

    printf("Customers in order:\n");

    Customer* current = root;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Priority Group: %s\n", current->priority_group_name);
        printf("Priority Level: %d\n", current->priority_level);
        printf("--------------------------\n");
        current = current->next;
    }
}

Customer* search_Customer(Customer* root, char name[]) {
    if (root == NULL) {
        printf("There is no customer by that name\n");
        return NULL;
    }

    
    if (strcmp(root->name, name) == 0) {
        printf("Customer found:\n");
        printf("Name: %s\n", root->name);
        printf("Age: %d\n", root->age);
        printf("Priority Group: %s\n", root->priority_group_name);
        printf("Priority Level: %d\n", root->priority_level);
        return root;
    }
    else
    	search_Customer(root->next, name);

}

Customer* changePriority(Customer *root, char name[], int new_plevel){
	Customer * find;
    char n_priority_group_name[20];
	
	find = search_Customer(root, name);
	
	if (find == NULL) {
		return (root);
	}
	else {
		find->prev->next = find->next;
        find->next->prev = find->prev;

        switch (new_plevel){
            case 1 :
                root = insert_Customer(root, find->name, find->age, "NORMAL");

                break;
            case 2 :
                root = insert_Customer(root, find->name, find->age, "VETERAN");

                break;
            case 3 :
                root = insert_Customer(root, find->name, find->age, "OD");

                break;
            case 4 :
                root = insert_Customer(root, find->name, find->age, "VIP");

                break;
            default :
                printf("There is no that level\n");
        }
	}

    return (root);
}

void print_file(Customer * root){
    FILE* fp = fopen(DATABASE, "w");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    Customer* current = root;
    while (current != NULL) {
        fprintf(fp, "Name: %s\n", current->name);
        fprintf(fp, "Age: %d\n", current->age);
        fprintf(fp, "Priority Group: %s\n", current->priority_group_name);
        fprintf(fp, "Priority Level: %d\n", current->priority_level);
        fprintf(fp, "\n");
        current = current->next;
    }

    fclose(fp);
    printf("Customers printed to the file successfully.\n");
}