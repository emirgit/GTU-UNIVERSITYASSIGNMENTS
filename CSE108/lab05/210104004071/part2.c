#include<stdio.h>

int main(){
	int num,temp,digits,curdig;
	
	printf("Enter a number (3-5 digits): ");
    scanf("%d", &num);
    
    temp = num;
    digits = 0;
    
    for (temp = num; temp > 0; temp /= 10){
    	digits++;
	}
    
    if (digits >= 3 && digits <= 5){
    	temp = 0;
    	for (num; num > 0; num /= 10){
    		temp = temp * 10 + (num % 10);
		}	
		printf("Reversed number: %d\n", temp);
	}
	else
		printf("Invalid number for converting\n");
		
	return (0);
    
}
