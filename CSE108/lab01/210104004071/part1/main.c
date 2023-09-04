#include<stdio.h>

int main(){

	int i;
// taking an integer value from user
	printf("Please enter an integer number:");
	scanf("%d",&i);
//checking number is in determined interval
	if (i >= 1 && i <= 100){
// if number can be divided 3 and is in determined interval,print fizzbuz
		if (i % 3 == 0 && (i <= 50 && i >= 5))
			printf ("FizzBuzz ");
// if number can be divided 3 print fizz
		else if (i % 3 == 0)
			printf("Fizz ");
// if numbar is in determinedi nterval print buzz
		else if (i <= 50 && i >= 5)
			printf("Buzz");
	}

	printf("\n");
	return (0);
}
