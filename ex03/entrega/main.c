/* AUTHOR: Lucas Viana Vilela */
/* N_USP: 10748409 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binarioNaTela(char *nomeArquivoBinario) { /* Você não precisa entender o código dessa função. */

    /* Use essa função para comparação no run.codes. Lembre-se de ter fechado (fclose) o arquivo anteriormente.
     *  Ela vai abrir de novo para leitura e depois fechar (você não vai perder pontos por isso se usar ela). */

    unsigned long i, cs;
    unsigned char *mb;
    size_t fl;
    FILE *fs;
    if(nomeArquivoBinario == NULL || !(fs = fopen(nomeArquivoBinario, "rb"))) {
        fprintf(stderr, "ERRO AO ESCREVER O BINARIO NA TELA (função binarioNaTela): não foi possível abrir o arquivo que me passou para leitura. Ele existe e você tá passando o nome certo? Você lembrou de fechar ele com fclose depois de usar?\n");
        return;
    }
    fseek(fs, 0, SEEK_END);
    fl = ftell(fs);
    fseek(fs, 0, SEEK_SET);
    mb = (unsigned char *) malloc(fl);
    fread(mb, 1, fl, fs);

    cs = 0;
    for(i = 0; i < fl; i++) {
        cs += (unsigned long) mb[i];
    }
    printf("%lf\n", (cs / (double) 100));
    free(mb);
    fclose(fs);
}

int main(){
    // .bin filename string (expecting max 20 chars)
    char filename[20];

    // reads filename from stdin
    scanf("%s", filename);

    // opens the file in binary-writing mode
    FILE *fp = fopen(filename, "wb");
    
    // number of registers to be read
    int N;

    // temporary/auxiliar variables to read each value
    int tmp_id, tmp_age;
    char tmp_name[100];
    
    // reads the number of inputs
    scanf("%d", &N);
    
    // loop that'll read all of the input and write it to disk
    for(int i = 0; i < N; i++){
        // reads each field
        scanf("%d", &tmp_id);
        scanf("%s", tmp_name);
        scanf("%d", &tmp_age);
        
        // writes to disk
        fwrite(&tmp_id, sizeof(int), 1, fp);
        fwrite(tmp_name, sizeof(char), strlen(tmp_name)+1, fp);
        fwrite(&tmp_age, sizeof(int), 1, fp);
    }

    // closes the file
    fclose(fp);

    binarioNaTela(filename);

    return 0;
}