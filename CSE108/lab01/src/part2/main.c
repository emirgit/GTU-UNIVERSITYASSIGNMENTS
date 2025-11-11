#include<stdio.h>


int main(){
	int X, Y;
	double Z, max;
// taking values of X and Z from user	
	printf("Enter values of X, Z respectively :");
	scanf("%d %d", &X, &Y);

//determining the maximum value of entered numbers
	if (X >= Y)
		max = ((double) X);
	else
		max = ((double) Y);
//I convert them to double because it is needed to make Z double 
//It is enough to make one of them double
	Z = (X / (double)Y) + max / (X + Y);
 	
	printf("The value of Z is : %.3lf\n", Z);

	return (0);
}
