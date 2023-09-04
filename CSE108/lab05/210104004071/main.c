#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
the struct that has 3 variable int,int,float respectively.
ID,age, gpa
it is said to name it as Student
*/
typedef struct {
    int ID;
    int age;
    float gpa;
} Student;


//declarations
int* cre_dyn_arr(int size);
int find_min(int *array,int size);
int* cumulative_sum_calculator(int* array, int size);
float cre_Student_array(int size);
//float cre_Student_array(int size);

int main(){
	//part 1 ************************************
	int size, min, i;
	int *array;
	
	//taking size from user
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    //calling cre_dyn_arr function to create array
    array = cre_dyn_arr(size);
    
    if (array == NULL) {
		return (EXIT_FAILURE);
	}
	
	// finding minimum value algorihtm
	min = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    // printing value
    printf("Min of the array elements: %d",min);
    
    //freeing dynamic array from heap
    free(array);
    
    /*
	part 2*****************************
    I used size,i and array again in function
    */
    
    int * sum_arr;

	printf("\n\n******* part2 ****** \n\n");
	
	//taking size from user
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
	//calling cre_dyn_arr function to create array
    array = cre_dyn_arr(size);
    
    if (array == NULL) {
		return (EXIT_FAILURE);
    }
    
    //finding cumulative sum by calling cumulative_sum_calculator
    sum_arr = cumulative_sum_calculator(array, size);
    
    //if dynamic allocation is failed, free previous array
    if (sum_arr == NULL){
    	free(array);
    	return (EXIT_FAILURE);
	}
	
	//printing array respectively
	printf("First array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
        //printf("%d ", *(p + i));
    }
    printf("\nSecond array (cumulative sum): ");
    for (i = 0; i < size; i++) {
        printf("%d ", sum_arr[i]);
    }
    
    //deallocations
    free(array);
    free(sum_arr);
    
    /*
    part3
	I used size and i  variable before  
    */
    printf("\n\n******* part3 ****** \n\n");
    size = 10000;
    float Average = 0.0;
    /*
	printf("Enter the size of the array: ");
    scanf("%d", &size);
	*/
	for (i = 0 ; i < size ; i++){
		Average += cre_Student_array(size);
	}
	
	printf("Average GPA of 10.000 x 10.000 students: %f\n",Average / size);
	
	
	/*
	Student* Student_array;
	
	// creating same array 10.000 tines
	Student_array = cre_Student_array(size);
	for (i = 0; i < size ; i++){
		if (Student_array != NULL)
			free(Student_array);
		Student_array = cre_Student_array(size);
	}
	
    if (Student_array == NULL) {
        return (EXIT_FAILURE);
    }
    
    float sum = 0.0;
    
    // finding sum and divide it into size (finding average)
    for (i = 0; i < size; i++) {
        sum += Student_array[i].gpa;
    }
    printf("Average GPA: %.1f\n", sum / size);
    free(Student_array);
    
    */
    /*
    2. 
    
    
    float = sum;
    
	Student_array = cre_Student_array(size);
	for (i = 0; i < size ; i++){
		if (Student_array != NULL){
			sum = 0.0;
    
			for (i = 0; i < size; i++) {
        		sum += Student_array[i].gpa;
    		}
    		printf("Average GPA: %.1f\n", sum / size);
			free(Student_array);
		}
		Student_array = cre_Student_array(size);
	}
	
    if (Student_array == NULL) {
        return (EXIT_FAILURE);
    }
    
    free(Student_array);
    
    */
    
    /*
    3.
    Student* Student_array;
	
	// creating same array 10.000 tines
	Student_array = cre_Student_array(size);
	float sum = 0.0;
	for (i = 0; i < size ; i++){
		if (Student_array != NULL){
			for (i = 0; i < size; i++) {
        		sum += Student_array[i].gpa;
    		}	
			free(Student_array);
		}
		Student_array = cre_Student_array(size);
	}
	
    if (Student_array == NULL) {
        return (EXIT_FAILURE);
    }
    
    printf("Average GPA: %.1f\n", sum / size * size);
    free(Student_array);
    
    */
    
    return (0);
}


// definitions
int* cre_dyn_arr(int size) {
	int i;
    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    
	printf("Please enter the elements of the array : ");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    

    return array;
}

/*int find_min(int *array, int size){
	int i, min;
	
	min = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}*/

int* cumulative_sum_calculator(int* array, int size){
	int * sum_arr, sum, i; 
	
	sum_arr = (int*)calloc(size, sizeof(int));
	if (sum_arr== NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    
    sum = 0;
    for (i = 0; i < size; i++) {
        sum += array[i];
        sum_arr[i] = sum;
    }
    
    return sum_arr;
}

/*
Student* cre_Student_array(int size) {
    Student* array = (Student*)malloc(size * sizeof(Student));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Seed random every time by time
    srand(time(NULL));

	int i;
    for (i = 0; i < size; i++) {
    	//min age 18 max age 29 
    	array[i].age = rand() % 13 + 17;
    	// ID = 10000000
        array[i].ID = i + (10000000) * array[i].age;  

        array[i].gpa = ((float)rand() / RAND_MAX) * 4.0;  
    }

    return array;
}
*/

float cre_Student_array(int size) {
    Student* array = (Student*)malloc(size * sizeof(Student));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    // Seed random every time by time
    srand(time(NULL));

	int i;
    for (i = 0; i < size; i++) {
    	//min age 18 max age 29 
    	array[i].age = rand() % 13 + 17;
    	// ID = 10000000
        array[i].ID = i + (10000000) * array[i].age; 
		/*
		rand() function create a random integer value from 0 to RAND_MAX
		if I dividet it by  RAND_MAX it create a value [0,1]
		so if I multiple by 4 the result will be in interval [0,4]  
		*/  
        array[i].gpa = ((float)rand() / RAND_MAX) * 4.0;  
    }

    float sum = 0.0;
    
    // finding sum and divide it into size (finding average)
    for (i = 0; i < size; i++) {
        sum += array[i].gpa;
    }
    
    free(array);
    return (sum / size);
}

