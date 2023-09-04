#ifndef _UTIL_H_
#define _UTIL_H_

#include<stdio.h>

#define MAX_NAME_LEN 8
#define MAX_BRAND_LEN 6
#define MAX_BRANCH_LEN 15
#define PRODUCT_FILE "products.txt"
#define STOCK_FILE "stocks.txt"
#define REPORT_FILE "report.txt"

//helping function
int find_feature(char *s1, char *s2);

int is_in_it(int ID, char file[]);

int current_status(char file[]);

void insertionSort(int arr[], int n);

void sort_array(double original[], int index[], int size);

void ft_strcpy(char *dest, char *src);

int num_digits(int n);



//main functions for part 2
void add_new_product(int *);

void delete_product(int *);

void update_product(void);

void add_feature_product(void);

void add_new_stock(int *);

void delete_stock(int *);

void update_stock(void);

void part2_file_operations(int *,int *);

//main functions for part 3

void list_all_products(void);

int filter_products(char filtered_products[][100]);

void part3_search_product(void);

//main funtions for part 4

int query_product(void);

int query_all_product(int filtered_stock[][100]);

int query_out_pruduct(int filtered_stock[][100]);

void part4_check_stock_status(void);

//main funtions for part 5

int part5_brand_stock_control(double information[][100]);

//main funtions for part 6

void part6_stock_report(double information[][100], int size);

#endif /* _UTIL_H_ */
