#include<stdio.h>

int main(){

	int age, exp;
// taking values of age and experience from users
	printf("How old are you :");
	scanf("%d", &age);
	printf("How many years have you worked in this job? :");
	scanf("%d", &exp);
// checking the determined intervals and conditions
	if (age < 20)
	{
		if (exp <= 10 && exp >= 0)
			printf("Your salary is 10.000");
		else
			printf("Error");
	}
	
	else if (age <= 50)
	{
		if (exp <= 10 && exp >= 0)
			printf("Your salary is 15.000");
		else if (exp > 10) 
			printf("Your salary is 20.000");
	}

	else if (age > 50)
	{
		if (exp <= 10 && exp >= 0)
			printf("Your salary is 20.000");
		else if (exp > 10)
			printf("Your salary is 25.000");
	}
	printf("\n");

	return (0);
}
