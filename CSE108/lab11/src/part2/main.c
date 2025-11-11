#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ExamPaper {
    char* studentName;
    long long int studentNumber;
    int score;
    struct ExamPaper* next;
} ExamPaper;

ExamPaper* push(ExamPaper* stack, char* studentName, long long int studentNumber, int score);

ExamPaper* pop(ExamPaper* stack);

bool isEmpty(ExamPaper* stack);

void display(struct ExamPaper* stack);

int main() {
    struct ExamPaper* stack = NULL;

    stack = push(stack, "Zehra Bilici", 20220000001, 90);
    printf("Exam Paper Added: Student Name: %s, Student Number: %lld, Score: %d\n", stack->studentName, stack->studentNumber, stack->score);

    stack = push(stack, "Baris Ozcan", 20190000002, 85);
    printf("Exam Paper Added: Student Name: %s, Student Number: %lld, Score: %d\n", stack->studentName, stack->studentNumber, stack->score);

    stack = push(stack, "Mehmet Burak Koca", 20180000010, 95);
    printf("Exam Paper Added: Student Name: %s, Student Number: %lld, Score: %d\n", stack->studentName, stack->studentNumber, stack->score);

	stack = pop(stack);
    
    if(isEmpty(stack)){
    	printf("Stack is empty\n");
	}
	else {
		printf("Stack is not empty\n");
	}

    return 0;
}

// it push entry of number as first elements
ExamPaper* push(ExamPaper* stack, char* studentName, long long int studentNumber, int score) {
    ExamPaper* newPaper;
	newPaper = (ExamPaper*)malloc(sizeof(ExamPaper));
	
	//printf("Exam Paper Added: Student Name: %s, Student Number: %d, Score: %d\n\n",studentName,studentNumber,score);
    newPaper->studentName = studentName;
    newPaper->studentNumber = studentNumber;
    newPaper->score = score;
    newPaper->next = stack;
    display(newPaper);
    return newPaper;
    
    /*
    it push the element to last entry
    if (stack == MULL)[
    	stack = (ExamPaper*)malloc(sizeof(ExamPaper));
    	    stack->studentName = studentName;
    		stack->studentNumber = studentNumber;
    		stack->score = score;
    		stack ->next = NULL;
    }
    ExamPaper *temp;
    while (temp ->next != NULL)
    	temp = temp ->netxt;
    
    ExamPaper* newPaper;
	newPaper = (ExamPaper*)malloc(sizeof(ExamPaper));
	newPaper->studentName = studentName;
    newPaper->studentNumber = studentNumber;
    newPaper->score = score;
    newPaper->next = NULL;
    temp->next = newPaper;
    
    return (stack);
	*/
}


//this function remove the first entry of stack
ExamPaper* pop(ExamPaper* stack) {

    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return NULL;
    }
    printf("Last Added Exam Paper\n");
    printf("Student Name: %s, Student Number: %lld, Score: %d\n\n",stack->studentName, stack->studentNumber, stack->score);
    ExamPaper* top;
	top = stack;
    stack = stack->next;
    free(top);
    
    display(stack);
    return stack;
    
    /*
    it removes the last entry of the list
    if (stack == NULL)
    	printf("stack is empty);
    
    ExamPaper *temo = stack;
    while (temp->next->next != NULL)
    	temp = temp->next
    free(temp->next);
    temp->next = NULL;
    
    return (stack);
    
    */
}

bool isEmpty(ExamPaper* stack) {
    return stack == NULL;
}

void display(struct ExamPaper* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Exam Papers in the Stack:\n");
    while (!isEmpty(stack)) {
        printf("- %s, Student Number: %lld, Score: %d\n", stack->studentName, stack->studentNumber, stack->score);
        stack = stack->next;
    }
}
