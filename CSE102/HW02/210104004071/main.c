#include<stdio.h>
#include <math.h>

/*
declaration of parts of homework.
they will just print output ,Thus their data type is void.
and their data will be taken in functions ,So they don't take parameter.
*/

void part1(void);
void part2(void);
void part3(void);

int main(){
	//calling part1, part2, and part3 functions in that order.
	part1();
	part2();
	part3();
	
	return (0);
}

void part1(){
	//taken data of year from the user.
	int year;
	
	printf("***************************\n");
	printf("Please enter a year: ");
	scanf("%d", &year);
	
	
	/*These is scientific calculation of leap year
	Because it takes Earth 365.242190 days to orbit the Sun, or 365 days 5 hours 48 minutes and 56 seconds
	So this means we cannot figure out this problem just by checking whether it is divisible by 4 or not
	The rule is that if the year is divisible by 100 and not divisible by 400, leap year is skipped.
	The year 2000 was a leap year, for example, but the years 1700, 1800, and 1900 were not.
	*/
	// it is leap year if it is exactly divisible by 400
	if (year % 400 == 0){
		printf("%d is a leap year\n", year);
	}
	// it isn't a leap year if it is divisible by 100
	// but it isn't divisible by 400 because we check it firstly  
	else if (year % 100 == 0){
		printf("%d is not a leap year\n", year);
	}
	// if it is divisible by 4 and not divisble by 100,it is a Leap year
	else if (year % 4 == 0){
		printf("%d is a leap year\n", year);
	}
	// Other years are not leap years.
	else{
		printf("%d is not a leap year\n", year);
	}
	/*
	if it took exactly Earth 365.25 (or 365 day 6 hour) days to orbit the Sun.)
	we can figure out this problem with basic code as follow.
	if (year % 4 == 0)
		printf("%d is leap year.", year);
	else
		printf("%d is not a leap year.",year);
	But our problem isn't that easy.
	*/
		
}


//I used too many if-else to avoid possible any error.
void part2(){
	//format and operator is used both S and I;
	//So, it is better declarating format and operator at the top of the function.
	char format, oper;
	double result;
	/*
	printf("%0*d",zerocounter,number);
	the "*"  or is used to specify the length of space required to print the integer ..
	and printf now takes two arguments one for space and other for integer..
	simply
	the first argument specifies the length of space(and print 0 for space expect integer),
	 and the second argument specifies the integer to be printed.. 
 	*/
	printf("*************************************\n");
	//taking format of output from user
	printf("Enter the format of output (S or I): ");
	/*The reason I left 1 space in scanf (" %c") is to prevent possible error.
	If we takes character parameter instantly after taking another parameter,
	scanf will try to read the character from the input stream immediately.
	Because Enter means newline (in ASCII it is a character that is 10).
	To avoid this problem, we should always include a space before the format specifier in scanf when we reads characters. 
	This means scanf to skip any whitespace characters (including newlines) before trying to read the input.
	*/
	
	scanf(" %c", &format);
	// if the format is invalid formating type,perform calculation else print error
	if (format == 'S' || format == 'I'){
		//types of operand is double
		double ope1,ope2;
		int m,n;
		
		if (format == 'S'){
			//taking m and n value for S format	
			printf("Enter m and n values: ");
			scanf("%d %d", &m, &n);

			if (n > m){
				//if n is greater than m ,swap them
				int temp;
			
				printf("Number of digits after decimal point(n = %d) cannot be greater than number of total digits of result(m = %d)\n", n, m);
				printf("Values will be replaced \n");
				temp = m;
				m = n;
				n = temp;
			}

			else if (n == m){
				printf("Error : Number of digits after decimal point(n = %d) cannot equal to number of total digits of result(m = %d)\n", n, m);
				return ;
			}
		}

		printf("Enter the operation(+, -, *, /,!,^,%%): ");
		//I explained the reason I left 1 space in scanf format.
		scanf(" %c", &oper);
		
    	switch (oper){

        	case '+':
        		//take 2 double variable for addition,and perform calculation
        		printf("Enter the first operand: ");
        		scanf("%lf", &ope1);
        		printf("Enter the second operand: ");
        		scanf("%lf", &ope2);
            	result = ope1 + ope2;
            	//break is necessary to prevent program entering other cases.
				break;

        	case '-':
        		//take 2 double variable for subtraction,and perform calculation
        		printf("Enter the first operand: ");
        		scanf("%lf", &ope1);
        		printf("Enter the second operand: ");
        		scanf("%lf", &ope2);
            	result = ope1 - ope2;
            	break;

        	case '*':
        		//take 2 double variable for multiplication,and perform calculation
        		printf("Enter the first operand: ");
        		scanf("%lf", &ope1);
        		printf("Enter the second operand: ");
        		scanf("%lf", &ope2);
            	result = ope1 * ope2;
            	break;

        	case '/':
        		//take 2 double variable for divison
				printf("Enter the first operand: ");
        		scanf("%lf", &ope1);
        		printf("Enter the second operand: ");
        		scanf("%lf", &ope2);
				//if operand2 equal 0 this means an error,print error
				//if it is not,continue and perform calculation
 				if (ope2 != 0){
        			result = ope1 / ope2;
        			break;
        		}
            	else{
            		printf("ZeroDivisionError\n");
            		return ;
				}

        	case '!':
				//the reason I put curly braces is being able to declare variable in case
        		{
				int i,fact;
				//taking a variable for factorialization
        		printf("Enter the operand: ");
        		scanf("%lf", &ope1);
        		//if the variable is not an integer,make it integer
        		if (ope1 != (int) ope1){
        			printf("The number entered to get the factorial is floating number.\n");
        			printf("The largest integer smaller than itself will be used for factorialization.\n");
				}
				//if the variable is not invalid variable,print an error
				else if (ope1 < 0){
					printf("Error: Invalid input for factorial\n");
					return ;
				}
				//multiplying all values until program get the operand
				fact = 1;
				for (i = 1;i <= ope1;i++){
					fact *= i;
				}
				//fact is integer,it is bettor convert it double to avoid possible errors
				result = (double) fact;
            	break;
        		}

			case '^':
				//take 2 double variable for power
        		printf("Enter the first operand: ");
        		scanf("%lf", &ope1);
        		printf("Enter the second operand: ");
        		scanf("%lf", &ope2);
        		/*
        		pow is a speacial funtion in math.h 
        		the first parameter a number that will be taken power 
        		the second parameter is power
        		*/
        		result = pow(ope1,ope2);
            	break;

        	case '%':
        		//take 2 double variable for finding remainder from divison
        		printf("Enter the first operand: ");
        		scanf("%lf", &ope1);
        		printf("Enter the second operand: ");
        		scanf("%lf", &ope2);
        		/*
        		Following is the declaration for fmod() function.
        		double fmod(double x, double y)
        		x - This is the floating point value with the division numerator i.e. x.
				y - This is the floating point value with the division denominator i.e. y.
				This function returns the remainder of dividing x/y.
				*/
            	result = fmod(ope1, ope2);
            	break;

        	default:
        		//I print error basically using printf because we didn't learn printing error message by using errno.h
            	printf("Error: Invalid operator\n");
            	return;
    	}

    	if (format == 'S'){

    		if (result != 0){
	    		int exp;
	    		/*m-n means how many digits there are before 0
	    		m-n-floor(log10(result))-1 will say us ,how digits we need to slide number
	    		m = 8 n = 4        result = 1.23
	    		1230.0000e-3 ý need to slide it 3 digit left
	    		I did this like this because if I do this,The digits will be lost less
	    		For exp,
	    		m = 8 n = 4        result = 1.23456789
	    		1234.5678e-3 we lost just 1 digit
	    		If I take the number to 1's digits,4 digits will be lost
	    		0001.2345e0 6789 is lost
	    		e = 8 - 4 - 0 - 1 = 3
	    		10^3 for 1.23 to slide 3 left so the program need to multiply exp by -1.  1.23e0 = 1230e-3	    		
				log10 cannot take a negative parameter
				To avoid this problem, I used fabs (absolute value for double variables).
				*/
				exp = m-n-floor(log10(fabs(result)))-1;
				result *= pow(10,exp);
	    		exp *= -1;

	    		if (oper == '!'){
	    			//if operator equal ! (factorial),there is just 1 opearnd

					if ((int) ope1 >= 17){
						printf("Calculator support number until 17 for factorilization.\n");
						return ;
					}
	    			printf("%d! = %0*.*lfe%d\n",(int) ope1,m+1,n,result,exp);
				}

				else{					

					if ((ope1 == (int) ope1) && (ope2 == (int) ope2)){
						//if the nubers are integer ,don't print 0 after decimal point for operands
						//I expalined * above
						printf("%d %c %d = %0*.*lfe%d\n",(int ) ope1, oper, (int) ope2, m+1, n, result, exp);
					}
					else{
						//else print 2 digits after decimal point for operands
						printf("%.2lf %c %.2lf = %0*.*lfe%d\n",ope1,oper,ope2,m+1,n,result,exp);			
					}
				}
			}

			else{
				/*****************Result equal 0***********************
				'!' cannot be 0 so it will enter first condition
				When the result is 0, there is an error. To fix this error, I have to write a different status for 0.
				*/
				if ((ope1 == (int) ope1) && (ope2 == (int) ope2))
					printf("%d %c %d = %0*.*lfe0\n",(int ) ope1, oper, (int) ope2, m+1, n, result);
				else
					printf("%.2lf %c %.2lf = %0*.*lfe0\n",ope1,oper,ope2,m+1,n,result);
			}
    	}

    	else{
    		//**************** I format **************
	    	if (oper == '!'){
				//to avoid overflow,give a warning to user
				if ((int) ope1 >= 17){
					printf("Calculator support number until 17 for factorilization.\n");
					return ;
				}

	    		printf("%d! = %d\n",(int) ope1,(int) result);
			}
			else{
				/*
				According to given example 5 + 4 = 9
				but for value ope1 = 3.5 ope2 = 7.6  result will be 11.1 
				if we convert integer 11.1
				the output will bi 3 + 7 = 11
				I asked this on Teams but The Assistant didn't reply
				so 
				Result will be every time integer
				but the operands can be double
				if the input is integer, they will be printed like integer
				but it is not ,they will be printed like they entered
				*/
				if ((ope1 == (int) ope1) && (ope2 == (int) ope2))
	    			printf("%d %c %d = %d\n", (int) ope1, oper, (int) ope2, (int) result);
	    		else if ((ope1 == (int) ope1) && (ope2 != (int) ope2))
	    			printf("%d %c %.2lf = %d\n", (int) ope1, oper, ope2, (int) result);
	    		else if ((ope1 != (int) ope1) && (ope2 == (int) ope2))
	    			printf("%.2lf %c %d = %d\n",ope1, oper, (int) ope2, (int) result);
	    		else
	    			printf("%.2lf %c %.2lf = %d\n", ope1, oper, ope2, (int) result);
	    	}
		}
	}

	else{
		//Invalid format 
		printf("Invalid format of output\n");
	}
}

void part3(){
	// I declared all variables in float types to be suitable all possibilities
	float exam1, exam2, exam3, as1, as2, final;
	

	
	//taking datas from user.
	printf("*******************************\n");
	printf("Enter 3 exam grades of student: ");
	scanf("%f %f %f", &exam1, &exam2, &exam3);
	printf("Enter 2 assignment grades of student: ");
	scanf("%f %f", &as1, &as2);
	
	//checking whether the exams and assignments are in interval 0 and 100
	if (exam1 < 0 || exam1 > 100){
		printf("Error : Invalid grade for exam 1\n");
		return ;
	}
	else if (exam2 < 0 || exam2 > 100){
		printf("Error : Invalid grade for exam 2\n");
		return ;
	}
	else if (exam3 < 0 || exam3 > 100){
		printf("Error : Invalid grade for exam 3\n");
		return ;
	}
	else if (as1 < 0 || as1 > 100){
		printf("Error : Invalid grade for assignment 1\n");
		return ;
	}
	else if (as2 < 0 || as2 > 100){
		printf("Error : Invalid grade for assignment 2\n");
		return ;
	}
	/*
	I could check whether the exams and assignments are in interval 0 and 100 by using function
	but I didn't want to break the things said in pdf
	By using function
	
	***************************************
	
	int is_validg(float grade) { (of course above and out of part3 function)
    	return (grade >= 0 && grade <= 100);
	}
	if (!is_validg(exam1) || !is_validg(exam2) || !is_validg(exam3) || !is_validg(as1) || !is_validg(as2)){
		printf("Data entered out of range");	
		return ;
	}
	**************************************
	By using macro
	#define IS_V(grade) ((grade) >= 0 && (grade) <= 100)
	
	if (!IS_V(exam1) || !IS_V(exam2) || !IS_V(exam3) || IS_V(as1) || IS_V(as2)){
		printf("Data entered out of range");
		return ;
	}
	***************************************
	*/
	
	//calculation of final grade
	final = (exam1 + exam2 + exam3) / 3.0 * 0.6 + (as1 + as2) / 2.0 * 0.4;
	//printing final grade
	printf("Final Grade: %.1f ", final);
	//Checking whether the student has passed the lesson or not
	if (final >= 60){
		printf("Passed!\n");
	}
	else{
		printf("Failed!\n");
	}
}
