#include "util.h"

/*
add_node functions adds node to family tree
the new_node is node that will add up to tree
the current for searching and adding
counter will count the name of the father and mother is valid on family tree
i is basic index element for child array
*/

void add_node1(node *father, node *mother, node* new_node, char mother_name[40], char father_name[40]){
    node *current;
    int counter = 0;
    int i;
    

    //trying to find the name of the mother in tree
    current = find_name(mother, mother_name);

    /*
    if it is found
    add the node to under the mother 
    else counter will be 0 or it will be 1
    the name of the father or mother is not found
    create an new person 
    the name will be 
    */
    if (current != NULL){
        i = 0;
        while (i < MAX_CHILD -1 && current->child[i] != NULL){
            i++;
        }
        if (i <= MAX_CHILD -2){
            current->child[i] = new_node;
            current->child[i + 1] = NULL;
            counter++;
        }
    }
    else {
        //if it is not found
        current = (node *)malloc(sizeof(node));
        current->Age = -1;
        current->Father = NULL;
        current->Mother = NULL;
        current->child[0] = NULL;
        strcpy(current->Name,mother_name);
    }
    new_node->Mother = current;
    /*trying to find the name of the father in tree
    if it is found
    add the node to under the father 
    after 2 operation
    counter can be 0 1 or 2
    0 is error
    1 is the new person is stepchild 
    2 is the 
    */
    current = find_name(father, father_name);

    if (current != NULL){
        i = 0;
        while (i < MAX_CHILD -1 && current->child[i] != NULL){
            i++;
        }
        if (i <= MAX_CHILD -2){
            current->child[i] = new_node;
            current->child[i + 1] = NULL;
            counter++;
        }
    }
    else {
        current = (node *)malloc(sizeof(node));
        current->Age = -1;
        current->Father = NULL;
        current->Mother = NULL;
        current->child[0] = NULL;
        strcpy(current->Name,father_name);
    }
    new_node->Father = current;

    new_node->child[0] = NULL;
    //if the mother and father is not found ,it is an uncorrect input
    if (counter == 0){
        printf("The father and mother name could not found !\n");
        free(new_node->Mother);
        free(new_node->Father);
        free(new_node);
    }
}

int split(char *source, char *dest, int *i){
    int dst_index = 0;
    //continue to copy the informatin in source until see '|' or '\n' character
    while (source[*i] != '|' && source[*i] != '\n'){
        dest[dst_index] = source[*i];
        (*i)++;
        dst_index++;
    }
    
    //if it is new line character don't continue to call split function 
    //else continue to until see newline character
    if (source[*i] == '\n')
        return (0);
    else if(source[*i] == '|')
        (*i)++;
    return(1);
}

int find_name_file(char file_name[40]){
    int line, counter;
    FILE *fp;
    char buffer[40];    
    //take the line
    printf(">");
    scanf("%d", &line);

    counter = 0;
    fp = fopen(FAMILYS, "r");
    
    if (fp == NULL){
        printf("Error ! File couldn't opened\n");
        return (1);
    }
    //try to get the line of the file until see line that is entered by scanf
    //if it is found close it,else close and say line is not found
    while (fgets(buffer, 40, fp)){
        if (line == counter){
            strcpy_tilln(file_name,buffer);
            fclose(fp);
            return (0);
        }

        counter++;
    }

    fclose(fp);
    printf("The line is not found \n");
    return (1);
}

//ft_strcmp check string is equal or not
//str1 goes until see new line
//str2 goes until see '\0'
int ft_strcmp(const char *str1, const char *str2){
    int i;

    i = 0;
    while (str1[i] != '\n' && str2[i] != '\0'){
        if (str1[i] != str2[i])
            return (1);

        i++;
    }

    return (0);
}

int is_strandint(const char *filename){
    int i, flag;
    //check the first 6 char is family
    if(strncmp(filename, "family",6) == 0){
        i = 6;
        flag = 0;
        //after check the all entries is integer until ".txt"
        while (filename[i] != '.'){
            if (filename[i] < '0' || filename[i] > '9'){
                flag = 1;
            }

            i++;
        }
        if (flag == 0){
            return (1);
        }
    }

    return (0);
}

int remove_tree(const char *file_name){

    /*
    The C library function int remove(const char *filename) deletes the given filename so that it is no longer accessible.

    Return Value
    On success, zero is returned. On error, -1 is returned, and errno is set appropriately

    source : "https://www.tutorialspoint.com/c_standard_library/c_function_remove.htm"
    */
    if (remove(file_name) == 0){
        printf("%s has been removed succesfully\n", file_name);
        return (1);
    }
    else{
        printf("File could not be deleted\n");
        return (0);
    }
}

void sub_menu_add(void){
    int choice, counter;
    //the roots of the family trees
    node *gfather, *gmother,*new_node;
    char mother_name[40],father_name[40];

    
    /*
    submenu
    the counter for setting roots
    counter = 0   for gfather
    counter = 1 for gmother
    the other values is not important
    */

   counter = 0;
    do{
        printf("\t1-Add node\n");
        printf("\t2-Save Family Tree\n");
        printf("\t3-Exit\n");
        printf("\t>");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                switch (counter){
                    case 0:
                        //the first input for grandfather root
                        gfather = set_roots();
                        break;
                    case 1:
                        //the second input for grandmother root
                        gmother = set_roots();
                        break;
                    default:
                        node *new_node = (node *)malloc(sizeof(node));
                        //taking the name of the person from user
                        printf("Enter the name of the person: ");
                        scanf(" %[^\n]",new_node->Name);
                        //taking the age of the person from user
                        printf("Enter the age of the person:");
                        scanf("%d",&new_node->Age);
                        //taking the mother name of the person from user
                        printf("Enter the name of the mother: ");
                        scanf(" %[^\n]",mother_name);
                        printf("Enter the name of the Father: ");
                        scanf(" %[^\n]",father_name);
                        //add nodes by sending parameters to add_node1
                        add_node1(gfather, gmother, new_node, mother_name, father_name);
                }
                counter++;
                break;
            case 2:
            // save family tree
                save_family(gfather, gmother);
                break;
            case 3:
            //exit
                break;        
            default:
                printf("Invalid choice!Please try again\n");
        }
    }while(choice != 3);
}

node *set_roots(void){
    node *new_node = (node *)malloc(sizeof(node));
    /*set roots
    the fater and mother of the roots is null
    and there is not child as a start*/
    printf("Enter the name of the person: ");
    scanf(" %[^\n]",new_node->Name);
    printf("Enter the age of the person:");
    scanf("%d",&new_node->Age);
    new_node->Father = NULL;
    new_node->Mother = NULL;
    new_node->child[0] = NULL;

    return (new_node);
}


/*
recursive finding function
*/
node* find_name(node* root, char name[40]) {
    node *result;
    int i;
    //if name is found return the addres of root
    if (strcmp(root->Name, name) == 0)
        return root;

    // Traverse in family tree recursively
    for (i = 0; root->child[i] != NULL; i++) {
        /*
        the result will be our node that we try to find return it if not null 
        it will return so many null because it will go thorugh all node
        so if it is not null return else continu to serach
        if all nodes is checked return NULL
        */
        result = find_name(root->child[i], name);
        if (result != NULL)
            return result;
    }

    return NULL;
}

void printTree(node *root, int depth) {
    int i;

    //if root is null, there is nothing to print
    if (root == NULL) {
        return;
    }

    /*print before mother or father of current root if it is not blood-relation
    it will print extra two tab to be seen like this


            Father          Mother
                    Child
    */
    if(root->Mother != NULL){
        if (root->Mother->child[0] == NULL){
            for (i = 0; i < depth; i++) {
                printf("\t"); 
            }
            printf("\tName of Mother: %s\n",root->Mother->Name);
        }
    }
    if (root->Father != NULL){
        if (root->Father->child[0] == NULL){
            for (i = 0; i < depth; i++) {
                printf("\t"); 
            }
            printf("\tName of Father : %s\n",root->Father->Name);
        }
    }

    //print the child
    for (i = 0; i < depth; i++) {
        printf("\t"); 
    }


    printf("Name: %s, Age: %d\n", root->Name, root->Age);

    //calling function recursively print all function
    for (i = 0; i < 5; i++) {
        if (root->child[i] != NULL) {
            printTree(root->child[i], depth + 1);
        }
    }
}

int save_family(node *father, node *mother){
    FILE *fp;
    char buffer[40], file_name[40];
    int flag, counter;
    int i;

    //taking file name from user
    printf("Enter the name of the family tree: ");
    scanf(" %s",file_name);

    //open the list of files txt
    fp = fopen(FAMILYS,"r");

    if (fp == NULL){
        printf("Error when trying to open file !\n");
        return 0;
    }
    
    //whether Cheching the name of the file is taken or not
    flag = 0;
    while (fgets(buffer,40,fp) != NULL){
        if (ft_strcmp(buffer, file_name) == 0){
            flag = 1;
            printf("The name of the file already taken! \n");
            break;
        }
    }

    /*
    if flag is 1 
    find unique family name
    rewind pointer and check the name of the families
    */
    if (flag == 1){
        char temp[40];

        rewind(fp);
        //passing first line
        fgets(buffer,40,fp);
        //trying to find uniquie number in file
        counter = 1;
        while (fgets(buffer,40,fp) != NULL){
            //create a file name
            strcpy(file_name, "family");
            f_itoa(counter,temp);
            strcat(file_name, temp);
            strcat(file_name, ".txt");
            // if it is found break the loop
            counter++;
            if (ft_strcmp(buffer, file_name) == 1){
                //if it is different we found the unique file name
                break;
            }
        }
    }
    /*
    closing familys.txt
    and opening uniqie family name file with 'w' mode
    */
    fclose(fp);
    fp = fopen(file_name, "w");
    
    /*printing error if there is problem*/
    if (fp == NULL){
        printf("Error when trying to save family tree\n");
        return 0;
    }
    //saving root to file
    save_roots(fp, father, mother);

    //saving father roots
    for (i = 0; father->child[i] != NULL; i++) {
        if (strcmp(father->child[i]->Mother->Name,mother->Name) == 0)
            save_father_root(fp, father->child[i]);
    }

    //if it is created,add it to list of txtes
    fclose(fp);
    txt_update(file_name, 0);
}

void save_roots(FILE *fp, node *father, node *mother){
    node *child, *parent;
    int i;
    //saving root by printing file
    //before father and his stepsons will be printed 
    fprintf(fp,"Granparents :\n");
    fprintf(fp,"%s %d", father->Name, father->Age);
    for (i = 0; father->child[i] != NULL; i++){
        child = father->child[i];
        if (strcmp(child->Mother->Name,mother->Name) != 0)
            fprintf(fp,"|%s %d %s", child->Name, child->Age, child->Mother->Name);
        
    }
    fprintf(fp,"\n");
    //after mother and her stepsons will be printed
    fprintf(fp,"%s %d", mother->Name, mother->Age);
    for (i = 0; mother->child[i] != NULL; i++){
        child = mother->child[i];
        if (strcmp(child->Father->Name,father->Name) != 0)
            fprintf(fp,"|%s %d %s", child->Name, child->Age, child->Father->Name);
        
    }
    fprintf(fp,"\nFamily Tree :\n");
}

void save_father_root(FILE *fp, node *father){
    int i;
    //the actual function to save all family 
    fprintf(fp,"%s %d %s %s\n", father->Name, father->Age, father->Father->Name, father->Mother->Name);
    //traverse child nodes recursively
    for (i = 0; father->child[i] != NULL; i++) {
        save_father_root(fp, father->child[i]);
    }

}

void txt_update(const char *filename, int method){
    FILE *fpread, *fpwrite;
    char buffer[40];
    int number;
    /*
    it read list of txt from the beginning and write it to temp.txt
    because the name of the temp.txt will be changed to list of txt files
    so it will be changed
    */
    fpread = fopen(FAMILYS, "r");
    fpwrite = fopen("temp.txt", "w");

    //pass the first line and print it to temptxt
    fgets(buffer,40,fpread);
    fputs(buffer, fpwrite);

    //if method is 0 it is adding mode
    if (method == 0){
        //if the file name is like familyX.txt print it as order
        if (is_strandint(filename)){
            
            while (fgets(buffer,40,fpread) && is_strandint(buffer)){
                //printing it is as order 
                //if we have family4.txt 1 2 3 will be printed in there
                if (strncmp(buffer, filename,6) == 0 && f_atoi(buffer + 6) > f_atoi(filename + 6))
                    break;
            
                fputs(buffer, fpwrite);
            }
            //after we see 5 4 will be printed after 5 6.. will be printed
            fputs(filename, fpwrite);
            putc('\n',fpwrite);
            //after file that starts with familyand integer printed ,other will be printed like deneme.txt
            if (strncmp(buffer,"List",4) != 0)
                fputs(buffer, fpwrite);
            while (fgets(buffer,40,fpread)){
                fputs(buffer, fpwrite);
            }
        }
        else {
            //print before familyX.txt after print our and others
            while (fgets(buffer,40,fpread) && is_strandint(buffer)){
                fputs(buffer, fpwrite);
            }
            fputs(filename, fpwrite);
            fputc('\n',fpwrite);
            if (strncmp(buffer,"List",4) != 0)
                fputs(buffer, fpwrite);
            while (fgets(buffer,40,fpread)){
                fputs(buffer, fpwrite);
            }
        }
    }
    else {
        //if method is 1, remove the selected line
        while (fgets(buffer,40,fpread)){
            if (ft_strcmp(buffer, filename) != 0)
                fputs(buffer, fpwrite);
        }
    }

    // close two of file
    fclose(fpread);
    fclose(fpwrite);

    //remove and change our temp file name
    remove(FAMILYS);
    rename("temp.txt",FAMILYS);
}

/* 
basic atoi function
if we input 123

1 will be read adn result will be 1
2 will be read and result will be 12
3 will be read and result will be 123 and it will be returned
*/
int	f_atoi(const char *str){
	int	result;
	int	i = 0;

	result = 0;
	while (str[i] && str[i] >= 48 && str[i] <= 57){
		result *= 10;
		result += str[i] - 48;
		i++;
	}

	return (result);
}

/*
it print files name as this format :
1-family1.txt
2-family2.txt
...
*/
void print_familys(void){
    FILE *fp;
    int counter;
    char buffer[40];

    fp = fopen(FAMILYS, "r");
    fgets(buffer,40,fp);
    printf("%s",buffer);
    counter = 1;
    while (fgets(buffer,40,fp)){
        printf("%d-%s", counter, buffer);
        counter++;
    }

    fclose(fp);
}
//it loads root by calling fill_roots function
FILE *load_family_root(node **mother, node** gfather, const char file_name[40]){
    FILE *fp;
    char buffer[256];
    char temp[80];

    fp = fopen(file_name, "r");

    if (fp == NULL){
        printf("File could not open\n");
        return (NULL);
    }

    //first line is Grandsparents so pass it
    fgets(buffer,256,fp);
    //second line is grandfather roots
    fgets(buffer,256,fp);
    *gfather = fill_roots(buffer, 0);
    //third is grandfather root
    fgets(buffer,256,fp);
    *mother = fill_roots(buffer, 1);
    return (fp);
}

/*load menu for part 2 
it is most comprehensive function with add_node1 in this homework
*/
void load_menu(void){
    FILE *fp;
    node *gfather, *gmother;
    node *new_node;
    char file_name[40];
    char mother_name[40],father_name[40],buffer[256];
    char name[40];
    int i = 0,choice;
    int j;

    //taking file name by using
    do {
        print_familys();
    }while(find_name_file(file_name));
    //say user whether it is found
    printf("%s has been selected.\n",file_name);
    fp = load_family_root(&gmother, &gfather, file_name);
    //pass "Family Tree:" sentence
    fgets(buffer,256,fp);

    /*
    read the file by using sscanf
    sscanf meaning string scanf
    the input will be string
    the first parameter is string other like scanf
    send this to add_node1 function*/
    while (fgets(buffer,256,fp)){
        new_node = (node *)malloc(sizeof(node));
        sscanf(buffer,"%s %d %s %s\n",new_node->Name,&new_node->Age,father_name,mother_name);
        add_node1(gfather, gmother, new_node, mother_name, father_name);
    }

    //print submenu for part 3
    do{
        printf("\t1-Add new person\n");
        printf("\t2-Remove a person\n");
        printf("\t3-Print a Person's nuclear family\n");
        printf("\t4-Search Relatives of Given Person\n");
        printf("\t5-Return to the main menu\n");
        printf("\t>");
        scanf("%d",&choice);

        //implement operation respect to input
        switch (choice){
            case 1:
                new_node = (node *)malloc(sizeof(node));
                //taking the name of the person from user
                printf("Enter the name of the person: ");
                scanf(" %[^\n]",new_node->Name);
                //taking the age of the person from user
                printf("Enter the age of the person:");
                scanf("%d",&new_node->Age);
                //taking the mother name of the person from user
                printf("Enter the name of the mother: ");
                scanf(" %[^\n]",mother_name);
                printf("Enter the name of the Father: ");
                scanf(" %[^\n]",father_name);
                add_node1(gfather, gmother, new_node, mother_name, father_name);
                break;
            case 2:
                printf("Enter the name of the person you want to remove: ");
                scanf(" %[^\n]",name);
                
                //it remove the nodes that entered
                new_node = find_name(gfather, name);
                if (new_node != NULL){ 
                    //if there is chid wanr user
                    if (new_node->child[0] != NULL){
                        //warning the user
                        printf("Warning: %s has children, removing %s will also remove her children\n",name,name);
                        printf("Do you still want to continue (Yes for continue):");
                        //mother_name is used for not declaring new variable
                        scanf("%s",mother_name);
                        //if user reply as "Yes" delete it
                        if (strcmp(mother_name,"Yes") == 0){
                            /*
                            if it has a fother (that's mean not root)
                            remove node and change child pointer in father
                            because after malloc place in memory that node information after malloc will be junk
                            and it can be used by other applications
                            */
                            if (new_node->Father != NULL){
    
                                i = 0;

                                while (new_node->Father->child[i] != NULL && new_node->Father->child[i] != new_node){
                                    i++;
                                }
                                j = i + 1;
                                while(new_node->Father->child[j] != NULL){
                                    new_node->Father->child[i] =  new_node->Father->child[j];
                                    i++;
                                    j++;
                                }
                                new_node->Father->child[i] = NULL; 
                            }
                            //removing the nod
                            free_tree(new_node);
                            printf("%s and her children have been removed from the family tree\n",name);
                        }
                    }
                    else {
                        //if it has no child ,don't warn the user and delete it directly

                        if (new_node->Father != NULL){

                            i = 0;
                            while (new_node->Father->child[i] != NULL && new_node->Father->child[i] != new_node){
                                i++;
                            }
                            j = i + 1;
                            while(new_node->Father->child[j] != NULL){
                                new_node->Father->child[i] =  new_node->Father->child[j];
                                i++;
                                j++;
                            }
                            new_node->Father->child[i] = NULL; 
                        }
                        free_tree(new_node);
                        printf("%s has been removed from the family tree\n",name);
                    }
                }
                else {
                    printf("The name you entered not found\n");
                }
                break;
            case 3:
                //case 3 for printing nuclear family of person
                printf("Enter the name of the person : ");
                scanf(" %[^\n]",name);
                
                i = 0;
                new_node = find_name(gfather, name);
                if (new_node == NULL){
                    new_node = find_name(gmother, name);
                    i = 1;
                }

                //printing parents
                if (new_node != NULL){
                    printf("Printing nuclear family of %s:\n",name);
                    
                    if (new_node->Father != NULL)
                        printf("Father: %s\n",new_node->Father->Name);
                    else {
                        printf("Father: Unknown\n");
                    }

                    if (new_node->Mother != NULL)
                        printf("Mother: %s\n",new_node->Mother->Name);
                    else {
                        printf("Father: Unknown\n");
                    }
                    j = 0;

                    /*
                    printing siblings
                    there is step child so it can be mother side or father side
                    if i is 0 it is found in father side
                    else if i is 1 it is found in mother side
                    */
                    printf("Siblings : ");
                    if (i == 0 && new_node->Father != NULL && new_node->Father->child[0] != NULL){
                        i = 0;
                        while (new_node->Father->child[i] != NULL){
                            if (new_node->Father->child[i] != new_node){
                                printf("%s ",new_node->Father->child[i]->Name);
                                j = 1;
                            }
                            i++;
                        }
                        printf("\n");
                    }
                    else if (i == 1 && new_node->Mother != NULL && new_node->Mother->child[0] != NULL){
                        i = 0;
                        while (new_node->Mother->child[i] != NULL){
                            if (new_node->Mother->child[i] != new_node){
                                printf("%s ",new_node->Mother->child[i]->Name);
                                j = 1;
                            }
                            i++;
                        }
                        printf("\n");
                    }
                    //if it is not found (that's mean j = 0 )print warning)
                    if (!j)
                        printf("Not Found\n");

                    //printing children 
                    printf("Children :");
                    if (new_node->child[0] != NULL){
                        i = 0;
                        while (new_node->child[i] != NULL ){
                            printf("%s ",new_node->child[i]->Name);
                            i++;
                        }
                        printf("\n");
                    }
                    else {
                        printf("None\n");
                    }

                    //and my family tree function 
                    //the homework more pretty with this funciton
                    printf("Family tree of %s:\n",name);
                    printTree(new_node,0);
                }
                else {
                    printf("The name you entered not found\n");
                }
                break;
            case 4:
                //it is special finding relative function 
                printf("Enter the name of the person : ");
                scanf(" %[^\n]",name);
                
                //if it is found go thorugh sub sub menu
                i = 0;
                new_node = find_name(gfather, name);
                if (new_node == NULL){
                    new_node = find_name(gmother, name);
                    i = 1;
                }

                if (new_node != NULL){
                    sub_sub_menu(gfather, gmother, new_node, i);
                }
                else {
                    printf("The name you entered not found\n");
                }

                break;
            case 5:

                break;
            default:
                printf("Invalid choice!Please try again\n");
            }
    }while(choice != 5);

    free_tree(gfather);
    free_tree(gmother);
}

/*
gender 0 male
gender 1 female*/
node *fill_roots(char buffer[256], int gender){
    node *new_node = (node *)malloc(sizeof(node));
    node *current;
    char temp[90];
    char parent_name[40];
    int condition, i, last_index = 0;
    
    //split and read roots
    split(buffer, temp, &last_index);
    sscanf(temp,"%s %d", new_node->Name, &new_node->Age);

    new_node->Father = NULL;
    new_node->Mother = NULL;

    i = 0;
    //the process of gender is different so 
    //I make the process by gender
    // the step child will be added in this operatins
    if (gender){
        do{
            condition = split(buffer, temp, &last_index);
            current = (node *)malloc(sizeof(node));
            current->Father = (node *)malloc(sizeof(node));
            sscanf(temp,"%s %d %s", current->Name, &current->Age, current->Father->Name);
            current->Mother = new_node;
            //setting father of the child
            current->Father->Age = -1;
            current->Father->child[0] = NULL;
            current->Father->Mother = NULL;
            current->Father->Father = NULL;

            new_node->child[i] = current;
            i++;

        }while(condition);
    }
    else {
       do{
            condition = split(buffer, temp, &last_index);
            current = (node *)malloc(sizeof(node));
            current->Mother = (node *)malloc(sizeof(node));
            sscanf(temp,"%s %d %s", current->Name, &current->Age, current->Mother ->Name);
            current->Father = new_node;

            //setting father of the child
            current->Mother->Age = -1;
            current->Mother->child[0] = NULL;
            current->Mother->Mother = NULL;
            current->Mother->Father = NULL;

            new_node->child[i] = current;
            i++;

        }while(condition);
    }
    new_node->child[i] = NULL;
        
    return (new_node);
}

/*
it is basic strcpy function to copy until new line character*/
void strcpy_tilln(char *dest, char *source){
    int i;

    for(i = 0; source[i] != '\n'; i++){
        dest[i] = source[i];
    }

    dest[i] = '\0';
}

/*
itoa function convert integer to string*/
void f_itoa(int num, char str[40]) {
    int i = 0;
    int digit;
    int start, end;
    char temp;
    
    //if num is 0 add 0 to string
    if (num == 0) {
        str[i] = '0';
        i++;
    }

    // continue to adding integer to string until num is 0
    while (num != 0) {
        digit = num % 10;
        str[i] = digit + '0';
        i++;
        num /= 10;
    }

    //adding null character end of the line
    str[i] = '\0';
    /*
    we need to reverse the number 
    because after it operation it will be reverse
    example
    123

    123 % 10 = 3
    "3"
    12 % 10 = 2
    ..
    "321"
    erverse it
    "123"
    so this is our input
    
    */
    start = 0;
    end = i - 1;
    while (start < end) {
        //temp value for converting values of string
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        //increase start by one decrease end by one
        start++;
        end--;
    }
}

//sub sub menu for last part
void sub_sub_menu(node *gfather, node *gmother, node *new_node, int method){
    int choice;
    int i;
    int j;
    
    do{
        printf("Select type of relatives:\n");
        printf("1-Parents\n");
        printf("2-Spouse\n");
        printf("3-Children\n");
        printf("4-Grandparents\n");
        printf("5-Cousins\n");
        printf("6-Return to sub menu\n");
        printf(">");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            //printing parents 
            printf("Printing Parents of %s:\n", new_node->Name);
            if (new_node->Father != NULL)
                printf("Father: %s\n",new_node->Father->Name);
            else {
                printf("Father: Unknown");
            }

            if (new_node->Mother != NULL)
                printf("Mother: %s\n",new_node->Mother->Name);
            else {
                printf("Father: Unknown");
            }
            break;
        case 2:
        //printing spouses 
            printf("Printing Spouse of %s:\n", new_node->Name);
            if (new_node->child[0] != NULL){
                if (new_node->child[0]->Father != NULL && strcmp(new_node->Name,new_node->child[0]->Father->Name) != 0){
                    printf("Spouse : %s\n",new_node->child[0]->Father->Name);
                }
                else if(new_node->child[0]->Mother != NULL && strcmp(new_node->Name,new_node->child[0]->Mother->Name) != 0){
                    printf("Spouse : %s\n",new_node->child[0]->Mother->Name);
                }
                else {
                    printf("Spouse : Not found\n");
                }
            }
            else {
                printf("Spouse : Not found\n");
            }
            break;
        case 3:
            //printing children

            printf("Printing Children of %s:\n", new_node->Name);
            if (new_node->child[0] != NULL){
                i = 0;
                while (new_node->child[i] != NULL ){
                    printf("%s ",new_node->child[i]->Name);
                    i++;
                }
                printf("\n");
            }
            else {
                printf("Not found\n");
            }
            break;
        case 4:
        //printing grandparents
            printf("Printing Grandparents of %s:\n", new_node->Name);
            if (new_node->Father != NULL && new_node->Father->Father != NULL && new_node->Father->Mother != NULL){
                printf("Grandparents by the father : %s %s\n",new_node->Father->Father->Name,new_node->Father->Mother->Name);
            }
            else {
                printf("Grandparents by the father : Not found\n");
            }
            if (new_node->Mother != NULL && new_node->Mother->Father != NULL && new_node->Mother->Mother != NULL){
                printf("Grandparents by the Mother : %s %s\n",new_node->Mother->Father->Name,new_node->Mother->Mother->Name);
            }
            else {
                printf("Grandparents by the Mother : Not found\n");
            }

            break;
        case 5:
        //printing cousing

            if (new_node->Mother == NULL || new_node->Father == NULL) {
                printf("The new_node does not have parents.\n");
                return;
            }
            //there is two cousing 1 is by father 2 is by mother
            //prints two of sides
            node *mother = new_node->Mother;
            node *father = new_node->Father;
            node *sibling;

            printf("Printing Cousins of %s:\n", new_node->Name);

            if (mother->Father != NULL && mother->Father->child != NULL) {
                for (i = 0; i < MAX_CHILD; i++) {
                    if (mother->Father->child[i] != NULL && mother->Father->child[i] != mother) {
                        j = 0;
                        sibling = mother->Father->child[i];
                        while (sibling->child[j] != NULL){
                            printf("%s\n", sibling->child[j]->Name);
                            j++;
                        }
                    }
                }
            }
            else {
                printf("Cousin not fount by the Mother\n");
            }
            
            if (father->Father != NULL && father->Father->child != NULL) {
                for (i = 0; i < MAX_CHILD; i++) {
                    if (father->Father->child[i] != NULL && father->Father->child[i] != father) {
                        j = 0;
                        sibling = father->Father->child[i];
                        while (sibling->child[j] != NULL){
                            printf("%s\n", sibling->child[j]->Name);
                            j++;
                        }
                    }
                }
            }
            else {
                printf("Cousin not fount by the Father\n");
            }

            break;
        case 6:

            break;
        default:
            printf("Invalid choice !Please enter again\n");
        }
    }while(choice != 6);
}

void free_tree(node *root) {
    int i;
    //freeing tree to prevent memory leak
    if (root == NULL)
        return;
    // Recursively divide into the 
    for (i = 0; i < MAX_CHILD; i++) {
        if (root->child[i] != NULL) {
            free_tree(root->child[i]);
            root->child[i] = NULL;
        }
    }

    //but there is some mother and father that cannot be accesed by tree directly
    //so try to free it
    if (root->Mother != NULL && root->Mother->Age == -1){
        free(root->Mother);
    }
    else if (root->Father != NULL && root->Father->Age == -1){
        free(root->Father);
    }
    
    // Free the current node
    free(root);
}
