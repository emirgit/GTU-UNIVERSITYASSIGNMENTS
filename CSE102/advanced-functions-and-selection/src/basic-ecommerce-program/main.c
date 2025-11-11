#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STUDENT_DIS 0.125
#define DISCOUNT 0.1
#define VAT 0.18

/*
I didn't use stftime because it take an array as a first parameter
but using array is forbidden
it is a contradiction
So ý used ctime for printing

The program will be written using functions that perform the above operations(pdf)
declaration
menu functionf for menu
ctdigit function for counting the digit number of integer number
receipt function for printing receipt to txt file
print receipt function for printing receipt to output screen
*/
void menu(void);
int ctdigit(int num);
void receipt(void);
void print_receipt(void);

int main(){
	menu();
	receipt();
	print_receipt();
	
	return (0);
}

//definiton
void menu(void){
	//file pointer for file process and char for reading data from file
	//i is the food number
	FILE *fptr;
	char ch;
	int i;
	/*
	to open file,the function fopen() was used and the reference of the file in a file pointer(fptr)
	just reading will be done so it opened in r mode
	getc(), fgets(), fscanf(), or fread() can be used but 
	it is said us that We must perform this operation without a String.
	So I used getc() function
	*/
	fptr = fopen("menu.txt","r");
	//if fptr == null that's mean the file file not found and Program terminated unsuccessfully
	if (fptr == NULL){
		printf("We don't have menu...(Menu file not found)\n");
		exit(1);
	}

	printf("Yemek Listesi:\n");
	//passing first line of menu (Product		Price (TL))
	while ((ch = fgetc(fptr)) != '\n');
	/*
	ch = fgetc(fptr) taking the character 
	printf("%c",ch) print the character
	printing name of the food and the number of the food
	number of the food will be printed shortly after newline
	after name is printed,pass price of food
	It will print character until see EOF(-1)
	*/
	printf("1. ");
	i = 2;
	while ((ch = fgetc(fptr)) != EOF) {
		printf("%c",ch);
		if (ch == ' '){
		//passing the price of the food
			
			while ((ch = fgetc(fptr)) != '\n' && ch != EOF);
			
			if (i <= 10){
				printf("\n");
            	printf("%d. ",i);
            	i++;
			}
		}
	}
	printf("\n");
	//Closing the file using the function fclose().
	fclose(fptr);
}
/*
it take an integer number
it counts digits of number by dividing number by 10 (that's mean remove 1 digits after dividing by 10)
and return the counter
for example
num = 123
ct = 0
123 / 10 = 12.3 but this is integer 12
ct = 1
12 / 10 = 1.2 ---> 1
ct = 2
1 / 10 = 0.1 ---->0
ct = 3
return 3
*/
int ctdigit(int num){
	int ct;
    for (ct = 0; num != 0; num /= 10) {
        ct++;
    }
    return ct;
}

void receipt(void){
	/*
	fpread will read the menu.txt
	fpwrite will write on receipt.txt
	choice will keep the number of the selected food
	quantity will keep the quantity of the selectetd food
	nlcounter = newline counter
	chcounter = char counter
	price is the price of current food 
	total = the prices of the food that the user selected
	ch = char that will use to read and write to files
	is_student for learning whether the user is student or not
	time_t is a data type that represent the number of second since the Epoch
	*/
	time_t cur_time;
	FILE *fpread, *fpwrite;
	int choice, quantity, nlcounter, chcounter;
	float price, total;
	char ch,is_student;
	/*
	!!
	This is array way to print time
	I didn't this because of it is forbidden
	So ,ý find another way to print time by using ctime() 
	it is similir to example given us in 
	!!
	
	time_t cur_time = time(NULL);
    struct tm *tm = localtime(&cur_time);
    char str_time[25];
    strftime(str_time, sizeof(str_time), "%d.%m.%Y/%H:%M", tm);
	fprintf(fpwrite,"210104004071      %s\n", str_time);
	*/
	cur_time = time(NULL);
	//creating the head of the receipt
	fpwrite = fopen("receipt.txt","w");
	fprintf(fpwrite,"210104004071      %s",ctime(&cur_time));
	fprintf(fpwrite,"------------------------------------------\n");
	fprintf(fpwrite," Product                        Price(TL) \n");
	fprintf(fpwrite,"------------------------------------------\n");
	
	//If user want to quit ,he/she can enter 0 at the "choosing a product" phase or "How many servings do you want" phase
	while (1){
		//making sure the user input right input
		while (1){
			printf("Please choose a product (1-10): ");
			scanf("%d",&choice);
			if (!(choice >= 0 && choice <= 10))
				printf("Invalid product number,Try again!\n");
			else
				break;
		}
		//if choice equal zero,break the loop and ask user whether he/she is student or not
		if (choice == 0)
			break;
		//making sure the user input right input
		while (1){
			printf("How many servings do you want? ");
			scanf("%d",&quantity);
			if (quantity < 0)
				printf("The quantity served cannot be less than 0,Try again!\n");
			else
				break;
		}
		//if quantity equal zero,break the loop and ask user whether he/she is student or not
		if (quantity == 0)
			break;

		fpread = fopen("menu.txt","r");
		/*
		If he/she select 1. kebab he/she need to pass just first line
		ýf he/she select 2. he/she need to pass second line 
		that's mean when nlcounter equal choice number we skipt those
		I can open infinite loop because ý will break it when nlcounter reach the value of choice
		*/
		nlcounter = 0;
		while (1){
			ch = fgetc(fpread);
			if (ch == '\n')
				nlcounter++;
			if (nlcounter == choice)
				break;	
		}
		//there was a space in example in pdf for per food
		fputc(' ', fpwrite);
		/*
		using array is forbidden
		so I have to allignment by using algorithm
		I tried to obey pdf as much as I can
		there was 31 '-' (-------------------------------) in example in pdf for food name space in receipt
		so if quantity is 1 space = 31 - foodnamelength -
		but if quantity is more than 1 space = 31 - foodnamelength - (digitsofquantity + 2)('*' and ' ')
		chcounter = foodnamelength + digitsofquantity + 2
		*/
		if (quantity == 1)
			chcounter = 0;
		else{
			//printing the quantity and the name of the food
			fprintf(fpwrite,"%d* ",quantity);
			chcounter = ctdigit(quantity) + 2;
		}
		while ((ch = fgetc(fpread)) != ' '){
			fputc(ch, fpwrite);
			chcounter++;
		}
		while (chcounter <= 31){
			fputc(' ', fpwrite);
			chcounter++;
		}
		
		//we are now on space,so the next value is our float number
		//taking the value by using fscanf
		fscanf(fpread,"%f",&price);
		//printing the prices of the selected amount of selected foods 
		fprintf(fpwrite, "%.2f\n",quantity * price);
		//adding price to total price
		total += quantity * price;
		//closing the menu.txt
		fclose(fpread);
	}
	//printing the total price 
	fprintf(fpwrite," Total:                          %.2f\n",total);
	
	/*
	I used do while 
	because is_student wasn't initialized
	So I wanted program to check whether the user student or not after is_student declared
	do while check the condition after
	but while check it firstly
	so it is better using do-while for our case
	and make the program diverse
	*/
	
	do {
		printf(" Are you student? (Y/N): ");
	/*
	The reason I left 1 space in scanf (" %c") is to prevent possible error.
	If we takes character parameter instantly after taking another parameter,
	scanf will try to read the character from the input stream immediately.
	Because Enter means newline (in ASCII it is a character that is 10).
	To avoid this problem, we should always include a space before the format specifier in scanf when we reads characters. 
	This means scanf to skip any whitespace characters (including newlines) before trying to read the input.
	*/
		scanf(" %c",&is_student);
		switch (is_student){
			
			/*
			if she/he is student appy student discound but don't break it 
			Because total can be greater than 150 so 'Y' option include 'N' option
			if it is appy discount
			else continue
			*/
			case 'Y':
				fprintf(fpwrite," Student discount:               -%.2f\n",total * STUDENT_DIS);
				total -= total  * STUDENT_DIS;
			case 'N':
				if (total >= 150){
					fprintf(fpwrite," Additional Discount:            -%.2f\n",total * DISCOUNT);
					total -= total * DISCOUNT;
				}
				fprintf(fpwrite,"------------------------------------------\n");
				break;
			default:
				printf("Please enter a valid answer!\n");
		}
	} while (is_student != 'N' && is_student != 'Y');
	//printing total price and total price with tax
	fprintf(fpwrite," Price:                          %.2f\n",total);
	total *= 1 + VAT;
	fprintf(fpwrite," Price + VAT:                    %.2f\n",total);
	//close receipt.txt
	fclose(fpwrite);
}

void print_receipt(void){
	FILE *fptr;
	char ch;
	
	fptr = fopen("receipt.txt","r");
	
	while ((ch = fgetc(fptr)) != EOF) {
		printf("%c",ch);
	}
	
	fclose(fptr);
}
