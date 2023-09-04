#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
f_strcpy(char * dest, char* source){
	int i;
	
	i = 0;
	while (source[i] != '\0')
		dest[i] =source[i];
	dest[i] = '\0';
}
*/

// Structure to hold order details
typedef struct Order {
    char customer_name[100];
    int orderID;
    char items[100];
    char order_time[100];
    struct Order* next;
} Order;


//declarations

// Function to enqueue a new order
Order* enqueue(Order* queue, char* costumer_name, int orderID, char* items, char* order_time);

// Function to dequeue the oldest order
Order* dequeue(Order* queue);

// Function to display the linked list
void display(Order* queue);

// Function to update the items in an existing order
void updateOrder(Order* queue, int orderID, char* newItems);

int main() {
    Order* queue = NULL;

    //Enqueue some orders
    queue = enqueue(queue, "Barýs Ozcan", 101, "Burger, Fries, Coke", "10:30 AM");
    display(queue);
    queue = enqueue(queue, "Zehra Bilici", 102, "Pizza, Salad, Ice Cream", "13:35");
    display(queue);
    queue = enqueue(queue, "Mehmet Burak Koca", 103, "Steak, Mashed Potatoes, Salad", "14:53");
    display(queue);

    //Update an order
    updateOrder(queue, 102, "Pizza, Salad, Ice Cream, Iskender");
    display(queue);

    // Dequeue an order
    queue = dequeue(queue);
    printf("Barýs Ozcan Removed\n");
    display(queue);






    // Free all element by order time after program is down
    while (queue != NULL) {
        Order* temp = queue;
        queue = queue->next;
        free(temp);
    }

    return (0);
}

Order* enqueue(Order* queue, char* customer_name, int orderID, char* items, char* order_time) {
	//new order 
    Order* new_order, *temp;
	
	//creating an Order type by using malloc
	new_order = (Order*)malloc(sizeof(Order));
	//copying data to new_order
    strcpy(new_order->customer_name, customer_name);
    new_order->orderID = orderID;
    strcpy(new_order->items, items);
    strcpy(new_order->order_time, order_time);
    
    //putting NULL to next pointer of new_order that is created
    new_order->next = NULL;
    
	printf("Enqueue Operation:\n");
	printf("Enqued: Order ID: %d, Customer Name: %s, Items: %s\n\n\n",orderID,customer_name,items);
	
	//if root is null (that mean's returning new_order because there is just 1 element don't need to return queue)
    if (queue == NULL) {
        return new_order;
    }

	//creating new copy of root to append new_order end of the linked list
    temp = queue;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    //append it
    temp->next = new_order;
    //return root
    return (queue);
}

// Function to dequeue the oldest order
Order* dequeue(Order* queue) {
    if (queue == NULL) {
        printf("Queue is empty.\n");
        return NULL;
    }

	//creating tem order and freeing next 
    Order* temp;
	temp = queue;
    queue = queue->next;
    free(temp);
    return (queue);
}

// Function to display the linked list
void display(Order* queue) {
    if (queue == NULL) {
        printf("Queue is empty.\n");
        return;
    }
	
    Order* temp = queue;
	printf("Display Orders by Order Time\n");
    while (temp != NULL) {
    	printf("Order ID: %d, ", temp->orderID);
        printf("Customer Name: %s, ", temp->customer_name);
        printf("Items: %s\n", temp->items);
        temp = temp->next;
    }
    printf("\n\n");
}

// Function to update the items in an existing order
void updateOrder(Order* queue, int orderID, char* newItems) {
    if (queue == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Order* temp;
	temp = queue;
	
	//it finding order that is wanted and change the data in it
    while (temp != NULL) {
        if (temp->orderID == orderID) {
            strcpy(temp->items, newItems);
            return;
        }
        temp = temp->next;
    }

    printf("Order ID %d not found.\n", orderID);
}
