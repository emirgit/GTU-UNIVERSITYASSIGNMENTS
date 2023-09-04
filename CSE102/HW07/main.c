#include"util.h"

int main(int argc, char *argv[]){
    //constant file names
    const char *filename = "dictionary.txt";
    const char *text_file = "input.txt";
    const char *ignore_file = "ignore.txt";
    //adding + 1 because of senitel value
    const int numberofword = read_first_line(filename) + 1;

    //if number of word is -1,the file not found .end up main function
    if (numberofword != -1){
        //dict
        char dict[numberofword][MAX_WORD_SIZE];
        //words of text_file
        char words[MAX_WORD_LIMIT + 1][MAX_WORD_SIZE];
        //input array and str that allow us to determine words of input
        char input[MAX_WORD_SIZE * 100];
        /*
        i and j is element of an loop
        frequency is the frequency of word in determined text file
        input_word word number of input
        word_counter of also element of an array to fill and print
        */
        int i, j, frequency, input_word, word_counter, allignment;
        // option is double value of found cloest of a word
        double option;
        //fill dict array
        read_dict(filename, dict);
        //fill words array
        read_text(text_file, ignore_file, words);

        printf("Enter word(s): ");
        /*
        taking line from user
        it can print 100 word
        so it must be maximum 1300 (" " character included)
        from stdin
        and place it in input
        */
        fgets(input , MAX_WORD_SIZE * 100, stdin);
        //string word counter return the word number of input
        input_word = stringwordcount(input);

        /*
        input_words will store the inputted word
        for sentiel value the values number is input_word + 1
        2 * MAX_WORD_SIZE because its closest word included
        
        occurences will store the frequency a word
        
        hist will be used for drawing histogram
        it is also input_word + 1
        */
        char input_words[input_word + 1][2 * MAX_WORD_SIZE];
        int occurences[input_word + 1];
        char hist[input_word + 1][2 * MAX_WORD_SIZE + 5 + 20];
        
        //continue until all inputted try
        i = 0;
        for (word_counter= 0; input[i] != '\0'; word_counter++){

            //filling inputted word by splitting them (like strtok)
            i = fill_arr(input, input_words[word_counter], i);
            //frequency will be stored in frequency by using find_frequency function
            frequency = find_frequency(words, input_words[word_counter]);
            //if frequency is not zero store it
            if (frequency != 0){
                occurences[word_counter] = frequency;
            }
            else {
                //else try to find the closest word
                for (j = 0; dict[j][0] != '-'; j++){
                    /*
                    you can change threshold 0.020-0.039
                    dissimilarity will be find the first closest word that reach the threshold
                    if it is found it will return the value of close
                    it means option < 1 && option > 0
                    */
                    option = dissimilarity(input_words[word_counter], dict[j], dict, 0.034, filename);
                    
                    /*
                    Don't forget to change threshold to get different result 
                    !!!!!ATTENTİON!!!!!
                    My algorithm support to find closest word that pass the threshold
                    but also it can be converted to find closest word and after check threshold
                    
                    you can copy rest of code in for (j = 0; dict[j][0] != '-'; j++ to out of it
                    
                    and append this algorith 
                    
                    (define variables upper)
                    
                    if (option > max)
                    	max = option
                    and change option as max
                    
                    this is basic functionality that findind maximum values that means closest word
                    and decide the judgement for the result
                    
                    I undestand this from pdf and Zehra teacher allow me to do like this
                    
                    Thanks for your attention
                    
                    */
                    
                    if (option < 1 && option > 0){
                        //if the c losest found try to find its frequench 
                        occurences[word_counter] = find_frequency(words, dict[j]);
                        //if the frequency different from 0 show it by adding closest word like this ("car->student")
                        //and break it because we found the closest word that pass threshold
                        //else continue to try to find it
                        if (occurences[word_counter] != 0)
                        {
                            f_strcat(input_words[word_counter],"->");
                            f_strcat(input_words[word_counter],dict[j]);
                            break;
                        }
                    }
                    // if option == 2 it means the vector of first word not found
                    // the closest word cannot be found
                    // sential value of occurences is -1
                    else if (option == 2){
                        occurences[word_counter] = -1;
                        break;
                    }
                }
                //if option is 0 there is no word that provide threshold also send it as -1
                if (option == 0){
                    occurences[word_counter] = -1;
                }
            }
        }
        //provide array end up sential value input_words '-'        occurences -100
        input_words[word_counter][0] = '-';
        occurences[word_counter] = -100;
        
        //if inputted word number is greater than zero print historgram else print it basically
        if (input_word != 1){
            //calling histogram and print it scale
            //and print hist array that filled up in histogram function
            printf("Scale : %d\n",histogram(input_words, occurences, hist));
            for (i = 0; hist[i][0] != '-'; i++){
                for (j = 0; hist[i][j] != ' '; j++){
                    printf("%c",hist[i][j]);
                }
                // 30 is 2 * MAX_WORD_SIZE + 4
                allignment = 30 - j;
                while (allignment > 0){
                    printf(" ");
                    allignment--;
                }
                printf("%s\n",&hist[i][j + 1]);
            }
        }
        else{
            //print it as wanted way
            switch (occurences[0])
            {
            case 0:
            case -1:
                printf("“%s” doesn’t appear in “%s”.\n", input_words[0], text_file);
                break;
            default:
                printf("“%s” appears in “%s” %d times.\n", input_words[0], text_file, occurences[0]);
            }
        }
        
        
    }

    return (0);
}
