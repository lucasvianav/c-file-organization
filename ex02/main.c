#include <stdio.h>

int main(){
    // .csv filename string (expecting max 20 chars)
    char filename[20];

    // reads filename from stdin
    scanf("%s", filename);

    // opens the file in binary-reading mode
    FILE *fp = fopen(filename, "rb");

    // temporary/auxiliar variables to read each value
    char tmp_name[50]; 
    int tmp_id, tmp_age;
    
    // loops through every register
    while(fread(&tmp_id, sizeof(int), 1, fp) && fread(tmp_name, sizeof(char), 50, fp) && fread(&tmp_age, sizeof(int), 1, fp)){
        // if that user is overage, prints output
        if(tmp_age >= 18){ (tmp_name[0] != '\0') ? printf("O usuario %s eh de maior.\n", tmp_name) : printf("O usuario de identificacao %d eh de maior.\n", tmp_id); }
    }
    
    fclose(fp);

    return 0;
}