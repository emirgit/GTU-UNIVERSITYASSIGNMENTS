#ifndef _UTIL_H_
#define _UTIL_H_

//libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//constants
#define MAX_BOOK 20
#define SENTIEL '-'
#define S_TEXT_FILE "students.txt"
#define B_TEXT_FILE "books.txt"

//structs
typedef struct book{
	char isbn_number[20];
	char title[80];
	char author[40];
	int pub_year;
	int reserved_status;
	struct book *next;
} Book;

typedef struct student{
	char name[40];
	long long int ID;
	char borrowed_books[10][80];
	struct student *next;
} Student;

//globals
extern Book* root_book;
extern Student* root_student;

//declarations
int split_and_fill(char *dest, char* source, int* str_index);
void read_database(void);
void read_lib_database(void);
void display_borrowed_books(long long int ID);
void addBook(char* isbn, char* title, char* author, int publicationYear, int method);
void deleteBook(char* isbn);
void updateBook(char* isbn, char* feature, char* value);
void filterAndSortBooks(int filterChoice, char* filter, int sortChoice);
void reverseBookList();
void searchBooks(int searchChoice, char* searchValue);
void borrowBook(char* isbn);
void returnBook(char* isbn);
void save_changes_to_database(void);



#endif /* _UTIL_H_ */
