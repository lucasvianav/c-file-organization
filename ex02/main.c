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
    FILE *fp = fopen(filename, "rb");

    // temporary/auxiliar variables to read each .csv row
    // and corresponding csvs
    char tmp_name[50]; 
    int tmp_id, tmp_age;
    
    // loops through every register
    while(fread(tmp_id, sizeof(int), 1, fp) && fread(tmp_name, sizeof(char), 50, fp) && fread(tmp_age, sizeof(int), 1, fp)){
        // if that row's user is overage, prints output
        if(tmp_age >= 18){ strcmp(tmp_name, "") ? printf("O usuario %s eh de maior.\n", tmp_name) : printf("O usuario de identificacao %s eh de maior.\n", tmp_id); }
    }
    
    fclose(fp);

    return 0;
}