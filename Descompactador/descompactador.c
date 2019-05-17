#include <stdio.h>
#include <stdlib.h>
#include "descompactador.h"
#include "bitmap.h"
#include "arvore.h"


void descompacta(Arv* arv, FILE* comp, char* arqnome){

    bitmap bm = bitmapInit(8);
    bm.length = 8;
    Arv* raiz = arv;
    int contador, i;
    char vet[8];
    char caracter[2];
    int lixo = (int) fgetc(comp) - 48;

    int tamCabecalho = ftell(comp);
    fseek(comp, 0, SEEK_END);
    int tamTotal = ftell(comp);
    fseek(comp, tamCabecalho, SEEK_SET);

    int numBitsASeremLidos = 8*(tamTotal - tamCabecalho) - lixo;
    int contaBits = 0;

    FILE* saida = fopen(arqnome, "w");

    while(fscanf(comp, "%c", &bm.contents[0]) == 1){
        contador = 8;
        while(contador != 0){
            if(bitmapGetBit(bm, 8-contador) == 0){
                //printf("Fui para a direita\n");
                arv = arv_retornasad(arv);
            }
            else{
                //printf("Fui para a esquerda\n");
                arv = arv_retornasae(arv);
            }

            if(arv_retornasad(arv) == NULL && arv_retornasae(arv) == NULL){
                //printf("Achei um caracter! Ele eh o ");
                caracter[0] = arv_retornac(arv);
                //printf("%c", caracter[0]);
                fwrite(caracter, 1, 1, saida);
                arv = raiz;
            }
            contaBits++;
            if(contaBits == numBitsASeremLidos) break;
            contador--;
        }
        if(contaBits == numBitsASeremLidos) break;

}
free(bitmapGetContents(bm));
fclose(saida);
}
