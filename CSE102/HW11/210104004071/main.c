#include"util.h"

int main(){
	int choice;
	char file_name[40];
	// main functions
	do {
		printf("***********************************\n");
		printf("1-Add Family Tree\n");
		printf("2-Remove Family Tree\n");
		printf("3-Load Family Tree\n");
		printf("4-Exit\n");
		printf(">");
		scanf("%d", &choice);

		switch (choice){
			case 1:
			//add node
				sub_menu_add();
				break;
			case 2:
			// removing tree
				// it checks the file is already in directory
				// if it is ,remove file 
				printf("Enter the name of the txt file of the family tree: ");
    			scanf("%s", file_name);
				int status = remove_tree(file_name);
				if (status)
					txt_update(file_name,1);
				break;

			case 3:
			//load menu
				load_menu();
				break;
			case 4:

				break;

			default:
				printf("Invalid choice! Please try again\n");
		}
	} while (choice  != 4);




	return (0);
}
