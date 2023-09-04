#include <stdio.h>
#include <stdlib.h>
/*to use exit I include stdlib.h
I coded it in 2 separate files because in pdf the program is wanted.
*/
int main(){
	int row,i;
	
	//Opening a file by using the function fopen() and store the reference of the file in a FILE pointer(fptr).
	FILE *fptr = fopen("example.txt", "r");
	
	//if file not found, exit the program unsuccessfully
    if (fptr == NULL) {
        printf("File not found.\n");
        exit(1);
    }
	
	//fscanf() function is used to read formatted input from a file.
	fscanf(fptr,"%d",&row);
	
	//as it is wanted,4 seperate array for program
	int ages[row];
	char occupations[row];
	float salaries[row];
	char fteams[row];
	
	//reading line by line and printing the character in arrays
	for (i = 0; i < row; i++)
		fscanf(fptr, "%d %c %f %c", &ages[i], &occupations[i], &salaries[i], &fteams[i]);
	
	//File close the file using the function fclose().
	fclose(fptr);
	
	/*
	char team for team
	float total for total salaries of persons
	flag for handling whether there is any fan of the team 
	fan_ctr is for calculating avarage salaries
	*/
	char team;
	float total;
	int flag,fan_ctr;
	
	//ask the user to selecta team
	printf("Please select a team: ");
	scanf(" %c", &team);
	
	//initialization
	total = 0;
	fan_ctr = 0;
	flag = 0;
	//if the person is fan of this team,
	//change flag by 1 and append him salary to total and increment fan_ctr
	for (i = 0; i < row; i++){
		if (fteams[i] == team) {
			flag = 1;
			total += salaries[i];
			fan_ctr++;
		}
	}
	
	//there is any fan of the team print average salaries else print there is no fan of the team
	if (flag)
		printf("Average salaries of fans of %c: %.1f\n", team, total / fan_ctr);
	else
		printf("There are no fans of %c in the database!\n", team);
		
	return (0);
}
