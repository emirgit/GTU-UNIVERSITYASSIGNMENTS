#include "util.h"

void fillLinkedList(struct Node** head) {
	/*
	Since there are 2 strings in the third, 
	I created random arrays that are sentences and words.
	*/
	
	char sentence[25][50] = {
	"I am Emir",
	"The sun sets in the west",
	"John enjoys running daily",
	"Dogs are loyal animals",
	"She sings beautifully",
	"Snowflakes fall gently",
	"The food tastes amazing",
	"Paris is the city of love",
	"Rain makes the grass greener",
	"Coffee keeps me awake",
	"Music soothes the soul",
	"I love reading books",
	"The pie is very tasty",
	"London is a vibrant city",
	"His painting is creative",
	"Math puzzles are challenging",
	"Nature is incredibly beautiful",
	"Traveling expands your horizon",
	"Education is vital for all",
	"I enjoy morning jogs",
	"Life is full of surprises",
	"Photography is his hobby",
	"Cooking is therapeutic for her",
	"I appreciate your help",
	"Dreams can become reality"
	};
	
	int i, asset_num, asset_type;
	Asset1* asset1;
	Asset2* asset2;
	Asset3* asset3;
	Asset4* asset4;
	Node* new_node;
	
    srand(time(NULL));
    asset_num = (rand() % 11) + 10;  
    printf("Generating Linked list with %d asset\n",asset_num);
    
    for(i = 0; i < asset_num; i++){
        new_node = (Node*)malloc(sizeof(Node));
        asset_type = (rand() % 4) + 1; 
        
        switch(asset_type){
            case 1:
            	
                asset1 = (Asset1*)malloc(sizeof(Asset1));

                strcpy(asset1->type, "Asset1");
                asset1->ivals[0] = rand() % 147483647;
                asset1->svals[0] = rand() / (double)RAND_MAX;

                new_node->data = asset1;
                break;
                
            case 2:
            	
                asset2 = (Asset2*)malloc(sizeof(Asset2));

                strcpy(asset2->type, "Asset2");
                asset2->ivals[0] = rand() % 147483647;
                asset2->ivals[1] = rand() % 147483647;
                asset2->svals[0] = rand() / (double)RAND_MAX;
                asset2->svals[1] = rand() / (double)RAND_MAX;

                new_node->data = asset2;
                
                break;
            case 3:
            	
                asset3 = (Asset3*)malloc(sizeof(Asset3));

                strcpy(asset3->type, "Asset3");
                random_word(asset3->string1, sentence);
                random_word(asset3->string2, sentence);

                new_node->data = asset3;
                
                break;
            case 4:
            	
                asset4 = (Asset4*)malloc(sizeof(Asset4));

                strcpy(asset4->type, "Asset4");
                asset4->value1 = rand() / (double)RAND_MAX;
                asset4->value2 = rand() / (float)RAND_MAX;
                asset4->value3 = rand() / (double)RAND_MAX;

                new_node->data = asset4;
                
                break;
        }
        
        new_node->next = *head;
        *head = new_node;
    }
}

/*
print_linked_list function prints the linked list
the head pointer is local parameter after passing it to function
Thus, I used directly head (and I don't modify the rest of the pointer)
I print the linked list it is not problem for using head pointer directl
*/
void print_linked_list(Node* head) {
	/*
	asset instance to detect the asset type
    I will use this for ease 
    it will be like this
    asset1 = (Asset1*)head->data;
    because data is void pointer I need to type cast
    */
	Asset1* asset1;
    Asset2* asset2;
    Asset3* asset3;
    Asset4* asset4;

	printf("\n\nThe Linked List is printing...\n");
    while(head != NULL){
    	/*
		there is 4 condition for type .Thus, I used if else if ..
    	(type casting)head->data
        if strcmp gives 0, we wind the the asset 
        */
		if(strcmp(((Asset1*)head->data)->type, "Asset1") == 0){
			
            asset1 = (Asset1*)head->data;
            printf("Type: %s\t", asset1->type);
            printf("ivals[0]: %d\t", asset1->ivals[0]);
            printf("svals[0]: %f\t", asset1->svals[0]);
            
        }
        else if(strcmp(((Asset2*)head->data)->type, "Asset2") == 0){
        	
            asset2 = (Asset2*)head->data;
            printf("Type: %s\t", asset2->type);
            printf("ivals[0]: %d\t", asset2->ivals[0]);
            printf("ivals[1]: %d\t", asset2->ivals[1]);
            printf("svals[0]: %f\t", asset2->svals[0]);
            printf("svals[1]: %f\t", asset2->svals[1]);
            
        }
        else if(strcmp(((Asset3*)head->data)->type, "Asset3") == 0){
        	
            asset3 = (Asset3*)head->data;
            printf("Type: %s\t", asset3->type);
            printf("string1: %s\t", asset3->string1);
            printf("string2: %s\t", asset3->string2);
            
        }
        else if(strcmp(((Asset4*)head->data)->type, "Asset4") == 0){
        	
            asset4 = (Asset4*)head->data;
            printf("Type: %s\t", asset4->type);
            printf("value1: %f\t", asset4->value1);
            printf("value2: %f\t", asset4->value2);
            printf("value3: %f\t", asset4->value3);
            
        }
        printf("\n");
        //goes throughout until the end of the linked list
		head = head->next;
    }
}

void random_word(char *string, char sentence[25][50]){
	int index;
	
	index = rand() % 25;
	
	strcpy(string, sentence[index]);
}

void serializeLinkedList(struct Node* head) {
    FILE* fp;
    /*
	asset instance to detect the asset type
    I will use this for ease 
    it will be like this
    asset1 = (Asset1*)head->data;
    because data is void pointer I need to type cast
    */
    Asset1* asset1;
    Asset2* asset2;
    Asset3* asset3;
    Asset4* asset4;

    //openning the binary file to print the datas of the struct(assets) 
    //binary file has special mode "wb" to write binary file
    fp = fopen("linkedlist.bin", "wb");

    if (fp == NULL) {
        printf("Error! Unable to open file.\n");
        return;
    }

    printf("Serializing the Linked Listt..\n");
    while (head != NULL){
        /*
		there is 4 condition for type. Thus, I used if else if ..
    	(type casting)head->data
        if strcmp gives 0, we find the the asset 
        */

        if (strcmp(((Asset1*)head->data)->type, "Asset1") == 0) {

            asset1 = (Asset1*)head->data;
            fwrite(asset1->type, sizeof(asset1->type), 1, fp);
            fwrite(asset1, sizeof(Asset1), 1, fp);

        } 
        else if (strcmp(((Asset2*)head->data)->type, "Asset2") == 0){

            asset2 = (Asset2*)head->data;
            fwrite(asset2->type, sizeof(asset2->type), 1, fp);
            fwrite(asset2, sizeof(Asset2), 1, fp);

        } 
        else if (strcmp(((Asset3*)head->data)->type, "Asset3") == 0){

            asset3 = (Asset3*)head->data;
            fwrite(asset3->type, sizeof(asset3->type), 1, fp);
            fwrite(asset3, sizeof(Asset3), 1, fp);

        } 
        else if (strcmp(((Asset4*)head->data)->type, "Asset4") == 0){

            asset4 = (Asset4*)head->data;
            fwrite(asset4->type, sizeof(asset4->type), 1, fp);
            fwrite(asset4, sizeof(Asset4), 1, fp);

        }

        head = head->next;
    }

    fclose(fp);
}
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
if you are sure of your place or you want to read the file struct by struct
you can use this

void serializeLinkedList(struct Node* head) {
    FILE* fp;
    
	asset instance to detect the asset type
    I will use this for ease 
    it will be like this
    asset1 = (Asset1*)head->data;
    because data is void pointer I need to type cast
    
    Asset1* asset1;
    Asset2* asset2;
    Asset3* asset3;
    Asset4* asset4;

    //openning the binary file to print the datas of the struct(assets) 
    //binary file has special mode "wb" to write binary file
    fp = fopen("linkedlist.bin", "wb");

    if (fp == NULL) {
        printf("Error! Unable to open file.\n");
        return;
    }


    while (head != NULL){
        
		there is 4 condition for type. Thus, I used if else if ..
    	(type casting)head->data
        if strcmp gives 0, we find the the asset 
        

        if (strcmp(((Asset1*)head->data)->type, "Asset1") == 0) {

            asset1 = (Asset1*)head->data;
            fwrite(asset1, sizeof(Asset1), 1, fp);

        } 
        else if (strcmp(((Asset2*)head->data)->type, "Asset2") == 0){

            asset2 = (Asset2*)head->data;
            fwrite(asset2, sizeof(Asset2), 1, fp);

        } 
        else if (strcmp(((Asset3*)head->data)->type, "Asset3") == 0){

            asset3 = (Asset3*)head->data;
            fwrite(asset3, sizeof(Asset3), 1, fp);

        } 
        else if (strcmp(((Asset4*)head->data)->type, "Asset4") == 0){

            asset4 = (Asset4*)head->data;
            fwrite(asset4, sizeof(Asset4), 1, fp);

        }

        head = head->next;
    }

    fclose(fp);
}
*/

void deserializeLinkedList(struct Node** head) {
    FILE* fp; 
    /*
	asset instance to detect the asset type
    I will use this for ease 
    it will be like this
    asset1 = (Asset1*)head->data;
    because data is void pointer I need to type cast
    */
    Asset1* asset1;
    Asset2* asset2;
    Asset3* asset3;
    Asset4* asset4;
    //asset type to detect the type of asset
    char asset_type[20];
    
    /*
    openning the binary file to read the datas of the struct(assets) 
    binary file has special mode "rb" to read binary file
    */
    fp = fopen("linkedlist.bin", "rb");
    
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }
    /*
    current will be used to add node to linked list
    new_node will be used to add node 
    the node that will be added is new_node
    */
    Node* current = NULL;
    Node* new_node;

    printf("Reconstructing the Linked List..");
    while (1) {

        /*
        fread returns the total numbef of elements succeessfully returned
        it needs to read 1 elements so if it is not 1 break
        !fread(assetType, sizeof(assetType), 1, file) also okay
        but This way, if I want to use the code in the future, I can understand it more easily.
        */
        if (fread(asset_type, sizeof(asset_type), 1, fp) != 1)
            break;
        //filling new node
        new_node = (Node*)malloc(sizeof(struct Node));
        new_node->next = NULL;

        /*
        trying to find correct asset_type
        after it is found,
        read the rest of struct 
        if it can be read sucsesfully , the list will point the asset
        else free asset and new_node
        */
        if (strcmp(asset_type, "Asset1") == 0) {

            asset1 = (Asset1*)malloc(sizeof(Asset1));
            if (fread(asset1, sizeof(Asset1), 1, fp) != 1) {
                free(asset1);
                free(new_node);
                break;
            }

            new_node->data = asset1;
        } 
        else if (strcmp(asset_type, "Asset2") == 0) {

            asset2 = (Asset2*)malloc(sizeof(Asset2));
            if (fread(asset2, sizeof(Asset2), 1, fp) != 1) {
                free(asset2);
                free(new_node);
                break;
            }

            new_node->data = asset2;
        }
        else if (strcmp(asset_type, "Asset3") == 0) {

            asset3 = (Asset3*)malloc(sizeof(Asset3));
            if (fread(asset3, sizeof(Asset3), 1, fp) != 1) {
                free(asset3);
                free(new_node);
                break;
            }

            new_node->data = asset3;
        } 
        else if (strcmp(asset_type, "Asset4") == 0) {

            asset4 = (Asset4*)malloc(sizeof(Asset4));
            if (fread(asset4, sizeof(Asset4), 1, fp) != 1) {
                free(asset4);
                free(new_node);
                break;
            }

            new_node->data = asset4;
        } 
        else {
            free(new_node);
            break;
        }

        /*
        adding it to linked list
        if head pointer is null
        */
        if (*head == NULL) {
            *head = new_node;
            current = new_node;
        } 
        else{
            current->next = new_node;
            current = current->next;
        }
    }

    fclose(fp);
}

/*
If you are sure the place of type 
you can add fseek and You can use above

but If you want to read struct by struct you can use this

I didn't check this function ı write it just as idea
void deserializeLinkedList(struct Node** head) {
    FILE* fp; 
    
	asset instance to detect the asset type
    I will use this for ease 
    it will be like this
    asset1 = (Asset1*)head->data;
    because data is void pointer I need to type cast
    
    Asset1* asset1;
    Asset2* asset2;
    Asset3* asset3;
    Asset4* asset4;
    //asset type to detect the type of asset

    
    
    openning the binary file to read the datas of the struct(assets) 
    binary file has special mode "rb" to read binary file
    
    fp = fopen("linkedlist.bin", "rb");
    
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }
    
    current will be used to add node to linked list
    new_node will be used to add node 
    the node that will be added is new_node
    
    Node* current = NULL;
    Node* new_node;

    while (1) {
        
        asset1 = (Asset1*)malloc(sizeof(Asset1));
        
        if (fread(asset1, sizeof(asset1), 1, fp) != 1){
            free(asset1);
            break;
        }

        //filling new node
        new_node = (Node*)malloc(sizeof(struct Node));
        new_node->next = NULL;

        
        if (strcmp(asset1->type, "Asset1") == 0) }
            new_node->data = asset1;
        } 
        else {
            free(asset1);
            fseek(fp, -sizeof(Asset1), SEEK_CUR);

            asset2 = (Asset2*)malloc(sizeof(Asset2));
            
            if (fread(asset2, sizeof(Asset2), 1, fp) != 1){
                free(asset2);    
                free(new_node);
                break;
            }

            if (strcmp(asset_type, "Asset2") == 0) {
                new_node->data = asset2;
            }
            else {
                free(asset2);
                fseek(fp, -sizeof(Asset2), SEEK_CUR);
                asset3 = (Asset3*)malloc(sizeof(Asset3));
                if (fread(asset3, sizeof(Asset3), 1, fp) != 1) {
                    free(asset3);
                    free(new_node);
                    break;
                }
                if (strcmp(asset_type, "Asset3") == 0) {
                    new_node->data = asset3;
                }
                else {
                    free(asset3);
                    fseek(fp, -sizeof(Asset3), SEEK_CUR);
                    asset4 = (Asset4*)malloc(sizeof(Asset4));
                    if (fread(asset4, sizeof(Asset4), 1, fp) != 1) {
                        free(asset4);
                        free(new_node);
                        break;
                    }
                    if (strcmp(asset_type, "Asset4") == 0) {
                        new_node->data = asset4;
                    }

                }
            }

        }

        
        if (*head == NULL) {
            *head = new_node;
            current = new_node;
        } 
        else{
            current->next = new_node;
            current = current->next;
        }
    }

    fclose(fp);
}

*/




void free_linked_list(Node* head){
    Node* current;

    while (head != NULL) {
        current = head;
        head = head->next;

        free(current->data);
        free(current);
    }
}
