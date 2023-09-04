#ifndef _UTIL_H_
#define _UTIL_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CHILD 6
#define FAMILYS "Familys.txt"

/*
Person can have more children
So the child pointer is pointer array
it will include sentiel value
max 5 children
if it is less than 5
the last index will be NULL
*/
typedef struct node{
    char Name[40];
    int Age;
    struct node *Mother;
    struct node *Father;
    struct node *child[MAX_CHILD];
} node;

//declarations 
/*
fill_roots function for filling roots respect to 2-3 line of the txts
*/
node *fill_roots(char buffer[256], int gender);
/*
split functions split source respect to '|'
it will detect the stepchild
*/
int split(char *source, char *dest, int *i);
/*
is_strandind check the filenames is this format "familyX.txt" , X is unique number

*/
int is_strandint(const char *filename);
/*
ge
*/
/*
find_name_file find the name of the file for load 3
*/

int find_name_file(char file_name[40]);
/*
print_familys print the files for 3-load
*/
void print_familys(void);
/*
strcpy_tilln is like strcpy but it copy source until new line character
*/
void strcpy_tilln(char *dest, char *source);
/*
load famiy root for loading from file it return file pointer 
because it fill roots after the cursor that is processed and there are lines that aren't used
*/
FILE *load_family_root(node **mother, node **gfather, const char file_name[40]);
/*
load_menu is sub menu for loading
it makes the load menu works
*/
void load_menu(void);
/*
remove_tree is for removing family tree by enterin file
*/
int remove_tree(const char *file_name);

void sub_menu_add(void);
//it sets roots
node *set_roots(void);

/*
add_node1 add nodes to family tree
*/
void add_node1(node *father, node *mother, node* new_node, char mother_name[40], char father_name[40]);
/*
the find_name also important function to search the entered node by checking name
*/
node *find_name(node *root, char name[40]);
//printTree print the tree recursively
void printTree(node *root, int depth);
//save functions and txt_update to save the family tree to file
int save_family(node *father, node *mother);
void save_roots(FILE *fp, node *father, node *mother);
void save_father_root(FILE *fp, node *father);
void txt_update(const char *filename, int method);
// atoi is convert string to integer
int	f_atoi(const char *str);
//ft_strcmp check string is equal or not
//str1 goes until see new line
//str2 goes until see '\0'
int ft_strcmp(const char *str1, const char *str2);
//integer to string
void f_itoa(int num, char str[40]);
//it fills root for load
node *fill_roots(char buffer[256], int gender);
//it frees family tree to prevent memory leak
void free_tree(node *root);
//sub menu to search relatives
void sub_sub_menu(node *gfather, node *gmother, node *new_node, int method);



#endif /* _UTIL_H_ */
