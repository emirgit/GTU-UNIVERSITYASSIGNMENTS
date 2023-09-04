#include<stdio.h>
#include<math.h>

#define PI 3.14
//#define PI M_PI

void cube(void);
void recpris(void);
void sphere(void);
void cone(void);
void BMIcal(void);

int main(){
	//part1
	cube();
	recpris();
	sphere();
	cone();
	//part1
	//part2
	BMIcal();
	//part2
	return (0);
}

void cube(void){
	double elen;

	printf("Enter the edge length for cube: ");
	scanf("%lf", &elen);
	printf("Surface Area = %.2lf, Volume = %.2lf\n", 6*elen*elen, elen*elen*elen);
}

void recpris(void){
	double slen, wid, heg;

	printf("Enter side length for rectangular prism: ");
	scanf("%lf", &slen);
	printf("Enter side width : ");
	scanf("%lf", &wid);
	printf("Enter side height: ");
	scanf("%lf", &heg);
	printf("Surface Area = %.2lf, Volume = %.2lf\n",2*(slen*wid + slen*heg + wid*heg),slen*wid*heg);
}

void sphere(void){
	double r;

	printf("Enter the radius for sphere: ");
	scanf("%lf", &r);
	printf("Surface Area = %.2lf, Volume = %.2lf\n",4 * PI * r * r,(4 * PI * r * r * r) / 3.0);
}

void cone(){
	double r,heg;

	printf("Enter the radius for cone: ");
	scanf("%lf", &r);
	printf("Enter the height: ");
	scanf("%lf", &heg);
	printf("Surface Area = %.2lf, Volume = %.2lf\n",PI * r * (r + sqrt(r*r + heg*heg)),PI * r * r * heg / 3);
}

void BMIcal(void){
	double weight, height, bmi ;

	printf("Enter the weight(kg) : ");
	scanf("%lf", &weight);
	printf("Enter the height(m) : ");
	scanf("%lf", &height);
	
	bmi = weight / (height * height);
	printf("Your Body Mass Index is %.1lf\n", bmi);
	if(bmi < 18.5){
		printf("Your BMI grade is: Underweight\n");
    }
	else if(bmi >= 18.5 && bmi <= 24.9){
		printf("Your BMI grade is: Average Weight\n");
	}
	else if(bmi >= 25 && bmi <= 29.9){
		printf("Your BMI grade is: Overweight\n");
	}
	else if(bmi >= 30.0){
		printf("Your BMI grade is: Obese\n");
	}
}
