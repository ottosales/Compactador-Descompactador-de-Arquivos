#include <stdio.h>
#include "tabela.h"

void ImprimeTabela(tTabela* t){
    for(int i = 0; i < 256; i++)
        printf("%u - %s\n", i, t->tabela[i]);
}

void ZeraTabela(tTabela* t){
    for(int i = 0; i < 256; i++)
        t->tabela[i][0] = '\0';
}
