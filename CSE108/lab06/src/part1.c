#include<stdio.h>
//#include<stdlib.h>
#define SENTIEL -100
#define MAX_ARRSIZE 100


/*declarations
enter_input function to read the inputs and return the results in an array
dec_label function to label these numbers in another function returning the results in a second array.
print_arrs function to print calculated labels and entered inoputs
*/
void enter_input(int arr[], int *counter);
void dec_label(int arr[], char charr[], int *counter);
void print_arrs(int arr[], char charr[], int *counter);

int main() {
	//array pointer because it is sait return array
	//there is max size but size variable will count until see -100 value in enter_input function
	int size;
	//declaring maxsize array
	int arr[MAX_ARRSIZE];
	
	//initialization
	size = 0;
	
	enter_input(arr, &size);
	//after it determined,new function is enough size 
	char label_array[size];
	dec_label(arr, label_array, &size);
	print_arrs(arr, label_array, &size);
	
	return (0);
}

//definitons

void enter_input(int arr[], int *counter){
	
	int num;
	
	scanf("%d", &num);
	//will continue until the number does not equal SENTILE
	while (num != SENTIEL && *counter < MAX_ARRSIZE) {
		//append the number current index
        arr[*counter] = num;
        // or (*counter)++
        *counter += 1;
        scanf("%d", &num);
    }

}

void dec_label(int arr[], char label[], int *counter){
	int i;
	
	//go over all numbers one by one and calculate labels and append this label to labelarray
	for (i = 0; i < *counter ; i++){
		if (arr[i] % 2 == 0)
			label[i] = 'e';
		else
			label[i] = 'o';
	}
}

void print_arrs(int arr[], char label_array[], int *counter){
	int i;
	
	//print reuslts
	for (i = 0; i < *counter; i++)
		printf("%d %c\n", arr[i], label_array[i]);
}

/*
declarations
enter_input function to read the inputs and return the results in an array
dec_label function to label these numbers in another function returning the results in a second array.
print_arrs function to print calculated labels and entered inoputs

void enter_input(int arr[]);
void dec_label(int arr[], char charr[]);
void print_arrs(int arr[], char charr[]);

int main() {
	//array pointer because it is sait return array
	//there is max size but size variable will count until see -100 value in enter_input function
	//declaring maxsize array
	int arr[MAX_ARRSIZE];
	char labe_array[MAX_ARRSIZE];
	//initialization
	
	enter_input(arr);
	dec_label(arr, label_array);
	print_arrs(arr, label_array);
	
	return (0);
}

//definitons

void enter_input(int arr[]){
	
	int num,i;
	
	i = 0;
	scanf("%d", &num);
	//will continue until the number does not equal SENTILE
	while (num != SENTIEL && i < MAX_ARRSIZE) {
		//append the number current index
        arr[i] = num;
        i++;
        scanf("%d", &num);
    }

}

void dec_label(int arr[], char label[]){
	int i;
	
	//go over all numbers one by one and calculate labels and append this label to labelarray
	for (i = 0; i < MAX_ARRSIZE ; i++){
		if (arr[i] % 2 == 0)
			label[i] = 'e';
		else
			label[i] = 'o';
	}
}

void print_arrs(int arr[], char label_array[]){
	int i;
	
	//print reuslts
	for (i = 0; i < MAX_ARRSIZE; i++)
		printf("%d %c\n", arr[i], label_array[i]);
}






//      MALLOC SOLUTION 
declarations
int* enter_input(void);
char* dec_label(int arr[]);
void print_arrs(int arr[], char charr[]);

int main() {
	//array pointer because it is sait return array 
	int *arr;
	char *charr;
	
	
	arr = enter_input();
	charr = dec_label(arr);
	print_arrs(arr, charr);
	
	free(arr);
	free(charr);
	
	return (0);
}

//definitons

int* enter_input(void){
	
	int* arr = (int*) malloc(ARRSIZE * sizeof(int));
	int num,i;
	
	i = 0;
	scanf("%d", &num);
	while (num != SENTIEL && i < ARRSIZE) {
        arr[i] = num;
        i++;
        scanf("%d", &num);
    }
	
	return (arr);
}

char* dec_label(int arr[]){
	char* label = (char*) malloc(ARRSIZE * sizeof(char));
	int i;
	
	for (i = 0; i < ARRSIZE ; i++){
		if (arr[i] % 2 == 0)
			label[i] = 'e';
		else
			label[i] = 'o';
	}
	
	return (label);	
}

void print_arrs(int arr[], char charr[]){
	int i;
	
	for (i = 0; i < ARRSIZE; i++){
		printf("%d %c\n", arr[i], charr[i]);
	}
}
*/
