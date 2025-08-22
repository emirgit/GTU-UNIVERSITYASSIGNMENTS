#include"util.h"

Book* root_book = NULL;
Student* root_student = NULL;

int main() {
    /*
    choice isbn title author publication year method is for add book function
    feature and value for updating
    filter filterchoice sortchice for filterin
    search value and serach choice for seracihn*/
    int choice;
    char isbn[20], title[80], author[40], feature[20], value[80], filter[20], searchValue[80];
    int publicationYear, method, filterChoice, sortChoice, searchChoice;

    //reading text file to fill root_book and root_student
	read_database();
	read_lib_database();
	
    /*library management menu
    the menu is simple
    printing menu and taking parameter of function from user
    and send parameter inputted value to function
    input 9 to exit
    and free all roots
    */
    do {
        printf("\n***-- LIBRARY MANAGEMENT --***\n");
        printf("\t1. Add Book\n");
        printf("\t2. Delete Book\n");
        printf("\t3. Update Book\n");
        printf("\t4. Filter and Sort Books\n");
        printf("\t5. Reverse Book List\n");
        printf("\t6. Search Books\n");
        printf("\t7. Borrow Book\n");
        printf("\t8. Return Book\n");
        printf("\t9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
            //taking parameter from user
                printf("Enter ISBN: ");
                scanf("%s", isbn);
                printf("Enter title: ");
                //%[^\n] this allow us to take space charactar too
                scanf(" %[^\n]", title);
                printf("Enter author: ");
                scanf(" %[^\n]", author);
                printf("Enter publication year: ");
                scanf("%d", &publicationYear);
                printf("Enter method (0 for FIFO, 1 for LIFO): ");
                scanf("%d", &method);
                addBook(isbn, title, author, publicationYear, method);
                break;

            case 2:
                printf("Enter ISBN of book to delete: ");
                scanf("%s", isbn);
                deleteBook(isbn);
                break;

            case 3:
                printf("Enter ISBN of book to update: ");
                scanf("%s", isbn);
                printf("Enter feature to update (title, author, or publication year): ");
                scanf(" %[^\n]", feature);
                printf("Enter new value for that feature: ");
                scanf(" %[^\n]", value);
                updateBook(isbn, feature, value);
                break;

            case 4:
                printf("Enter choice for filtering (0 for author, 1 for publication year): ");
                scanf("%d", &filterChoice);
                printf("Enter filter criteria: ");
                scanf(" %[^\n]", filter);
                printf("Enter choice for sorting (0 for title, 1 for author, 2 for publication year): ");
                scanf("%d", &sortChoice);
                filterAndSortBooks(filterChoice, filter, sortChoice);
                break;

            case 5:
                reverseBookList();
                break;

            case 6:
                printf("Enter choice for searching (0 for ISBN, 1 for author, 2 for title): ");
                scanf("%d", &searchChoice);
                printf("Enter search value: ");
                scanf(" %[^\n]", searchValue);
                searchBooks(searchChoice, searchValue);
                break;

            case 7:
                printf("Enter the ISBN of the book you want to borrow: ");
                scanf("%s", isbn);
                borrowBook(isbn);
                break;

            case 8:
                printf("Enter the ISBN of the book you want to return: ");
                scanf("%s", isbn);
                returnBook(isbn);
                break;

            case 9:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a number between 1 and 9.\n");
        }
    } while(choice != 9);

    Book *prev;
    Student *temp;
    //freeing the root to prevent memory leaks
    while (root_book != NULL){
        prev = root_book;
        root_book = root_book->next;
        free(prev);
    }

    while(root_student != NULL){
        temp = root_student;
        root_student = root_student->next;
        free(temp);
    }

	return (0);
}
