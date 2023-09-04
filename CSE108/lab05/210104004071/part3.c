#include<stdio.h>

void dectobin(int num);
void dectooct(int num);
void dectohex(int num);


int main(){
	int choice,num;
	
	do {
		printf("Menu:\n");
		printf("1. Convert a number to decimal, binary, octal, and hexadecimal\n");
		printf("2. Quit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);

                printf("Decimal equivalent: %d\n", num);
                dectobin(num);
                dectooct(num);
                dectohex(num);
				break;
            case 2:
                printf("Thanks for using program, Take care\n");
                break;
            default:
                printf("Invalid choice. (1-2)\n");
        }
    } while (choice != 2);

	return (0);
}

void dectobin(int num){
	long int bin,dignum;
	int temp;
	
	bin = 0;
	temp = 0;
	dignum = 1;
	while (num > 0) {
		temp = num % 2;
		num /= 2;
		bin += temp * dignum;
		dignum *= 10;  
    }
	printf("Binary equivalent: %ld\n",bin);
}

void dectooct(int num){
	long int oct,dignum;
	int temp;
	
	oct = 0;
	temp = 0;
	dignum = 1;
	while (num > 0) {
        temp = num % 8;
        num /= 8;
        oct += temp * dignum;
        dignum *= 10;
    }
    printf("Octal equivalent: %ld\n",oct);
}

void dectohex(int num){
	/*
	int temp,hex,dignum;
	
	temp = 0;
	hex = 0;
	dignum = 1;
	while (num > 0){
		temp = num % 16;
		if (temp < 10){
			hex += temp * dignum;
		}
		else {
			hex += ('A' + (temp - 10)) * dignum;
			
		}
		num /= 16;
		dignum *= 10;
	}
	
	printf("%d",hex);
	printf("Hexadecimal equivalent: %x\n",hex);
	*/
	/*
	int i, j, temp;
    char hexa[100];

	i = 0;
    for (num ; num != 0; num /= 16) {
        temp = num % 16;
        
        if (temp < 10)
            temp += 48;
        else
            temp = temp + 55;
        printf("%c",temp + 55);
        hexa[i] = temp;
        i++;
    }
    
    printf("Hexadecimal equivalent: ");
    for (j = i - 1; j >= 0; j--)
        printf("%c", hexa[j]);
  	printf("\n");
    return 0;
    */
    printf("Hexadecimal equivalent: %X\n", num);
}
