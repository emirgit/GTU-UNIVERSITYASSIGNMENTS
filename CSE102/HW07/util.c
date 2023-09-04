#include "util.h"

int find_frequency(const char words[][MAX_WORD_SIZE],char *str){
    int j, frequency;

    //finding frequency by trying all words by using strcmp in string.h
    frequency = 0;
    for (j = 0; words[j][0] != '-'; j++){
        if (!strcmp(words[j],str))
            frequency++;
    }

    return (frequency);
}



int pass_word(char *str){
    int i;
    //passing word of it
    for (i = 0; isnot_spacechar(str[i]) && str[i] != '\0'; i++);
    
    //passing space until see vector
    while(!isnot_spacechar(str[i]) && str[i] != '\0'){
        i++;
    }
    //if it counter index
    if (str[i] == '\0')
        return (i - 1);

    return (i);
}

void f_strcat(char *dest, const char *source){
    int i,j;
    //str cat is appending the word 
    i = f_strlen(dest);
    //taking its length and start from there and overwrite it
    for (j = 0; source[j] != '\0'; j++){
        dest[i] = source[j];
        i++;
    }
    dest[i] = '\0';
}


int fill_arr(const char *word, char * str, int index){
    
    int i = 0;
    //printing alphabetic word
    while (isnot_spacechar(word[index]) && word[index] != '\0'){
        str[i] = word[index];
        i++;
        index++;
    }
    //null terminated
    str[i] = '\0';
    //passing the space character
    while (!isnot_spacechar(word[index]) && word[index] != '\0'){
        index++;
    }
    //return index
    return (index);
}

int found_closest(const char *word){
    int i;
    //if we append closest (that's mean we find it),it includes - .Find it
    i = 0;
    while (word[i] != '\0'){
        if (word[i] == '-')
            return (1);
        i++;
    }

    return (0);
}

//basicaly string word counter (all words includes " "(ASCII 32))
int stringwordcount(char *s){
    int i,words=0;
	for(i=0;s[i];i++){
    	if(s[i]==32)
    	 words++;
 
 	}
 	if(i>0)
      words++;
	  
	return words; 	
}

/*
reading and file
the vector size after second '=' character
passing first and second '=' character
and converting this letter to normally number
*/
int read_vector_size(const char *file_name){
    FILE *fp;
    char ch;
    int vector_size = 0;

    fp = fopen(file_name, "r");

    if (fp == NULL){
        return (-1);
    }

    //passing "number_words" words
    while ((ch = fgetc(fp)) != '=');
    ch = fgetc(fp);
    while ((ch = fgetc(fp)) != '=');

    //calculating number until see ',' character
    while (isnot_spacechar((ch = fgetc(fp)))){

		vector_size *= 10;
		vector_size += ch - 48;
	}

    fclose(fp);
    return (vector_size);
}

/*
copying the string to another
and null terminated it
*/
void f_strcp(char *dest, const char *source){
    int i;

    i = 0;
    while (source[i] != '\0'){
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
}

/*
the space characters is
Vertical tab 
Horizontal tab
new line
carriage return
normal space
form feed
they are in interval [9-13] except space
it is in 32
*/
int isnot_spacechar(int ch){

    if ((ch >= 9 && ch <= 13) || ch == 32)
        return 0;
    
    return 1;
}

/*
find  whether the character is alphabetic or not by ASCII
*/
int is_alphabetic(int ch){

    	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            return (1);
		return (0);
}
/*
pass ignored word
I used static because ı want to call function faster
I sacrifice some ram area in but it worth
because ı will read the ignored file just 1 
by using static counter and static ignored array
*/
int is_an_ignored(char const * ignore_file,char const * str){
    static char ignored[MAX_WORD_COUNT][MAX_WORD_SIZE];
    static int counter = 0;
    int i;
    if (counter == 0){
        FILE *fp;
        int wordcounter = 0;
        char word[MAX_WORD_SIZE];

        fp = fopen(ignore_file,"r");
        if (fp == NULL){
            printf("ignored file not found\n");
            return (-1);
        }
        /*
        read the wrords in ignored file
        and copy it ignored array
        */
        while (fscanf(fp,"%s", word) != EOF){
            f_strcp(ignored[wordcounter],word);
            wordcounter++;
        }
        /*
        sentiel end
        */
        ignored[wordcounter][0] = '-';
        fclose(fp);
        counter++;
    }
    /*
    after just created it once
    use it with strcmp
    */
    for (i = 0;ignored[i][0] != '-';i++){
        if (strcmp(ignored[i],str) == 0)
            return (1);
    }
    return (0);
}

int read_first_line(const char * file_name){
    FILE *fp;
    char ch;
    int number_words = 0;

    fp = fopen(file_name, "r");

    if (fp == NULL){
        return (-1);
    }

    //passing "number_words" words
    while ((ch = fgetc(fp)) != '=');

 
    //calculating number until see ',' character
    while ((ch = fgetc(fp)) != ','){

		number_words *= 10;
		number_words += ch - 48;
	}

    fclose(fp);
    return (number_words);
}

/*
reading dict
*/
int read_dict(const char * file_name, char dict[][MAX_WORD_SIZE]){
    FILE *fp;
    int vector_size = read_vector_size(file_name);
    char str[(MAX_VECTOR_DIGIT * vector_size) + MAX_WORD_SIZE];
    int i,counter = 0;

    fp = fopen(file_name, "r");

    if (fp == NULL){
        return (-1);
    }
    //passing first line before
    fgets (str, 50, fp);
    /*
    I determine it changeable to gain some ram area
    because Vector digit and vector size is changeablee
    */
	while (fgets (str, (MAX_VECTOR_DIGIT * vector_size) + MAX_WORD_SIZE, fp)){
		i = 0;
        //append it as long as it is not space character
		while (isnot_spacechar(str[i]))
		{
            dict[counter][i] = str[i];
			i++;
		}
        // null terminate
        dict[counter][i] = '\0';
        counter++;
	}
    //sentiel terminated
    dict[counter][0] = '-';

    fclose(fp);
    return (counter);
}

//basically strlen function
int f_strlen(char *str){
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;

    return (i);
}

//read_text function 
int  read_text(const char  * text_file, const char  * ignore_file, char words[][MAX_WORD_SIZE]){
    FILE *fp1;
    int counter = 0,i;
    char str[40],ch;
    
    fp1 = fopen(text_file, "r");
    if (fp1 == NULL)
        printf("Error");
    
    //taking first value for do while
    ch = fgetc(fp1);
    do {
        //if it is alphabetic copy it to str and pass next word
        for(i = 0;is_alphabetic(ch);i++){
            str[i] = ch;
            ch =fgetc(fp1);
        }
        str[i] = '\0';
        //null terminated

        //be sure it is not ignored and copy it words a rray
		if (!is_an_ignored(ignore_file, str)){
			f_strcp(words[counter],str);
            counter++;
        }
        //continue until it is not end of file or space character
        while (!feof(fp1) && !is_alphabetic(ch)){
            ch = fgetc(fp1);
        }
        // continue until it is not end of file
    }while (!feof(fp1));

    //sentinel terminated

    words[counter][0] = '-';
    fclose(fp1);
    return (counter);
}

double dissimilarity(char * w1, char * w2, char dict[][MAX_WORD_SIZE], float threshold, const char *file_name ){
    FILE *fp;
    const int vector_size = read_vector_size(file_name);
    char str[30],strw1[(MAX_VECTOR_DIGIT * vector_size) + MAX_WORD_SIZE],strw2[(MAX_VECTOR_DIGIT * vector_size) + MAX_WORD_SIZE];
    int i,counter,linew1,linew2;
    double v1,v2,res,result;

    fp = fopen(file_name, "r");

    if (fp == NULL){
        printf("dict file not found\n");
        return (0);
    }

    //to make it faster just find the line number of it (it started from 0)
    //before put it sentinel value to find it wherher it is in dictionary file or not
    linew1 = -1;
    linew2 = -1;
    counter = 0;
    //
    while (dict[counter][0] != '-'){
        if (!strcmp(dict[counter],w1))
            linew1 = counter;
        else if (!strcmp(dict[counter],w2))
        {
            linew2 = counter;
        }
        else if (linew1 != -1 && linew2 != -1){
            break;
        }

        counter++;
    }
    if (linew1 == -1){
        //2 means no matching(this words vector not found)
        return (2);
    }
    else if (linew2 == -1){
        return (0);
    }

    //passing first line
    fgets(strw1, MAX_VECTOR_DIGIT * vector_size,fp);

    //finding which one is before
    //and find which line it is in by reading the file
    //
    if (linew1 > linew2){
        counter = 0;
        while (fgets(strw1, MAX_VECTOR_DIGIT * vector_size,fp)){
            //linew1 greater than linew2 so when it find linew1 break it to make it faster
            if (linew1 == counter)
                break;
            else if (linew2 == counter)
                f_strcp(strw2,strw1);
            counter++;
        }
    }
    else {
        counter = 0;
        while (fgets(strw2, MAX_VECTOR_DIGIT * vector_size,fp)){
            if (linew2 == counter)
                break;
            else if (linew1 == counter)
                f_strcp(strw1,strw2);
            counter++;
        }
    }

    //passing firsts worst of them
    res = 0;   
    i = pass_word(strw1);
    counter = pass_word(strw2);
    //calculating all values of them until see their null terminated character
    while (strw1[i] != '\0' && strw2[counter] != '\0'){
        i = fill_arr(strw1, str, i);
        sscanf(str, "%lf", &v1);
        counter = fill_arr(strw2, str, counter);
        sscanf(str, "%lf", &v2);

        res += (v1 - v2) * (v1 - v2);
    }
    /*
    WARNING
    I did everything by Zehra hoca's rule
    most people in group take sqrt of it 
    but ı obey Zehra hoca
    */

    /*
    if ve substract same vector this will be 0
    if it is similar
    result will be small and when we divided 1 by res
    this wil be close 1 
    so 1 means close
    0 means different
    so it is pass the threshold return it
    */
    fclose(fp);
    result = 1 / res;
    //printf("  %lf  ", result);
    if (result >= threshold)
        return (result);
    
    return (0);
}

//histogram will filled up histogram array
int histogram(const char words[][2 * MAX_WORD_SIZE],const int occurrences[], char hist[][2 * MAX_WORD_SIZE+5+20]){
    /*
    i and j is loop element
    max_occur is a variable that will be stored the most frequency word of in txt
    scale will be determinted by scale = (max_occur / 20) + 1;
    str will be keep the '*' or '+' character
    */
    int i, j, max_occur, scale;
    char str[21];
    max_occur = 0;
    /*
    findt max occurence until sentiel value*/
    for (i = 0; occurrences[i] != -100; i++){
        if (max_occur < occurrences[i])
            max_occur = occurrences[i];
    }
    scale = (max_occur / 20) + 1;
    /*convert it this "pigling->student" ++++++++++*/
    for(i = 0; words[i][0] != '-';i++){
        f_strcp(hist[i],"\"");
        f_strcat(hist[i],words[i]);
        
        if (occurrences[i] != -1){

            f_strcat(hist[i],"\" ");
            if (found_closest(words[i])){
                for (j = 0; j < occurrences[i] / scale; j++){
                    str[j] = '+';
                }
            }
            else {
                for (j = 0; j < occurrences[i] / scale; j++){
                    str[j] = '*';
                }
            }
            str[j] = '\0';
            //if it is 0 by scale , print TOO FEW 
            if (j == 0)
                f_strcat(hist[i],"TOO FEW");
            else
                f_strcat(hist[i],str);
        }
        // else it is not matched vector not found or it is 0 
        else{
            f_strcat(hist[i],"\" NO MATCHES");
        }
    }

    hist[i][0] = '-';

    return (scale);
}