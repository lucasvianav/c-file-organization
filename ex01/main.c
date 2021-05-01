#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char *content = (char *)malloc(0);

    // temporary/auxiliar variable to read individual chars
    char tmp;
    
    // loop to read each of the file's characters
    while(fread(&tmp, sizeof(char), 1, fp)){
        content = (char *)realloc(content, ++contentSize * sizeof(char));
        content[contentSize-1] = tmp;
    }
    
    // terminates the string 
    content = (char *)realloc(content, ++contentSize * sizeof(char));
    content[contentSize-1] = '\0';

    // temporary/auxiliar variables to read each .csv row
    // and corresponding csvs
    char *tmp_row, *tmp_id, *tmp_name; 
    int tmp_age;

    // deletes the header row (first register)
    if(content){ strsep(&content, "\n"); }

    // loops through every row (every register)
    while(strcmp(content, "")){
        // gets next row
        tmp_row = strsep(&content, "\n");
        
        // gets each of the row's values
        tmp_id = strsep(&tmp_row, ", ");
        tmp_name = strsep(&tmp_row, ", ");
        tmp_age = atoi(tmp_row);
        
        // if that row's user is overage, prints output
        if(tmp_age >= 18){ strcmp(tmp_name, "") ? printf("O usuario %s eh de maior.\n", tmp_name) : printf("O usuario de identificacao %s eh de maior.\n", tmp_id); }
    }

    fclose(fp);

    // it's not necessary to free content 
    // for strsep()'ll clean that for us

    return 0;
}