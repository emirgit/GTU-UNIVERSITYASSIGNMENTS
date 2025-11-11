#include "util.h"

//globals
extern Book* root_book;
extern Student* root_student;

//definitons of functions

//this function saves the linked list to given text files
void save_changes_to_database(void){
    FILE *file;
    Book *current = root_book;
    
    //opening with write mode
    file = fopen(B_TEXT_FILE, "w");
    
    //if file not found ,wanring the user
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    //print all nodes nodes by nodes
    while (current != NULL) {
        // print the data fields to the file, and make sure separated by commas
        fprintf(file, "%s,%s,%s,%d,%d\n", current->isbn_number, current->title, current->author, current->pub_year, current->reserved_status);
        
        //go to next node after printing
        current = current->next; 
    }
    
    //closing the file to prevents error
    fclose(file); 
    printf("Data written to file successfully.\n");
}

/*
this function take a source and copy the datas in source to destination
it return index + 1 (passing next character)
it is combine of strcopy and strtok 
*/
int split_and_fill(char *dest, char* source, int* str_index){
	int i;
	
	i = 0;
	while (source[i] != ',' && source[i] != '\n'){
		dest[i] = source[i];
		i++; 
	}
	
	dest[i] = '\0';
	*str_index += i;
	if (source[i] == '\n')
		return (0);
	return (1);
}

//basic insertion sort function for sorting books
void insertion_sort_by_year(Book** books, int n) {
	int i, j;
	Book* key;

    /*
    the algorithms
    start from sorting the second element
    and sort it

    3 1 2 5 4
    after sorting it will be 
    1 3 2 5 4
    
    1 3 sorted now

    but 2 5 4 not sorted

    go thorugh 2 and sort it

    it will contiune to last elements of list
    */
	for (i = 1; i < n; i++) {
		key = books[i];
		j = i - 1;

		while (j >= 0 && books[j]->pub_year > key->pub_year) {
			books[j + 1] = books[j];
			j = j - 1;
    	}
		books[j + 1] = key;	
	}
}

//selection sort for sorting title
/*
the algorithms of selection sort is
finding min values (the first string as alphabetical)
and put it into first index
and continue to finding nex minimun
and put it into second index
and continue sorting until sort all array
*/
void selection_sort_by_title(Book** books, int n) {
    int i, j, min;
    Book* temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(books[j]->title, books[min]->title) < 0) {
                min = j;
            }
        }
        temp = books[min];
        books[min] = books[i];
        books[i] = temp;
    }
}

//selection sort for sorting title
//the algorithms explained above
void selection_sort_by_author(Book** books, int n) {
    int i, j, min;
    Book* temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(books[j]->author, books[min]->author) < 0) {
                min = j;
            }
        }
        temp = books[min];
        books[min] = books[i];
        books[i] = temp;
    }
}

//printing the books function by choice 
void print_books(Book** books, int n, int choice) {
	int i;

	switch (choice){
    //if choice is 0 sort by title
	case 0:
		for (i = 0; i < n; i++) {
        	printf("\nTitle: %s", books[i]->title);
        	printf("\nAuthor: %s", books[i]->author);
        	printf("\nPublication Year: %d\n\n", books[i]->pub_year);
    	}
		break;
    //if choice is 1 sort by author
	case 1:
		for (i = 0; i < n; i++) {
			printf("\nAuthor: %s", books[i]->author);
        	printf("\nTitle: %s", books[i]->title);
        	printf("\nPublication Year: %d\n\n", books[i]->pub_year);
    	}
		break;
//if choice is 2 sort by pub year
	case 2:
		for (i = 0; i < n; i++) {
        	printf("\nPublication Year: %d", books[i]->pub_year);
			printf("\nAuthor: %s", books[i]->author);
        	printf("\nTitle: %s\n\n", books[i]->title);
    	}
		break;
	}
}

/*
read database function for student reads the txt by seperatec commas system (like excel or csv)
it uses the split_and_fill 
you can check this function
*/
void read_database(void){
	FILE *file = fopen(S_TEXT_FILE, "r");
    char line[1024], temp_str[20];
    int i, book_index, str_index;
    
    //if the file not found , print message and return root
    if (file == NULL) {
        printf("Could not find a file named \"%s\"\n", S_TEXT_FILE);
    }

	//put root datas to different variable
    Student *current = root_student;
    
	//take file line by line
	while(fgets(line, sizeof(line), file)) {
		int add;
		//create new struct element
        Student *new_student = malloc(sizeof(Student));  
        
        //starting index from 0 
		str_index = 0;
        //if there is comma at end, increase index by 1
		str_index += split_and_fill(new_student->name, line + str_index, &str_index);
		str_index += split_and_fill(temp_str, line + str_index, &str_index);
        //ID is long long int number use atoll to convert string to long long int
        new_student->ID = atoll(temp_str);
	
        //filling the new_student book array
		book_index = 0;
		while ((add = split_and_fill(new_student->borrowed_books[book_index], line + str_index, &str_index)) && book_index < 9){
			str_index += add;
			book_index++;
		}
		
        //make sure the book array end up with Sentiel '-' value
		book_index++;
		new_student->borrowed_books[book_index][0] = SENTIEL;


        new_student->next = NULL;


        /*
        if root is null
        it is the first element
        else 
        continue to add from current
        */
        if (root_student == NULL) {
            root_student = new_student;
            current = root_student;
        } 
		else {
			current->next = new_student;
        	current = current->next;
		}
    }

    fclose(file);
}
/*
this is read function for books*/
void read_lib_database(void){
	FILE *file = fopen(B_TEXT_FILE, "r");
    char line[1024], temp_str[20];
    int i, book_index, str_index;
    
    //if the file not found , print message
    if (file == NULL) {
        printf("Could not find a file named \"%s\"\n", B_TEXT_FILE);
    }

	//put root datas to different variable
    Book *current = root_book;
    
	//take file line by line
	while(fgets(line, sizeof(line), file)) {
		//create new struct element
        Book *new_book = (Book *)malloc(sizeof(Book));  
        
		str_index = 0;
		str_index += split_and_fill(new_book->isbn_number, line + str_index, &str_index);
		str_index += split_and_fill(new_book->title, line + str_index, &str_index);
		str_index += split_and_fill(new_book->author, line + str_index, &str_index);
		str_index += split_and_fill(temp_str, line + str_index, &str_index);
        new_book->pub_year = atoi(temp_str);
		str_index += split_and_fill(temp_str, line + str_index, &str_index);
        new_book->reserved_status = atoi(temp_str);

        new_book->next = NULL;

        if (root_book == NULL) {
            root_book = new_book;
            current = root_book;
        } 
		else {
			current->next = new_book;
        	current = current->next;
		}
    }

    fclose(file);
}
/*
displaying borrowed books until see Sentiel value
it is simple print funtion
 */
void display_borrowed_books(long long int ID){
	Student *root = root_student;

	if (root == NULL){
		printf("There is no student that given linked list\n");
		return ;
	}

	int i;
	
	while (root->next != NULL){
		if (root->ID == ID){
			i = 0;
			while (root->borrowed_books[i][0] != '-'){
				printf("%d. book bought by the student is %s\n", i, root->borrowed_books[i]);
				i++;
			}
			return ;
		}

		root = root->next; 
	}

	printf("The student not found with the given ID\n");
}
/*
This function allows the user to add a new book to the library. The user will be
prompted to enter the book's ISBN number and its details (title, author, publication year). The function
should add the book to the linked list based on the chosen book management method (FIFO or LIFO).*/
void addBook(char* isbn, char* title, char* author, int publicationYear, int method){
	Book *new_book, *temp;

	//creating an Book type by using malloc
	new_book= (Book*)malloc(sizeof(Book));

	//copying data to Book
    strcpy(new_book->isbn_number,isbn);
	strcpy(new_book->author, author);
	strcpy(new_book->title,title);
	new_book->pub_year = publicationYear;
	new_book->reserved_status = 0;
	
    /*
    lifo or lifo by choice of user
    */
	if (root_book == NULL || method == 1){
		new_book->next = root_book;
		root_book = new_book;
	}
	else {
		new_book->next = NULL;
		temp = root_book;
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new_book;

	}

    save_changes_to_database();
}

/*
This function allows the user to delete a book from the library based on its ISBN
number. If the book is found, it should be removed from the linked list, and the user should be notified
that the deletion was successful. If the book is not found, the user should be informed that the book does
not exist.*/
void deleteBook(char* isbn){
    Book *current = root_book;
    Book *prev = NULL;

    // Checking whether the linked list is empty or not
    if (current == NULL){
        printf("There is no book in the linked list.\n");
        return ;
    }

    // Search for the book needs to be deleted
    while (current != NULL && strcmp(current->isbn_number, isbn) != 0) {
        prev = current;
        current = current->next;
    }

    // If the book was not found in the list ,say it to user
    if (current == NULL) {
        printf("Book not found with the given ISBN.\n");
        return;
    }

	// providing the previous node point to next one
	//but if it is first element ,change root
	if (prev == NULL) {
        root_book = current->next;
    } 
	else {
        prev->next = current->next;
    }

    // freeing the one that will be deleted
    free(current);
    printf("Book deleted successfully.\n");

    save_changes_to_database();
}

/*
This function allows the user to update the information of a book in the library
based on its ISBN number. The user will be prompted to enter the ISBN number of the book to be
updated, as well as the name of the feature to be updated and the new value for that feature. The ISBN
number cannot be updated.*/
void updateBook(char* isbn, char* feature, char* value) {
    Book *current = root_book;
    int new_year;

	if (current == NULL){
        printf("There is no book in the linked list.\n");
        return ;
    }

    // Searchin the given book 
    while (current != NULL && strcmp(current->isbn_number, isbn) != 0) {
        current = current->next;
    }

    // if the book is not in the given ,print warning the user
    if (current == NULL) {
        printf("Book not found with the given ISBN.\n");
        return;
    }

    /*
	updating the feature
	the feature can be title,autor or publiction year
	i
	*/  

    if (strcmp(feature, "title") == 0) {
        strcpy(current->title, value);
    }
    else if (strcmp(feature, "author") == 0) {
        strcpy(current->author, value);
    }
    else if (strcmp(feature, "publication year") == 0) {
        new_year = atoi(value);
        current->pub_year = new_year;
    }
    else {
        printf("Invalid feature name. Feature can be 'title', 'author', or 'publication year'.\n");
        return;
    }

    printf("Book information updated successfully.\n");

    save_changes_to_database();
}
/*
This function allows the user to filter and sort the books in the library
based on specified criteria. The user can choose to filter the books by author or publication year and sort
the filtered results by title, author, or publication year.*/
void filterAndSortBooks(int filterChoice, char* filter, int sortChoice){
	//creating an book array to storage filtered books
	Book* current = root_book;
	Book* filtered_books[MAX_BOOK];
	int pub_year, i = 0;

	//if filtering choice is 1 , convert it to integer for comparing 
	if (filterChoice == 1){
		pub_year = atoi(filter);
		//atoi returning 0 if it cannot convert it
		if (pub_year == 0){
			printf("Invalid publiction year\n");
			return ;
		}
	}

	while (current != NULL) {
		switch(filterChoice){
			case 0:
			//if the filetchoice = 0 ,check whether author is same or not
				if (strcmp(current->author, filter) == 0) {
                	filtered_books[i] = current;
					i++;
            	}

				break;
			//if the filetchoice = 1 ,check whether publiction year is same or not
			case 1:
            	if (current->pub_year == pub_year) {
                	filtered_books[i] = current;
					i++;
            	}
				break;
			default:
				printf("Invalid filtering choice. 0 for filtering by author, 1 for filtering bypublication year.\n");
				return ;
		}

        current = current->next;
    }

	//after filtering sorting it by given choice	
	switch (sortChoice)
	{
	case 0:
		//selection sort to sort by title
		selection_sort_by_title(filtered_books, i);
		//after sorting printing the books array
		print_books(filtered_books, i, 0);
		break;
	case 1:
		//selection sort to sort by author
		selection_sort_by_author(filtered_books, i);
		//after sorting printing the books array
		print_books(filtered_books, i, 1);
		break;
	case 2:
	//insertion sort to sort by years
		insertion_sort_by_year(filtered_books, i);
		//after sorting printing the books array
		print_books(filtered_books, i, 2);
		break;
	default:
		printf("Invalid Sorting choice.0 for sorting by title, 1 for sorting by author,2 for sorting by publication year.\n");
		return;
	}

}

/*
This function reverses the order of books in the linked list based on their
ISBN numbers. After the reversal, the list of books should be displayed to the user.*/
void reverseBookList(){
	Book *reversed_book = NULL;
    Book *current = root_book;
    Book *new_book, *next;
    
    if(current == NULL){
        printf("There is no books in the libray\n");
    }
    
    while (current != NULL){
        //creating new book
        new_book =(Book*)malloc(sizeof(Book));
        strcpy(new_book->isbn_number,current->isbn_number);
        strcpy(new_book->title,current->title);
        strcpy(new_book->author,current->author);
        new_book->pub_year = current->pub_year;
        new_book->reserved_status = current->reserved_status;
        //adding new_book to root part so the first of root_book will be last of reversed_book
        new_book->next = reversed_book;
        reversed_book = new_book;

        //go to next node
        current = current->next;
    }

    //creating a prev variable
    Book *prev = NULL;
    //printing and freeing the nodes
    while (reversed_book != NULL){
        printf("ISBN: %s, Title: %s, Author: %s, Pub Year: %d, Reserved: %d\n",
               reversed_book->isbn_number, reversed_book->title, reversed_book->author, reversed_book->pub_year, reversed_book->reserved_status);

        prev = reversed_book;
        reversed_book = reversed_book->next;
        free(prev);
    }

}

/*
This function allows the user to search for books based on the ISBN number,
author, or title. The user will enter the search criteria and value. The function should list the matching
books or inform the user if the book was not found.*/
void searchBooks(int searchChoice, char* searchValue) {
    Book *current = root_book;

    // if the root is null ,there is no need to search
    if (current == NULL){
        printf("There are no books in the database.\n");
        return;
    }

	//if the book is found it will be 1
    int found = 0; 
    while (current != NULL) {
        switch(searchChoice){
            case 0:
                //searching by isbn
                if (strcmp(current->isbn_number, searchValue) == 0) {
                    printf("\nTitle: %s", current->title);
                    printf("\nAuthor: %s", current->author);
                    printf("\nPublication Year: %d\n\n", current->pub_year);
                    found = 1;
                }
                break;
            case 1:
                // searching by author
                if (strcmp(current->author, searchValue) == 0) {
                    printf("\nTitle: %s", current->title);
                    printf("\nAuthor: %s", current->author);
                    printf("\nPublication Year: %d\n\n", current->pub_year);
                    found = 1;
                }
                break;
            case 2:
                // searching by title
                if (strcmp(current->title, searchValue) == 0) {
                    printf("\nTitle: %s", current->title);
                    printf("\nAuthor: %s", current->author);
                    printf("\nPublication Year: %d\n\n", current->pub_year);
                    found = 1;
                }
                break;
            default:
                printf("Invalid search choice. 0 for searching by ISBN number, 1 for searching by author, 2 for searching by title.\n");
                return;
        }
        current = current->next;
    }

    if (found == 0) {
        printf("Book not found based on the given search value.\n");
    }
}

/*
This function allows the user to borrow and return books. The
user will be prompted to enter the ISBN number of the book to be borrowed, and the function should
update the book's status as borrowed. When the book is returned, the status should be updated as
available.*/
void borrowBook(char* isbn) {
    Book *current = root_book;

    //Checking whether the linked list is empty or not
    if (current == NULL){
        printf("There are no books in the library.\n");
        return ;
    }

    //Searching for the book to be borrowed
    while (current != NULL && strcmp(current->isbn_number, isbn) != 0) {
        current = current->next;
    }

    //If the book was not found in the list,warn the user
    if (current == NULL) {
        printf("Book not found with the given ISBN.\n");
        return;
    }

    //If the book is already borrowed,say to user
    if (current->reserved_status == 1) {
        printf("The book is already borrowed.\n");
        return;
    }

    //Update the book status to borrowed
    current->reserved_status = 1;
    printf("Book borrowed successfully.\n");

    save_changes_to_database();
}

void returnBook(char* isbn) {
    Book *current = root_book;

    //Checking whether the linked list is empty or not
    if (current == NULL){
        printf("There are no books in the library.\n");
        return ;
    }

    //Searching for the book to be returned
    while (current != NULL && strcmp(current->isbn_number, isbn) != 0) {
        current = current->next;
    }

    //If the book was not found in the list,warnthe user
    if (current == NULL) {
        printf("Book not found with the given ISBN.\n");
        return;
    }

    //Update the book status to available
    current->reserved_status = 0;
    printf("Book returned successfully.\n");
    save_changes_to_database();
}
