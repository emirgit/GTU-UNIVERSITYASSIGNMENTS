#ifndef _UTIL_H_
#define _UTIL_H_

#include<stdio.h>
#include<string.h>

//macros that it is said in pdf
#define MAX_WORD_SIZE 13
#define MAX_WORD_COUNT 101
#define MAX_WORD_LIMIT 300000
#define MAX_VECTOR_DIGIT 12

//passing first word of a string to access directly vectors
int pass_word(char *);

//if closest vector is found ,the word include - .so print it it is said.
int found_closest(const char *);

//filling string by given word and return index of it
int fill_arr(const char *word, char * str, int index);

//word counter of specific string
int stringwordcount(char *s);

//finding frequench of a word in txt
int find_frequency(const char words[][MAX_WORD_SIZE],char *str);

//don't take ignored word
int is_an_ignored(char const * ignore_file,char const * str);

//copying a string to destination
void f_strcp(char *dest, const char *source);

//appending a string to destination
void f_strcat(char *dest, const char *source);

//finding the length of a string
int f_strlen(char *str);

//reading vector size of file that includes vectors
int read_vector_size(const char *file_name);

//reading first line and taking the number of word to use
int read_first_line(const char * file_name);

//if it is similar to is_space in string.h
int isnot_spacechar(int ch);

//finding whether words is alphabetically or not
int is_alphabetic(int ch);

//main functions
int read_dict(const char * file_name, char dict[][MAX_WORD_SIZE]);
int  read_text(const char  * text_file, const char  * ignore_file, char words[][MAX_WORD_SIZE]);
double dissimilarity(char * w1, char * w2, char dict[][MAX_WORD_SIZE], float threshold, const char * file_name);
int histogram(const char words[][2 * MAX_WORD_SIZE],const int occurrences[], char hist[][2 * MAX_WORD_SIZE+5+20]);

#endif /* _UTIL_H_ */
