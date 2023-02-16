#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxSize = 20;
int main(){
    char *input = (char *) malloc(maxSize);
    printf("Enter string: ");
    fgets(input, maxSize, stdin);
    printf("Your string is: %s\n", input);
    
    int arrayStringSize = maxSize + maxSize + 1;
    char *str = (char *) malloc(arrayStringSize);
    sprintf(str+0, "[");
    
    int k = 1;
    int j = 0;
    while(*(input+j) != '\n' && *(input+j) != '\0'){
        sprintf(str+k, "%c,", *(input+j));
        k = k+2;
        j++;
    }
    sprintf((str+k)-1, "]");
    printf("str = %s\n", str);

    free(str);
    free(input);
    return 0;
}