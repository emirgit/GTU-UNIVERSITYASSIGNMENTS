#include <stdio.h>

int main(){
	//------------part1-------------------------------------
    int num1, num2, num3;

    printf("Enter 3 integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

	if (num1 >= num2){
    	if (num2 >= num3)
    		printf("Median number is %d",num2);
		else if (num1 <= num3)
            printf("Median number is %d",num1);
		else
            printf("Median number is %d",num3);
    } 
	else{
        if(num1 >= num3)
            printf("Median number is %d",num1);
		else if (num2 <= num3)
        	printf("Median number is %d",num2);
		else
            printf("Median number is %d",num3);
    }
    printf("\n");
    //------------part1end-------------------------------------
    //------------part2----------------------------------------
    printf("Enter your scores: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    if (num1 > 100 || num1 < 0){
    	printf("Invalid number.");
	}
	else if (num2 > 100 || num2 < 0){
    	printf("Invalid number.");
	}
	else if (num3 > 100 || num3 < 0){
    	printf("Invalid number.");
	}
	else{
		printf("Your letter grades are ");
		switch(num1 / 10)
		{
			case 10:
			case 9:
				printf("A+");
	     		break;
			case 8:
				printf("A");
				break;
			case 7:
				printf("B+");
				break;
			case 6:
				printf("B");
				break;
			case 5:
				printf("C");
				break;
			case 4:
				printf("D");
				break;
			default:
				printf("F");
				break;
		}
		printf(", ");
		switch(num2 / 10)
		{
			case 10:
			case 9:
				printf("A+");
	     		break;
			case 8:
				printf("A");
				break;
			case 7:
				printf("B+");
				break;
			case 6:
				printf("B");
				break;
			case 5:
				printf("C");
				break;
			case 4:
				printf("D");
				break;
			default:
				printf("F");
				break;
		}
		printf(" and ");
	   	switch(num3 / 10)
		{
			case 10:
			case 9:
				printf("A+");
	     		break;
			case 8:
				printf("A");
				break;
			case 7:
				printf("B+");
				break;
			case 6:
				printf("B");
				break;
			case 5:
				printf("C");
				break;
			case 4:
				printf("D");
				break;
			default:
				printf("F");
				break;
		}
		printf(" with an %.1f average.",(num1 + num2 + num3) / 3.0);
	}
	printf("\n");
	//------------part2end-------------------------------------
	//------------part3----------------------------------------
	char ope;
	int res;
	
	printf("Enter an arithmetic operation (+, -, *, /): ");
	scanf(" %c",&ope);
	printf("Enter two numbers: ");
	scanf("%d %d", &num1, &num2);
	printf("Result: ");
	scanf("%d", &res);
	
	switch (ope){
	case '+':
    	num3 = num1 + num2;  
		break;
    case '-':
		num3 = num1 - num2;
		break;
    case '*':
		num3 = num1 * num2;
		break;
    case '/':
		num3 = num1 / num2;
		break;
    default:
		printf("Error! Invalid operator.");	
	}
	if (res != num3)
		printf("Wrong answer, try again.");
	else
		printf("Bravo, correct answer!");
	//------------part3end-------------------------------------
	printf("\n");
	return (0);
}
