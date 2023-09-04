#include <stdio.h>
#include "util.h"


int main() {
    /* A fractional number: 13/7
    int num1 = 13, den1 = 7;
     A second fractional number: 13/11 
    int num2 = 30, den2 = 11;
    An unitilized fractional number */
	int num1, num2, num3;
	int den1, den2, den3;

    //taking 4 variable from the user to process given number
    printf("Please enter the numerator of the first number:");
    scanf("%d", &num1);
	printf("Please enter the denominator of the first number:");
	scanf("%d", &den1);
	printf("Please enter the numerator of the second number:");
	scanf("%d", &num2);
    printf("Please enter the denominator of the second number:");
    scanf("%d", &den2);

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    
    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*
     TODO: Complete this code to read two fractional numbers and print their 
             multiplication and division results...
    */

    return(0);
}
