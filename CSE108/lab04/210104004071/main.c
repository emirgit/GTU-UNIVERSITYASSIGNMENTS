#include<stdio.h>

void write_seq_to_txt(void);
void draw_triang(int side);
void draw_square(int side);
void draw_byreading(void);

int main(){
	
	int choice;
	
	do {
	//do while kullanma nededim en az 1 kere menü gözükeceği içindi.		
	printf("Welcome to Shape Reader! Please make your choice to continue:\n");
	printf("1-) Generate a shape file\n");
	printf("2-) Read and draw a shape file\n");
	printf("3-) Terminate the program\n");
	//hangi seçenekten başlayacağını alıyor
	printf("Enter your choice:");
	scanf("%d",&choice);
	//switch ile yapmayı tercih ettim 2 sinide kullandım
	switch (choice) {
		//1 . casede 0 dan oluştur
		case 1:
        	write_seq_to_txt();
        	break;
		//2. casede olan bir textin üzerinden işlem yap
        case 2:
        	draw_byreading();
            break;
		//3 te sonlandır
    	case 3:
            printf("Program is terminated!\n");
            break;
		//geçersiz işlem varsa bastır
        default:
            printf("Invalid choice!\n");
        }
	} while (choice != 3);
	/*
	int least1;
	least1 = 1;

	while (least1 || choice != 3)

	bu şekild en az bir kere yapılabilir
	ancak do while kullanmak daha uygun oldu

	
	*/
	
	return (0);
}

void write_seq_to_txt(void){
	//file pointerı dosya yazma için
	FILE* fp;
    char shape;
    int size;
    
	//0 dan oluşturacağımız için owerrite yaptım
    fp = fopen("shapes.txt", "w");
    printf("Enter shape type and size immidiately i.e s3 (to exit print e for first character)\n");
    while (1){
    	//shape e olana kadar sürekli girecek
		//shape ve sizeı alacak
        scanf(" %c %d", &shape, &size);
        
        if (shape != 'e') {
			//, lü şekilde bastıracak
			if (!(size >=3 && size <= 10)){
				continue;
			}
            if (shape == 's'){
            	fprintf(fp, "s,%d\n", size);
        	}
			else if (shape == 't'){
            	fprintf(fp, "t,%d\n", size);
        	} 
			else{
            	printf("Invalid shape \n");
        	}
        }
        else{
        	break;
		}
	}
	//close file process	
	fclose(fp);
	//once created new file,draw immiditaly
	printf("Read and draw option is activated instantly\n");
	draw_byreading();
}

void draw_triang(int side){
	int i,j;
	
	for (i = 1;i <= side; i++){
		for (j = 1;j <= 2*side-1;j++){
			if ((i + j == side + 1) || (i - j == 1 - side ) || (i == side)){
				printf("*");
			}
			else{
				printf(" ");
			}
			
		}
		printf("\n");
	}
}

void draw_square(int side){
    int i, j;
    
    for (i = 1; i <= side; i++) {
        for (j = 1; j <= side; j++) {
            if (i == 1 || i == side || j == 1 || j == side) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void draw_byreading(void){
	FILE* fp;
	int c;
    char shape;
    int side;
	
	fp = fopen("shapes.txt", "r");
	
	while ((c = fgetc(fp)) != EOF) {
		if (c == ','){
			fscanf(fp , "%d",&side);
		
			if (shape == 's'){
				draw_square(side);
			}
			else if (shape == 't'){
				draw_triang(side);
			}
			while ((c = fgetc(fp)) != '\n' && c != EOF);
		}
		else{
			shape = c;
		}
	}

	
	fclose(fp);
}
