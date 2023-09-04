#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATABASE_FILE "furniture_database.txt"
#define MAX_ITEMS 100
#define MAX_LINE_SIZE 100
#define MAX_NAME_SIZE 50
#define MAX_COLOR_SIZE 20

typedef struct{
    char name[MAX_NAME_SIZE];
    char color[MAX_COLOR_SIZE];
    double price;
    int serialNumber;
    int quantity;
} Furniture;


// Function prototypes
void alphabeticalOrder(char words[][20], int count);
void f_cpy(char *dest, char *source);
void f_rm_newline(char *str);
void loadDatabase(Furniture items[], int* itemCount);
void saveDatabase(const Furniture items[], int itemCount);
void displayAllFurniture(const Furniture items[], int itemCount);
void addFurniture(Furniture items[], int* itemCount);
void removeFurniture(Furniture items[], int* itemCount);
void searchMenu(const Furniture items[], int itemCount);
void searchByColor(const Furniture items[], int start, int end, const char* targetColor, int itemnumber);
void searchByName(const Furniture items[], int start, int end, const char* targetName);

int main() {
	Furniture items[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    loadDatabase(items, &itemCount);
    while (1) {
    	printf("******************\n");
        printf("Welcome to database of furniture shop\n");
        printf("1-See all furniture\n");
        printf("2-Add a new furniture\n");
        printf("3-Remove furniture\n");
        printf("4-Search furniture\n");
        printf("5-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAllFurniture(items, itemCount);
                break;
            case 2:
                addFurniture(items, &itemCount);
                break;
            case 3:
                removeFurniture(items, &itemCount);
                break;
                
            case 4:
            	searchMenu(items, itemCount);
            	break;
            case 5:
                saveDatabase(items, itemCount);
                printf("Program is terminated, thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void alphabeticalOrder(char words[][20], int count) {
    char temp[50];

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
}

void f_cpy(char *dest, char *source){
	int i;
	
	for (i = 0; source[i] != '\n' && source[i] != '\0'; i++){
		dest[i] = source[i];
	}
	dest[i] = '\0';
}

void f_rm_newline(char *str){
	int i;
	
	for (i = 0; str[i] != '\n' ; i++);
	str[i] = '\0';
}

void loadDatabase(Furniture items[], int* itemCount) {
    FILE* file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        printf("Error opening database file.\n");
        exit(1);
    }

    // Read the file line by line
    char line[MAX_LINE_SIZE];
    //passing first line;
    fgets(line, MAX_LINE_SIZE, file);
    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        // Tokenize the line based on tabs 
        char* token;
        token = strtok(line, "\t ");
        //cpying string with my function
        f_cpy(items[*itemCount].name, token);
        
        token = strtok(NULL, "\t ");
        f_cpy(items[*itemCount].color, token);
        
        token = strtok(NULL, "\t ");
        sscanf(token, "%lf", &items[*itemCount].price);
        
        token = strtok(NULL, "\t ");
        sscanf(token, "%d", &items[*itemCount].serialNumber);
        
        token = strtok(NULL, "\t ");
        sscanf(token, "%d", &items[*itemCount].quantity);
        
        (*itemCount)++;
    }

    fclose(file);
}

void displayAllFurniture(const Furniture items[], int itemCount) {
    int i;
    
    for (i = 0; i < itemCount; i++) {
    	printf("\n");
        printf("Name: %s\n", items[i].name);
        printf("Color: %s\n", items[i].color);
        printf("Price: %.2f\n", items[i].price);
        printf("Serial Number: %06d\n", items[i].serialNumber);
        printf("Quantity: %d\n", items[i].quantity);
        printf("----------------------------------\n");
    }
}

void addFurniture(Furniture items[], int* itemCount) {
	FILE *fp;
    if (*itemCount >= MAX_ITEMS) {
        printf("Cannot add more furniture. Maximum capacity reached.\n");
        return;
    }

	fp = fopen(DATABASE_FILE, "a");
	
	getchar(); //consuming character
    printf("\nEnter the details of the new furniture:\n");
    printf("Name: ");
    fgets(items[*itemCount].name, MAX_NAME_SIZE, stdin);
    
    printf("Color: ");
    fgets(items[*itemCount].color, MAX_COLOR_SIZE, stdin);
    printf("Price: ");
    scanf("%lf", &items[*itemCount].price);
    printf("Serial Number: ");
    scanf("%d", &items[*itemCount].serialNumber);
    printf("Quantity: ");
    scanf("%d", &items[*itemCount].quantity);
    
    f_rm_newline(items[*itemCount].name);
    f_rm_newline(items[*itemCount].color);
    /*fprintf(fp, "%s %s %lf %d %d\n", items[*itemCount].name, items[*itemCount].color, items[*itemCount].price, 
									items[*itemCount].serialNumber, items[*itemCount].quantity);
	*/					
	printf("Following Furniture is added to Database\n");

    (*itemCount)++;
    
    fclose(fp);
}

void removeFurniture(Furniture items[], int* itemCount) {
    if (*itemCount == 0) {
        printf("No furniture available to remove.\n");
        return;
    }

    int serialNumber, index, i;
    
    printf("Enter the serial number of the furniture item to remove: ");
    scanf("%d", &serialNumber);

    index = -1;
    for (i = 0; i < *itemCount; i++) {
        if (items[i].serialNumber == serialNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Furniture item with the given serial number not found.\n");
        return;
    }

    // Shift the items to remove the item at the found index
    for (i = index; i < *itemCount - 1; i++) {
        items[i] = items[i + 1];
    }

    (*itemCount)--;
    printf("Furniture item removed successfully.\n");
}

void saveDatabase(const Furniture items[], int itemCount) {
    FILE* fp = fopen(DATABASE_FILE, "w");
    
    if (fp == NULL) {
        printf("Error opening database file.\n");
        exit(1);
    }
	
	int i;
	fprintf(fp,"Name	Color	Price	SerialNumber	Quantity\n");
	for (i = 0; i < itemCount ; i++) {
		    fprintf(fp, "%s %s %lf %d %d\n", items[i].name, items[i].color, items[i].price, 
									items[i].serialNumber, items[i].quantity);  
    }
	
    fclose(fp);
}

void searchByName(const Furniture items[], int start, int end, const char* targetName) {
    if (start > end) {
        printf("Furniture with the given name not found.\n");
        return;
    }
	int mid, result;
	
    mid = (start + end) / 2;
    printf("%s", items[mid].name);
    result = strcmp(items[mid].name, targetName);

    if (result == 0) {
        printf("Furniture found:\n");
        printf("Name: %s\n", items[mid].name);
        printf("Color: %s\n", items[mid].color);
        printf("Price: %.2f\n", items[mid].price);
        printf("Serial Number: %06d\n", items[mid].serialNumber);
        printf("Quantity: %d\n", items[mid].quantity);
    } 
	else if (result > 0) {
        searchByName(items, start, mid - 1, targetName);
    } 
	else {
        searchByName(items, mid + 1, end, targetName);
    }
}

void searchByColor(const Furniture items[], int start, int end, const char* targetColor, int itemnumber) {
   if (start > end) {
        printf("Furniture with the given color not found.\n");
        return;
    }


	int mid, result, i;
    char colors[itemnumber][MAX_COLOR_SIZE];

    for (i = 0; i < itemnumber; i++) {
        strcpy(colors[i],items[i].color);
    }
    alphabeticalOrder(colors, itemnumber);
	
    mid = (start + end) / 2;
    result = strcmp(colors[mid], targetColor);

    if (result == 0) {
        printf("Furniture found:\n");
        printf("Name: %s\n", items[mid].name);
        printf("Color: %s\n", items[mid].color);
        printf("Price: %.2f\n", items[mid].price);
        printf("Serial Number: %06d\n", items[mid].serialNumber);
        printf("Quantity: %d\n", items[mid].quantity);
    } 
	else if (result > 0) {
        searchByColor(items, start, mid - 1, targetColor, itemnumber);
    } 
	else {
        searchByColor(items, mid + 1, end, targetColor, itemnumber);
    }
}

void searchMenu(const Furniture items[], int itemCount) {
	printf("\n\tSearch Menu:\n");
    printf("\t1-Search by Furniture Name\n");
    printf("\t2-Search by Color\n");
    printf("\t3-Back to Main Menu\n");
    
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice){
    	case 1:{

    		char target[50];
            printf("Enter the furniture name to search: ");
            scanf("%s",target);
            f_rm_newline(target);
            searchByName(items, 0, itemCount - 1, target);
    		break;
    		}
    	case 2:{
    		char target[50];
            printf("Enter the furniture color to search: ");
            scanf("%s",target);
            f_rm_newline(target);
            searchByColor(items, 0, itemCount - 1, target, itemCount);
    		break;
    	}
    	case 3:
    		break;
    		
    	default:
    		printf("Invalid choice. Please try again.\n");
            break;
	}
}
