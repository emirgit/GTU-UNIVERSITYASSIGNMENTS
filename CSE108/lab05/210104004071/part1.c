#include<stdio.h>

void display_menu(void);
float prompt_input(void);
float con_temp(int choice, float temp);

int main() {
    int choice;
    float temp;
    
    do {
        display_menu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch (choice) {
        	case 1:
            	temp = prompt_input();
            	printf("%.2f Celsius = %.2f Fahrenheit\n", temp ,con_temp(choice, temp));
            	break;
			case 2:
            	temp = prompt_input();
            	printf("%.2f Fahrenheit = %.2f Celsius\n", temp ,con_temp(choice, temp));
            	break;
            case 3:
            	printf("Thanks for using program.\nTake Care.\n");
            	break;
            default:
            	printf("Invalid choice\n");
    	}
    } while (choice != 3);
    
    return 0;
}

void display_menu(void) {
    printf("Temperature Conversion Menu\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Quit\n");
}


float prompt_input(void) {
    float temp;
    printf("Enter the temperature value to convert: ");
    scanf("%f", &temp);
    return temp;
}


float con_temp(int choice, float temp) {
    float result;
    if (choice == 1){
        result = (temp * 9 / 5) + 32;
    } 
	else {
        result = (temp - 32) * 5 / 9; 
    }
    return result;
}
