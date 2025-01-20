#include "util.h"

int main(){
	//choice sID pID and size of information 
	int choice, sID, pID, size;
	double information[3][100];

	//taking status of pID and sID
	pID = current_status(PRODUCT_FILE);
	sID = current_status(STOCK_FILE);
	//menu
	do {
		printf("Welcome operator, please select an option to continue\n\n");
		printf("\t1- File Operations\n\t2- Query products\n\t3- Check stock status\n\t");
		printf("4- Stock control by brand\n\t5- Export report\n\tchoice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				part2_file_operations(&sID, &pID);
				break;
			case 2:
				part3_search_product();
				break;
			case 3:
				part4_check_stock_status();
				break;
			case 4:
				size = part5_brand_stock_control(information);
				break;
			case 5:
				part6_stock_report(information, size);
				break;
			default:
				printf("Invalid choice!Please enter again (1-5)\n");
		}
	}while (choice != 5);
	
	return (0);
}

