#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "descompactador.h"

int main(int argc, char const *argv[]) {
    char term[6] = {'\0'};
    FILE* comp = fopen(argv[1], "r");
    if(comp == NULL){
        printf("Erro ao Abrir o arquivo!\n");
        exit(1);
    }

    term[0] = fgetc(comp);
    for(int i = 1; term[i-1] != '0'; i++){
        term[i] = fgetc(comp);
        //printf("%c", term[i]);
    }

    char nomeSaida[259];
    strcpy(nomeSaida, argv[1]);
    int i, j;
    for(i = 0; nomeSaida[i - 1] != '.'; i++);

    for(j = 0, i; term[j] != 0; i++, j++){
        nomeSaida[i] = term[j];
    }
    nomeSaida[i-1] = '\0';
    

    fseek(comp, -1, SEEK_CUR);
    Arv* arv = GeraArvore(NULL, comp);

    descompacta(arv, comp, nomeSaida);
    arv_libera(arv);

    fclose(comp);

    //arv_imprime(arv);
    return 0;
}
