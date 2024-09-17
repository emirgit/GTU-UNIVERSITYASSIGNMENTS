#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
	printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1 * d2 + n2 * d1;
    *d3 = d1 * d2;
	fraction_simplify(n3, d3);
} /* end fraction_add */

/*this function takes 6 parameter ,and it implements fraction subtraction.
After that, it change the value of cells pointed by d3 and n3.*/
void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1 * d2 - n2 * d1;
    *d3 = d1 * d2;
	fraction_simplify(n3, d3);
} /* end fraction_sub */

/*this function takes 6 parameter ,and it implements fraction multiplication.
After that, it change the value of cells pointed by d3 and n3. */
void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1 * n2;
    *d3 = d1 * d2;
	fraction_simplify(n3, d3);
} /* end fraction_mul */

/*this function takes 6 parameter ,and it implements fraction multiplication.
After that, it change the value of cells pointed by d3 and n3. */
void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
	*n3 = n1 * d2;
	*d3 = d1 * n2;
	fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
	// i and great common divisor
	int gcd, i;
	// to avoid overflow ,I will store the value of numerator and denominator to two long integer variable.
	long int num, den;

	num = *n;
	den = *d;
	// if numerator less than 0,store the sign to variable called as signn.
	if (num < 0){
		num *= -1;
	}
	// if denominator less than 0,store the sign to variable called as signd.
	if (den < 0){
		den *= -1;
	}

	//to find great divisor,I used a loops.
	//there is an i that starting from 0 to number or denominator.
	//The loop trys to find the great divisor by dividing all i number to numerator and denominator.
	//if remainders of divisions are 0,that's means gcd.
	for(i=1; i <= num && i <= den; i++){
		if(num % i==0 && den % i==0){
			gcd = i;
		}
	}
	// /= operator divide both numerator and denominator.
	*n /= gcd;
	*d /= gcd;
	//that is basically simplfying of fraction.
} /* end fraction_div */
