#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "arvore.h"
#include "tabela.h"
#include "bitmap.h"
#include "compactador.h"


int main(int argc, char const *argv[]) {

    FILE* fp = fopen(argv[1], "r");
    unsigned char c;
    int vet[256];

    int aux = 0, aux2 = 0;
    char comp[259];
    char term[5];
    strcpy(comp, argv[1]);
    int j;

    for(j = 0; comp[j] != '.'; j++);
    for(int k = j+1, l = 0; comp[k] != '\0'; k++, l++){
        term[l] = comp[k];
    }


    comp[j+1] = 'c';
    comp[j+2] = 'o';
    comp[j+3] = 'm';
    comp[j+4] = 'p';
    comp[j+5] = '\0';


    FILE* saida = fopen(comp, "w");
    fprintf(saida, "%s", term);

    for(int i = 0; i < 256; i++)  vet[i] = 0;
    while(fread(&c, sizeof(unsigned char),1, fp)==1)
        vet[c]++;

    fclose(fp);
    TipoLista* l = InicializaLista();

    for(int i = 0; i < 256; i++){
        if(vet[i] != 0){
        Arv* no = arv_no(i, vet[i]);
        Insere(no, l);
        }
    }
    OrdenaLista(l);
    Arv* arv_final = CriaArvore(l);
    char cod[20];
    tTabela t;
    ZeraTabela(&t);
    GeraTabela(arv_final, &t, cod, 0);

    GravaArvore(arv_final, saida);
    fprintf(saida, "%d", contaNumBits(vet, t));

    fp = fopen(argv[1], "r");
    compacta(fp, t, vet, saida);
    fclose(saida);
    fclose(fp);

    Libera(l);

    return 0;
}
