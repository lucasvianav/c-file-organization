#include <stdio.h>
#include <stdlib.h>

// csv columns: ID (null?) - NAME - AGE

int main(){
    // .csv filename string (expecting max 20 chars)
    char filename[20];

    // reads filename from stdin
    scanf("%s", filename);

    // opens the file in reading mode
    FILE *fp = fopen(filename, "r");

    // string in which all of the file's content will be stored
    // it's initial value is 1 byte because each char will be read
    // individually
    int contentSize = 0;
    char *content;

    char tmp;
    
    // loop to read each of the file's characters
    while(fread(&tmp, sizeof(char), 1, fp)){
        content = (char *)realloc(content, ++contentSize * sizeof(char));
        content[contentSize] = tmp;
        printf("%c", tmp);
    }

    // terminates the string
    content = (char *)realloc(content, ++contentSize * sizeof(char));
    content[contentSize-1] = '\0';
    
    // frees allocated memory
    fclose(fp);
    free(content);

    return 0;
}