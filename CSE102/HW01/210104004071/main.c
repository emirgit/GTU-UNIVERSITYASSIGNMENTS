#include<stdio.h>

//declaration
int fgcd(int num1, int num2);
//types of functions is void because they will just print.
//they won't take any parameter because the numbers will be taken in function.
void part1(void);
void part2(void);
void part3(void);
void part4(void);

int main(){
	//calling all functions respectively.
	part1();
	part2();
	part3();
	part4();
	return (0);
}	

//I asked if I could use additionals function for gcd.Hoca said I can use.So, I decided to find gcd by using recursive funtion.
int fgcd(int num1, int num2)
{
	/*
	(place not important Because the function will change them at next recursion)
	For example;
	if a = 5 b = 10	fgcd(5,10), the next calling is fgcd(10,5) 
	It will divide big number as Big = Small*Q + R
	It will send small and remainder for next recursion
	Remainder = num1 % num2 Small = num2 
	It will continue till small number equals 0
	If small number equal 0,it will return the last dividend
	*/
	if (num2 == 0)
		return num1;
	return fgcd(num2, num1 % num2);
}

void part1(void){
	/*
	The Euclidean algorithm
	it takes two number
	1- it divides the larger number by the smaller number (A = B*Q + R)
	2- The Euclidean algorithm say that GCD(A,B) = GCD(B,R)
	3- Thus,it continues to divide numbers by remainder from previous process
	4- It will continue till it finds 0 as a remainder.
	5- When the remainder 0 ,The last dividend is the gcd.
	*/
	int num1, num2, gcd;
	
	printf("Please enter the first integer: ");
	scanf("%d", &num1);
	printf("Please enter the second integer: ");
	scanf("%d", &num2);
	gcd = fgcd(num1, num2);
	printf("The gcd of the numbers is %d\n",gcd);
}

void part2(void){
	int num1, num2;

	printf("First number : ");
	scanf("%d", &num1);
	printf("Second number: ");
	scanf("%d", &num2);
	printf("Result:\n     %7d\n     %7d\n     +\n     -------\n     %7d\n", num1, num2, num1 + num2);
}

void part3(void){
	int num1, num2, temp;

	printf("First number : ");
	scanf("%d", &num1);
	printf("Second number: ");
	scanf("%d", &num2);
	
	//I could this dinamic but it is said that The numbers could have most 3 digits,so ı decide to solve by using if-else statement.
	//If there is a number with only ones digit,I don't need to sum.
	//It is said that negative numbers will not input.
	if (num2 < 10)
		printf("Result:\n   %10d\n   %10d\n   *\n   ----------\n   %10d", num1, num2, num1 * num2);
	//If there is a number with two digit,number % 10 give  ones digit and number / 10 give tens digit
	else if (num2 < 100)
		printf("Result:\n   %10d\n   %10d\n   *\n   ----------\n   %10d\n   %9d\n   +\n   ----------\n   %10d", num1, num2, num1 * (num2 % 10), num1 * (num2 / 10), num1 * num2);
	//temp will keep the ones and tens digit
	else{
		temp = num2 % 100;
		printf("Result:\n   %10d\n   %10d\n   *\n   ----------\n   ", num1, num2);
		printf("%10d\n   %9d\n   %8d\n   +\n   ----------\n   %10d", num1 * (temp % 10), num1 * (temp / 10), num1 * (num2 / 100), num1 * num2);
	}
	printf("\n");
}

void part4(void){
	int num;

	printf("Please enter an integer between 1 and 10(inclusive) : ");
	scanf("%d", &num);
	if (num >= 1 && num <= 5)
		printf("The integer you entered is less than or equal to 5");
	else if (num <= 10 && num > 5)
		printf("The integer you entered is greater than 5");
	else
		printf("Invalid input");
	printf("\n");
}
