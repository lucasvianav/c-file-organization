
#include <stdio.h>

int main(){
    // .bin filename string (expecting max 20 chars)
    char filename[20];

    // reads filename from stdin
    scanf("%s", filename);

    // opens the file in binary-writing mode
    FILE *fp = fopen(filename, "wb");
    
    // number of register to be read
    int N;

    // temporary/auxiliar variables to read each value
    int tmp_id, tmp_age, tmp_nameSize = 0;
    char *tmp_name = (char *)malloc(sizeof(char)), tmp;
    
    // loop that'll read all of the input and write it to disk
    for(int i = 0; i < N; i++){
        // reads the id
        scanf("%d", tmp_id);

        // loop that read the user's name until it's finished ('\0' is found)
        while(tmp_name[tmp_nameSize-1] != '\0'){
            // reads next character
            scanf("%c", &tmp);

            // allocates memory for a new char in tmp_name
            tmp_name = (char *)realloc(tmp_name, ++tmp_nameSize * sizeof(char));
            
            // if the charater read is an space, it means the name has ended
            tmp_name[tmp_nameSize-1] = (tmp == ' ') ? '\0' : tmp;
        }

        // reads the age
        scanf("%d", tmp_age);
        
        // writes to disk
        fwrite(&tmp_id, sizeof(int), 1, fp);
        fwrite(tmp_name, sizeof(char), tmp_nameSize, fp);
        fwrite(&tmp_age, sizeof(int), 1, fp);
    }

    fclose(fp);
    free(tmp_name);

    return 0;
}