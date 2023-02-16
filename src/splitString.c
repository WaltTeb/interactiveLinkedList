#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int maxSize = 60;
    char *str = (char *) malloc(maxSize);
    printf("Enter items (seperated by , ): ");
    fgets(str, maxSize, stdin); //get user string from terminal
    
    //count the number of words the user entered
    int k = 0;
    int numWords = 0;
    while(*(str+k) != '\n'){
        if(*(str+k) == ','){
            numWords++;
        }
        
        k++;
    }
    numWords++;

    char *words[numWords]; //create array of pointers to store words in
    
    int i;
    int j = 0;
    for(i=0; i<numWords; i++){

        int h = 0;
        char *tempStr = (char *) malloc(maxSize);
        while(*(str+j) != ',' && *(str+j) != '\n'){
            sprintf(tempStr+h, "%c", *(str+j));
            h++;
            j++;
        }
        j+=2;
        
        sprintf(tempStr+h+1, "\0");
        printf("tempstr = %s\n", tempStr);
        words[i] = tempStr;
        
        
    }


    //iterates through the words list and prints each
    i=0;
    for(i; i<numWords; i++){
        printf("words[%d] = %s\n", i, words[i]);
        free(words[i]);
    }
    
    
    free(str);
    return 0;
}
