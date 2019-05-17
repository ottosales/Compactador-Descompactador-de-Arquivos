#ifndef COMPACTADOR_H_
#define COMPACTADOR_H_
#include "bitmap.h"
#include "tabela.h"

void compacta(FILE* entrada, tTabela t, int * vet, FILE* saida);

void checa(bitmap* bm, FILE* saida);

void salvaArquivo(bitmap bm, FILE* saida);

bitmap preenche(bitmap bm);

int contaNumBits(int * vet, tTabela t);


#endif
