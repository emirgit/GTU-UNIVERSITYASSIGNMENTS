#include "util.h"

/*
current_status takes an array name and open it
it takes max value
it reads all pID by using reading integer
if it is 123
it takes 1
after it takes 2
multiply 1 by 10
and append 2
12
12 * 10 = 120
120 + 3
123 as integer

*/

int current_status(char file[]){
	FILE *fp;
	char str[100];
	int temp, i, max;
	

	fp = fopen(file, "r");
	
	//passing first line because there is no pID there
	fgets (str, 100, fp);
	max = 0;
	
	while (fgets (str, 100, fp)){
		i = 0;
		temp = 0;
		while (str[i] != ',')
		{
			temp *= 10;
			temp += str[i] - 48;
			i++;
		}
		if (temp > max){
			max = temp;
		}
	}
	
	fclose(fp);
	return max;
}

//find feature is basic strcmp function but i changed it a little bit
int find_feature(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	
	while (s1[i] == s2[i] && s1[i] != ',' && s2[i] && '\n' && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	if (s1[i] == ',' || s1[i] == '\n' || s1[i] == 13)
		return (0 - s2[i]);
		
	return (s1[i] - s2[i]);
}

//this function check the sID or pId is valid or not
int is_in_it(int ID, char file[]){
	FILE *fp;
	char str[100];
	int temp, i;

	fp = fopen(file, "r");
	
	//passing first line because there is no pID there
	fgets (str, 100, fp);
	
	while (fgets (str, 100, fp)){
		i = 0;
		temp = 0;
		
		while (str[i] != ',')
		{
			temp *= 10;
			temp += str[i] - 48;
			i++;
		}
		
		if (temp == ID){
			fclose(fp);
			return (0);
		}
	}
	
	fclose(fp);
	return (1);
}

/* Function to sort an array using insertion sort */
void insertionSort(int arr[], int n)
{
    int i, key, j;
    
    for (i = 1; i < n; i++) {
    
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            
        }
        
        arr[j + 1] = key;
    }
}

//basic strcpy but ı changed it
void f_strcpy(char *dest, char *src){

	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	
}

//sorting array by not changin it just using another index array like it is showed in lecture
void sort_array(double arr[], int index[], int size){
	int i, j, temp;
    // Initialize index array
    
    for (i = 0; i < size; i++) {
        index[i] = i;
    }

    // Sort index array based on values in original array
    for (i = 0; i < size - 1; i++) {
    
        for (j = i + 1; j < size; j++) {
        
            if (arr[index[i]] > arr[index[j]]) {
                temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }
}

//it takes an integer and return the digit number of the integer
int num_digits(int n) {

    int count = 0;
    if (n == 0) {
        return 1;
    }
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

//it takes four input and print them by using fprinft to file
void add_new_product(int *pID){
	FILE *fp;
	char type, name[MAX_NAME_LEN], brand[MAX_BRAND_LEN];
	double price;
	
	printf("\t\t\tType of product: ");
	scanf(" %c",&type);
	printf("\t\t\tName of product: ");
	scanf("%s",name);
	printf("\t\t\tBrand of product: ");
	scanf("%s",brand);
	printf("\t\t\tPrice of product: ");
	scanf("%lf",&price);
	
	fp = fopen(PRODUCT_FILE,"a");
	(*pID)++;
	fprintf(fp, "\n%d,%c,%s,%s,%.1lf", *pID, type, name, brand, price);
	fclose(fp);
}

//deleting product function
void delete_product(int *pID){
	FILE *fp1, *fp2;
	char str[100];
	int temp, del, i, flag;


	//checking the pID is correct or not	
	do{
		printf("pID of the product to be deleted: ");
		scanf("%d",&del);
		flag = is_in_it(del, PRODUCT_FILE);
		if (flag)
			printf("There is no product by that pID\n");
	} while (flag);
	
	fp1 = fopen(PRODUCT_FILE, "r");
	fp2 = fopen("temp.txt", "w");
	
	//passing first line because there is no pID there
	fgets (str, 100, fp1);
	fputs(str, fp2);
	flag = 0;
	
	while (fgets (str, 100, fp1)){
		i = 0;
		temp = 0;
		
		while (str[i] != ',')
		{
			temp *= 10;
			temp += str[i] - 48;
			i++;
		}
	//if temp is pID that deleted don't print it 
	//and the pId after it reduce the temp value by 1
		if (temp != del){
			if (flag){
				fprintf(fp2,"%d",temp - 1);
				fputs(str + num_digits(temp), fp2);
			}
			else
				fputs(str, fp2);
		}
		else
			flag = 1;
	}
	
	(*pID)--;
	
	fclose(fp1);
	fclose(fp2);
	remove(PRODUCT_FILE);
	rename("temp.txt", PRODUCT_FILE);
}

void update_product(void){
	FILE *fp1, *fp2;
	char str[100],feature[15];
	int del, temp, i, after_comma, ctr, flag;
	
	
	do{
		printf("pID of the product to be updated: ");
		scanf("%d",&del);
		flag = is_in_it(del, PRODUCT_FILE);
		if (flag)
			printf("There is no product by that pID\n");
	} while (flag);

	fp1 = fopen(PRODUCT_FILE, "r");
	fgets (str, 100, fp1);
	
	//it find the comma after the feature
	do {
		printf("Name of the feature of product to be updated: ");
		scanf("%s",feature);
		if (!find_feature("pID",feature)){
			printf("pID cannot be changed\n");
			return;
		}
			
		i = 0;
		after_comma = 1;
		
		while (str[i] != '\n'){
			if (str[i] == ','){
				if (find_feature(str + i + 1, feature) == 0 ){
					break;
				}
				after_comma++;
			}
			i++;
		}
		if (str[i] == '\n')
			printf("there is no feature by that name!\n");
	} while (str[i] == '\n');
	
	printf("What is the new feature of %d pID product",del);
	scanf("%s",feature);
	fp2 = fopen("temp.txt", "w");
	fputs(str, fp2);
	
	//checking after_comma and print updated value
	while (fgets(str, 100, fp1)){
		i = 0;
		temp = 0;
		
		while (str[i] != ',')
		{
			temp *= 10;
			temp += str[i] - 48;
			i++;
		}
		if (temp == del){
			ctr = 0;
			i = 0;
			
			while (str[i] != '\0'){
				if (str[i] == ','){
					ctr++;	
					if (ctr == after_comma){
						fputc(str[i], fp2);	
						fputs(feature, fp2);
						i++;
						while (str[i] != ',' && str[i] != '\0' && str[i] != '\n'){
							i++;
						}
						if (str[i] == '\0')
							break;
					}
				}
				fputc(str[i], fp2);	
				i++;
			}
		}
		else{
			fputs(str, fp2);
		}
	}
	
	fclose(fp1);
	fclose(fp2);
	remove(PRODUCT_FILE);
	rename("temp.txt", PRODUCT_FILE);
}

void add_feature_product(void){
	FILE *fp1, *fp2;
	char str[100], feature[15];
	int i;
	
	printf("Name of the feature of product to be appended: ");
	scanf("%s",feature);
	fp1 = fopen(PRODUCT_FILE, "r");
	fp2 = fopen("temp.txt", "w");
	
	//passing first line because there is no pID there
	fgets (str, 100, fp1);
	i = 0;
	
	while (str[i] != '\n' && str[i] != '\r'){
		
		fputc(str[i], fp2);
		i++;
	}
	fputc(',', fp2);
	fputs(feature, fp2);
	fputc('\n', fp2);
	
	while (fgets (str, 100, fp1)){
		
		i = 0;
		while (str[i] != '\0' && str[i] != '\n' && str[i] != '\r'){
			fputc(str[i], fp2);
			i++;
		}
		fputs(",NONE", fp2);
		if (str[i] != '\0')
			fputc('\n', fp2);
	}
	
	fclose(fp1);
	fclose(fp2);
	remove(PRODUCT_FILE);
	rename("temp.txt", PRODUCT_FILE);
}


//adding new stock like add new product
void add_new_stock(int *sID){
	FILE *fp;
	char branch[MAX_BRANCH_LEN];
	int temp, current_stock, flag;
	
	do{
		printf("pID of product which will be stocked: ");
		scanf("%d",&temp);
		flag = is_in_it(temp, PRODUCT_FILE);
		if (flag)
			printf("There is no product by that pID\n");
	} while (flag);
	
	printf("Branch of stock: ");
	scanf("%s",branch);
	printf("What is current stock: ");
	scanf("%d",&current_stock);
	
	fp = fopen(STOCK_FILE,"a");
	(*sID)++;
	fprintf(fp, "%d,%d,%s,%d\n", *sID, temp, branch, current_stock);
	fclose(fp);
}

//deleting stock like deleting product
void delete_stock(int *sID){
	FILE *fp1, *fp2;
	char str[100];
	int temp, del, i, flag;
	
	do{
		printf("sID of the stock to be deleted: ");
		scanf("%d",&del);
		flag = is_in_it(del, STOCK_FILE);
		if (flag)
			printf("There is no stock by that sID\n");
	} while (flag);
	
	fp1 = fopen(STOCK_FILE, "r");
	fp2 = fopen("temp.txt", "w");
	
	//passing first line because there is no pID there
	fgets (str, 100, fp1);
	fputs(str, fp2);
	flag = 0;
	while (fgets(str, 100, fp1)){
		i = 0;
		temp = 0;
		while (str[i] != ',')
		{
			temp *= 10;
			temp += str[i] - 48;
			i++;
		}
		if (temp != del){
			if (flag){
				fprintf(fp2,"%d",temp - 1);
				fputs(str + num_digits(temp), fp2);
			}
			else
				fputs(str, fp2);
		}
		else
			flag = 1;
	}
	(*sID)--;
	
	fclose(fp1);
	fclose(fp2);
	remove(STOCK_FILE);
	rename("temp.txt", STOCK_FILE);
}

//updating stock like updating product
void update_stock(void){
	FILE *fp1, *fp2;
	char str[100],feature[15];
	int del, temp, i, after_comma, ctr, flag;
	
	
	do{
		printf("sID of the stock to be updated: ");
		scanf("%d",&del);
		flag = is_in_it(del, STOCK_FILE);
		if (flag)
			printf("There is no stock by that sID\n");
	} while (flag);

	fp1 = fopen(STOCK_FILE, "r");
	fgets (str, 100, fp1);
	
	do {
		printf("Name of the feature of stock to be updated: ");
		scanf("%s",feature);
		if (!find_feature("sID",feature)){
			printf("sID cannot be changed\n");
			return ;
		}
		i = 0;
		after_comma = 1;
		while (str[i] != '\n'){
			if (str[i] == ','){
	
				if (find_feature(str + i + 1, feature) == 0){
					break;
				}
				after_comma++;
			}
			i++;
		}
		if (str[i] == '\n')
			printf("there is no feature by that name!\n");
	} while (str[i] == '\n');

	printf("What is the new feature of %d sID product: ",del);
	scanf("%s",feature);
	fp2 = fopen("temp.txt", "w");
	fputs(str, fp2);
	
	while (fgets (str, 100, fp1)){
		i = 0;
		temp = 0;
		while (str[i] != ',')
		{
			temp *= 10;
			temp += str[i] - 48;
			i++;
		}
		if (temp == del){
			ctr = 0;
			i = 0;
			while (str[i] != '\0'){
				if (str[i] == ','){
					ctr++;
					if (ctr == after_comma){
						fputc(str[i], fp2);
						fputs(feature, fp2);
						i++;
						while (str[i] != ',' && str[i] != '\0' && str[i] != '\n')
							i++;
						if (str[i] == '\0')
							break;
					}
				}
				fputc(str[i], fp2);	
				i++;
			}
		}
		else{
			fputs(str, fp2);
		}
	}
	
	fclose(fp1);
	fclose(fp2);
	remove(STOCK_FILE);
	rename("temp.txt", STOCK_FILE);
}

//the menu of part 2 and operatins
void part2_file_operations(int *sID,int *pID) {
	int choice;
	
	do {
	    printf("\n\t\tFILE OPERATIONS\n");
	    printf("\t\tProduct Menu\n");
	    printf("\t\t1. Add a new product\n");
	    printf("\t\t2. Delete a product\n");
	    printf("\t\t3. Update a product\n");
	    printf("\t\t4. Add feature to products\n");
	    printf("\t\tStock Menu\n");
	    printf("\t\t5. Add a new stock entry\n");
	    printf("\t\t6. Delete a stock entry\n");
		printf("\t\t7. Update a stock entry\n");
		printf("\t\t8. Back to main menu\n");
		printf("\t\tEnter your choice: ");
	    scanf("%d", &choice);
	
	    switch (choice) {
	        case 1:
				add_new_product(pID);
				break;
	        case 2:
				delete_product(pID);
				break;
	        case 3:
				update_product();
	            break;
	        case 4:
	        	add_feature_product();
	            break;
	        case 5:
				add_new_stock(sID);
				break;
	        case 6:
	    		delete_stock(sID);
				break;
	        case 7:
				update_stock();
				break;			
	        case 8:
	            return ;
	        default:
	            printf("Invalid choice. Please try again.\n");
	    }
	} while(choice != 8);
}

//listing all products like a table
void list_all_products(void){
	FILE *fp;
	int i,ctr, ch;
	
	fp = fopen(PRODUCT_FILE, "r");
	ctr = 10;
	printf("|");
	while ((ch = fgetc(fp)) != EOF){
		if (ch == ','){
			for (i = 0;i < ctr;i++)
				printf(" ");	
			printf("|");
			ctr = 10;
		}
		else if (ch == '\n'){
			ctr = 10;
			printf("%c",ch);
			printf("|");
		}
		else{
			printf("%c",ch);
			ctr--;
		}
	}
	fclose(fp);
}

//filtering a product by not taking all of it an array like it is said
//ı used algorithm that ı wrote in upgrade
//but it can be bigger than 
//so ı upgraded algotihm 
//ı can explain that if the session is online
int filter_products(char filtered_products[][100]){
	FILE *fp;
	char str[100], filter[60], feature[15];
	char filter_values[10][15];
	int after_commas[10],after_comma, ctr, valctr, i, commactr, index;
	
	fp = fopen(PRODUCT_FILE, "r");
	fgets(str, 100, fp);
	
	/*do {
	
		printf("Select the type of filter (e.g. brand,Samsung,type,O) : ");
		scanf("%s",filter);
		i = 0;
		after_comma = 1;
		while (str[i] != '\n'){
			if (str[i] == ','){
				if (find_feature(str + i + 1, feature) == 0){
					break;
				}
				after_comma++;
			}
			i++;
		}
		if (str[i] == '\n')
			printf("there is no feature by that name!\n");
	} while (str[i] == '\n');
	*/
	printf("Select the type of filter (e.g. Brand,Samsung,Type,O !!case sensitive!!) : ");
	scanf("%s",filter);
	ctr = 0;
	valctr = 0;
	index = 0;
	do {
		i = 0;
		while (filter[index] != ','){
			feature[i] = filter[index];
			index++;
			i++;
		}
		feature[i] = '\0';
		//pass ',' because while end up at ','
		index++;
		i = 0;
		after_comma = 1;
		while (str[i] != '\n'){
			if (str[i] == ','){
				if (find_feature(str + i + 1, feature) == 0){
					break;
				}
				after_comma++;
			}
			i++;
		}
		after_commas[ctr] = after_comma;
		ctr++;
		

		i = 0;
		while (filter[index] != ',' && filter[index] != '\0'){
			filter_values[valctr][i] = filter[index];
			index++;
			i++;
		}
		filter_values[valctr][i] = '\0';
		valctr++;
		//if it continue to loop that's mean index at ',' increment index
		index++;
		//checking index - 1 because we pass it
	} while (filter[index - 1] != '\0');
	
	/*int sorted[ctr];
	for (index = 0;index < ctr; ctr++){
		sorted[index] = after_commas[index];
	}
	insertionSort(sorted, ctr);
	*/
	int flag, product = 0;
	while (fgets(str, 100, fp)){
		commactr = 0;
		i = 0;
		flag = 1;
		while (str[i] != '\0'){
			if (str[i] == ','){
				commactr++;
				for (index = 0; index < ctr; index++){
					if (commactr == after_commas[index]){
						if (find_feature(str + i + 1, filter_values[index])){
							flag = 0;
							break;
						}
					}
				}
				if (flag == 0)
					break;
			}
			i++;
		}
		if (flag == 1){
			f_strcpy(filtered_products[product],str);
			product++;
		}
		
	}
	fclose(fp);
	return product;
}

//seaching product menu 
void part3_search_product(void){
	int choice, product, i;
	char filtered_product[20][100];
	
	do {
	    printf("\n\t\tSearch Product\n");
	    printf("\t\tProduct Menu\n");
	    printf("\t\t1. List all product\n");
	    printf("\t\t2. Filter products by brand, type, price, or a user-defined feature\n");
	    printf("\t\t3. Back to main menu\n");
		printf("\t\tEnter your choice: ");
	    scanf("%d", &choice);
	
	    switch (choice) {
	        case 1:
				list_all_products();
				break;
	        case 2:
				product = filter_products(filtered_product);
				for (i = 0; i < product; i++){
					printf("%s",filtered_product[i]);
				}
				break;		
	        case 3:
	            return ;
	        default:
	            printf("Invalid choice. Please try again.\n");
	    }
	} while(choice != 3);
}

//querying product by brand name and pID
int query_product(void){
	FILE *fp;
	char str[100],branch[2][MAX_BRANCH_LEN];
	int temp, flag, sID, pID, stock, res;
	
	do{
		printf("pID of the product to query: ");
		scanf("%d",&temp);
		flag = is_in_it(temp, PRODUCT_FILE);
		if (flag)
			printf("There is no product by that pID\n");
	} while (flag);
	
	printf("Which branch do you want to query? : ");
	scanf("%s",branch[1]);
	
	fp = fopen(STOCK_FILE, "r");
	fgets(str, 100, fp);
	res = 0;
	while (fscanf(fp,"%d,%d,%[^,],%d", &sID, &pID, branch[0], &stock) != EOF){
		if (temp == pID && !find_feature(branch[0], branch[1])){
			res = stock;
		}
	}
	fclose(fp);
	return res;
}

//querying all product by branch
int query_all_product(int filtered_stock[][100]){
	FILE *fp;
	char str[100],branch[2][MAX_BRANCH_LEN];
	int sID, pID, stock, i;
	
	printf("Which branch do you want to query? : ");
	scanf("%s",branch[1]);
	
	fp = fopen(STOCK_FILE, "r");
	fgets(str, 100, fp);
	i = 0;
	while (fscanf(fp,"%d,%d,%[^,],%d", &sID, &pID, branch[0], &stock) != EOF){
		if (!find_feature(branch[0], branch[1])){
			filtered_stock[0][i] = sID;
			filtered_stock[1][i] = pID;
			filtered_stock[2][i] = stock;
			printf("the stock of %d pId is %d \n",pID,stock);
			i++;
		}
	}
	fclose(fp);
	return i;
}

//querying a product that out of stock
int query_out_pruduct(int filtered_stock[][100]){
	FILE *fp;
	char str[100],branch[2][MAX_BRANCH_LEN];
	int sID, pID, stock, i;
	
	printf("Which branch do you want to query? : ");
	scanf("%s",branch[1]);
	
	fp = fopen(STOCK_FILE, "r");
	fgets(str, 100, fp);
	i = 0;
	while (fscanf(fp,"%d,%d,%[^,],%d", &sID, &pID, branch[0], &stock) != EOF){
		if (stock == 0 && !find_feature(branch[0], branch[1])){
			filtered_stock[0][i] = sID;
			filtered_stock[1][i] = pID;
			filtered_stock[2][i] = stock;
			printf("%d pID is out of stock in %s\n", pID, branch[1]);
			i++;
		}
	}
	fclose(fp);
	return i;	
}

//checking stock menu and itsel

void part4_check_stock_status(void){
	int choice;
	int filtered_stock[3][100], stock;
	
	do {
	    printf("\n\t\tStock Status\n");
	    printf("\t\t1. Query product by branch\n");
	    printf("\t\t2. Query all product by branch\n");
	    printf("\t\t3. Find out-of-stock products by branch\n");
	    printf("\t\t4. Back to main menu\n");
		printf("\t\tEnter your choice: ");
	    scanf("%d", &choice);
	
	    switch (choice) {
	        case 1:
	        	stock = query_product();
	        	printf("The stock of the product is %d",stock);
				break;
	        case 2:
				stock = query_all_product(filtered_stock);
				break;
			case 3:
				stock = query_out_pruduct(filtered_stock);
				break;
	        case 4:
	            return ;
	        default:
	            printf("Invalid choice. Please try again.\n");
	    }
	} while(choice != 4);	
}

//brand stock control take 2d array and fill it
int part5_brand_stock_control(double information[][100]){
	FILE *fp1, *fp2;
	char wanted[MAX_BRAND_LEN],brand[MAX_BRAND_LEN], str[100];
	int current_stock, pID, pID_stock, i;
	double price;
	
	printf("Which brand do you want information about? : ");
	scanf("%s",wanted);
	
	fp1 = fopen(PRODUCT_FILE, "r");
	fp2 = fopen(STOCK_FILE, "r");
	
	i = 0;
	fgets(str, 100, fp1);
	fgets(str, 100, fp2);
	while (fscanf(fp1,"%d,%*c,%*[^,],%[^,],%lf,",&pID,brand,&price) == 3){
		if (!find_feature(brand, wanted)){
			while (fscanf(fp2,"%*d,%d,%*[^,],%d", &pID_stock, &current_stock) == 2){
				if (pID == pID_stock){
					information[0][i] = pID;
					information[1][i] = price;
					information[2][i] = current_stock;
					i++; 
				}
			}
			rewind(fp2);
			fgets(str, 100, fp2);
		}
		fgets(str, 100, fp1);
	}
	printf("pID   |  Price  |  Current Stock\n");
	for (pID = 0;pID < i; pID++){
		printf("%.1lf  |  ",information[0][pID]);
		printf("%.1lf  |  ",information[1][pID]);
		printf("%.1lf\n",information[2][pID]);
	}
	
	fclose(fp1);
	fclose(fp2);
	return (i);
}

//part 2 take information array and its size 
void part6_stock_report(double information[][100], int size){
	FILE *fp;
	int i, j, min, max, median;
	double same;
	int index[size], find_values[15];
	
	int ctr;
	
	sort_array(information[0],index,size);
	fp = fopen(REPORT_FILE, "w");
	fprintf(fp,"pID,Minimumnumber,Maximumnumber,Mediannumber\n");
	
	same = information[0][index[0]];
	j = 0;
	for(i = 0; i < size; i++){
		if (same == information[0][index[i]]){
			find_values[j] = (int) information[2][index[i]];
			j++;
		}
		else{
			insertionSort(find_values,j);
			if (j % 2 == 0)
				median = (find_values[j/2] + find_values[j /2+1])/2.0 ;
			else
				median = find_values[j /2];
			fprintf(fp,"%d,%d,%d,%d\n",(int) same,find_values[0],find_values[j - 1],median);
			same = information[0][index[i]];
			find_values[0] = (int) information[2][index[i]];
			j = 1;
		}
		insertionSort(find_values,j);
		if (j % 2 == 0)
			median = (find_values[j/2] + find_values[j /2+1])/2.0 ;
		else
			median = find_values[j /2];
		fprintf(fp,"%d,%d,%d,%d\n",(int) same,find_values[0],find_values[j - 1],median);
		
	}
	
	fclose(fp);
}
