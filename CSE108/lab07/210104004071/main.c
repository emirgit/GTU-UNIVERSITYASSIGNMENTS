#include<stdio.h>
#include<string.h>

int part1(char str[]);
void part2(void);
void part3(void);
void foo_min_max(int arr[], int n);

int main(){
	char str[200];
    printf("Enter a string: ");
    scanf("%s", str);
	printf ("%d",part1(str));
	part2();
	part3();	
	
	
	return (0);
}

int part1(char s[]){
    int n = strlen(s);
    int i = 0, count = 0, res = 0;
    while (i < n) {
        count = 0;
        while (i + count < n && s[i] == s[i + count]) {
            count++;
        }
        res += count / 3;
        i += count;
    }
    return res;
}

/*
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (str + i);
		i++;
		j = 0;
	}
	return (0);
}
*/

void filter(char *s, char* rule){
	int i, j, match;
	
	
	if (rule[0] == '\0')
		printf("%s",s);
	char *token = strtok(s, " ");
	while (token != NULL) {

		i = 0;
		j = 0;
		match = 0;
		while (token[i] != '\0')
		{
			while (token[i + j] == rule[j] && token[i + j] != '\0')
				j++;
			if (rule[j] == '*'){
				if (strstr(&token[i + j],&rule[j + 1]))
					match = 1;
			}
			else if (rule[j] == '?'){
				if (strstr(&token[i + j],&rule[j + 1]))
					match = 1;
			}
			else if (rule[j] == '\0'){
				match = 1;
			}
			i++;
			j = 0;
		}
		if (!match)
			printf("%s ",token);
		token = strtok(NULL, " ");
	}
	printf("\n");
}

void part2(void){
    char s[] = "As a noble person, I want to solve this novel problem on my own.";
    char rule[] = "o*e";
    filter(s, rule);
    char s2[] = "As a noble person, I want to solve this novel problem on my own.";
    char rule2[] = "no?el";
    filter(s2, rule2);
}

void foo_min_max(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];
    
    int i = 1;
    while (i < n){
        if (arr[i] < min) 
			min = arr[i];
        if (arr[i] > max) 
			max = arr[i];
			
		i++;
    }
    
    printf("Minimum: %d\nMaximum: %d\n", min, max);
}

void part3(void){
	int arr[100];
    int n;
    
    printf("Enter the number of items in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    foo_min_max(arr, n);
}
