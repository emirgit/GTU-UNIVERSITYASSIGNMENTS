#ifndef _UTIL_H_
#define _UTIL_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct {
    char type[20];
    int ivals[1];
    double svals[1];
} Asset1;

typedef struct {
    char type[20];
    double svals[2];
    int ivals[2];
} Asset2;

typedef struct {
    char type[20];
    char string1[50];
    char string2[50];
} Asset3;

typedef struct {
    char type[20];
    double value1;
    float value2;
    double value3;
} Asset4;

void fillLinkedList(struct Node** head);
void random_word(char *string, char sentece[25][50]);
void print_linked_list(Node* head);
void serializeLinkedList(struct Node* head);
void deserializeLinkedList(struct Node** head);
void free_linked_list(struct Node* head);


#endif /* _UTIL_H_ */
