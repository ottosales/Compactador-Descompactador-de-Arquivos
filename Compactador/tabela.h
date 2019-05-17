#ifndef TABELA_H_
#define TABELA_H_

typedef struct tabela tTabela;

struct tabela{
    char tabela[256][20];
};

void ImprimeTabela(tTabela* t);


void ZeraTabela(tTabela* t);

#endif
