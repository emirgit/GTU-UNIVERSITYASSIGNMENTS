#include <stdio.h>
#include <math.h>

//PART1-------------------------------------------------------------------------------------------------
typedef struct {
    double elements[3][3];
    double det;
} matrix;

typedef struct {
	double x;
	double y;
	double z;
} vector;

typedef struct {
	
	double a, b, c, d;
	
} third_order_polynomial;

typedef struct {
	double x7, x6, x5, x4, x3, x2, x1;
    char constant;
    double value_at_interval;
} polynomial;

void print_matrix(matrix m) {
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%8.4f	", m.elements[i][j]);
        }
        printf("\n");
    }
    
    printf("Determinant: %8.4f\n", m.det);
}

void determinant_of_matrix(matrix *initial_matrix) {
	initial_matrix -> det = initial_matrix->elements[0][0] * ((initial_matrix->elements[1][1] * initial_matrix->elements[2][2]) - (initial_matrix->elements[2][1] * initial_matrix->elements[1][2])) -
    initial_matrix->elements[0][1] * ((initial_matrix->elements[1][0] * initial_matrix->elements[2][2]) - (initial_matrix->elements[2][0] * initial_matrix->elements[1][2])) +
    initial_matrix->elements[0][2] * ((initial_matrix->elements[1][0] * initial_matrix->elements[2][1]) - (initial_matrix->elements[2][0] * initial_matrix->elements[1][1]));
          
    
}

void invert_matrix(matrix* initial_matrix, matrix* inverted_matrix) {
	double det = 0.0;
    double a,b,c,d,e,f,g,h,i;
    determinant_of_matrix(initial_matrix);
    det = initial_matrix->det;
          
    if (det == 0) {
        printf("Matrix is not invertible.\n");
        return;
    }
    
    a = initial_matrix->elements[0][0];
    b = initial_matrix->elements[0][1];
    c = initial_matrix->elements[0][2];
    d = initial_matrix->elements[1][0];
    e = initial_matrix->elements[1][1];
    f = initial_matrix->elements[1][2];
    g = initial_matrix->elements[2][0];
    h = initial_matrix->elements[2][1];
    i = initial_matrix->elements[2][2];
    inverted_matrix->elements[0][0] = (e*i - f*h) / det;
    inverted_matrix->elements[0][1] = (c*h - b*i) / det;
    inverted_matrix->elements[0][2] = (b*f - c*e) / det;
    inverted_matrix->elements[1][0] = (f*g - d*i) / det;
    inverted_matrix->elements[1][1] = (a*i - c*g) / det;
    inverted_matrix->elements[1][2] = (c*d - a*f) / det;
    inverted_matrix->elements[2][0] = (d*h - e*g) / det;
    inverted_matrix->elements[2][1] = (b*g - a*h) / det;
    inverted_matrix->elements[2][2] = (a*e - b*d) / det;
    inverted_matrix->det = det;
	
	print_matrix(*inverted_matrix); 
}

//PART2-------------------------------------------------------------------------------------------------
double find_orthogonal(vector vec_1, vector vec_2, vector* output_vec) {
	double dot_product;
	double vec_1_mag;
	double vec_2_mag;
	// calculating the cross product of vec_1 and vec_2(that's mean outpot vector
    output_vec->x = vec_1.y * vec_2.z - vec_1.z * vec_2.y;
    output_vec->y = vec_1.z * vec_2.x - vec_1.x * vec_2.z;
    output_vec->z = vec_1.x * vec_2.y - vec_1.y * vec_2.x;
    
    // calculating the angle between vec_1 and vec_2
    dot_product = vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z;
    vec_1_mag = sqrt(vec_1.x * vec_1.x + vec_1.y * vec_1.y + vec_1.z * vec_1.z);
    vec_2_mag = sqrt(vec_2.x * vec_2.x + vec_2.y * vec_2.y + vec_2.z * vec_2.z);
    
    return acos(dot_product / (vec_1_mag * vec_2_mag)) * 180.0 / M_PI;
}


//PART3-------------------------------------------------------------------------------------------------

//it will integrate 7 order polynomial
double integrate(double a, double b, double c, double d, double e, double f, double g, int x) {
	return a * pow(x,7) + b * pow(x,6) + c * pow(x,5) + d * pow(x,4) + e * pow(x,3) + f * x * x + g * x;
}

polynomial get_integral(third_order_polynomial p1, third_order_polynomial p2, int a, int b) {
	polynomial result;
	result.constant = 'C';
	//I calculated this algorithm in book
	result.x7 = p1.a * p2.a / 7.0;
	result.x6 = (p1.a * p2.b + p1.b * p1.a) / 6.0 ;
	result.x5 = (p1.b * p2.b + p1.a * p2.c + p1.c * p2.a) / 5.0;
	result.x4 = (p1.a * p2.d + p1.d * p2.a + p1.b * p2.c + p1.c * p2.b) / 4.0;
	result.x3 = (p1.b * p2.d + p1.d * p2.b + p1.c * p2.c) / 3.0;
	result.x2 = (p1.c * p2.d + p1.d * p2.c) / 2.0;
	result.x1 =	(p1.d * p2.d);
	
	//definite integral formula (a,b) = b - 1
	result.value_at_interval = integrate(result.x7, result.x6, result.x5, result.x4, result.x3, result.x2, result.x1, b) - integrate(result.x7, result.x6, result.x5, result.x4, result.x3, result.x2, result.x1, a);

	return result;
}

int main() {
	//PART1-------------------------------------------------------------------------------------------------
    matrix inverted_M,M = {
        {{1.0000, 0.9134, 0.2785},
         {0.9058, 0.6324, 0.5469},
         {0.1270, 0.0975, 0.9575}},
        0.0
    };

    print_matrix(M);
    invert_matrix(&M, &inverted_M);
    //PART2-------------------------------------------------------------------------------------------------
    vector vec1 = {1.0, -2.0, 1.0};
    vector vec2 = {3.0, 1.0, -1.0};
    vector output_vec;
    double angle = find_orthogonal(vec1, vec2, &output_vec);
    printf("Angle between first vector and second vector is %.4lf degrees.\n", angle);
    printf("The vector orthogonal is (%.4lf, %.4lf, %.4lf).\n", output_vec.x, output_vec.y, output_vec.z);
    
    //PART3-------------------------------------------------------------------------------------------------
    third_order_polynomial pol1, pol2;
    polynomial result;
    int a, b;
    
    printf("Enter coefficients of the first polynomial respectively (a b c d): ");
    scanf("%lf %lf %lf %lf", &pol1.a, &pol1.b, &pol1.c, &pol1.d);
    printf("Enter coefficients of the second polynomial respectively (a b c d): ");
    scanf("%lf %lf %lf %lf", &pol2.a, &pol2.b, &pol2.c, &pol2.d);
    printf("Enter interval of integretion: (i.e -1 to 1)");
    scanf("%d %d", &a, &b);
    result = get_integral(pol1, pol2, a, b);
    printf("Integrated polynomial: %.2lfx^7 + %.2lfx^6 + %.2lfx^5 + %.2lfx^4 + %.2lfx^3 + %.2lfx^2 + %.2lfx + %c\n",result.x7, result.x6, result.x5, result.x4, result.x3, result.x2, result.x1,result.constant);
    printf("Value between [%d, %d]: %lf\n", a, b, result.value_at_interval);
    
    return 0;
}
