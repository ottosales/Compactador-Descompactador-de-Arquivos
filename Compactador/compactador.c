#define MB 8000000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compactador.h"
#include "bitmap.h"
#include "tabela.h"


void compacta(FILE* entrada, tTabela t, int * vet, FILE* saida){
    unsigned char c;

    bitmap bm = bitmapInit(MB);
    while(fread(&c, sizeof(unsigned char),1, entrada)==1){
        for(int i = 0; i < strlen(t.tabela[c]); i++){
            checa(&bm, saida);
            if(t.tabela[c][i] == '0')
                bitmapAppendLeastSignificantBit(&bm, 0);
            else
                bitmapAppendLeastSignificantBit(&bm, 1);
        }
    }

    bm = preenche(bm);
    salvaArquivo(bm, saida);
    free(bitmapGetContents(bm));

}

void checa(bitmap* bm, FILE* saida){
    if(bitmapGetLength(*bm) == bitmapGetMaxSize(*bm)){
        salvaArquivo(*bm, saida);
        free(bitmapGetContents(*bm));
        *bm = bitmapInit(MB);
    }
}

void salvaArquivo(bitmap bm, FILE* saida){
    bm = preenche(bm);
    fwrite(bitmapGetContents(bm), 1, (bitmapGetLength(bm)+7)/8, saida);
}

bitmap preenche(bitmap bm){
    for(int i = 0; i < bitmapGetLength(bm)%8; i++){
        bitmapAppendLeastSignificantBit(&bm, 0);
    }
    return bm;
}

int contaNumBits(int * vet, tTabela t){
    unsigned int tamanho = 0;
    int cont;
    for(int i = 0; i < 256; i++){
        if(vet[i] != 0){
            tamanho += vet[i]*strlen(&t.tabela[i][0]);
       }
    }

    return 8 - tamanho%8;
}
