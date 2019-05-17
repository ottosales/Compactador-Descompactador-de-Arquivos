#ifndef ARVORE_H_
#define ARVORE_H_
#include "tabela.h"
#include <stdio.h>
typedef struct arv Arv;


//Cria uma árvore vazia
Arv* arv_criavazia (void);

//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
Arv* arv_cria (unsigned char c, int peso, Arv* e, Arv* d);

//cria um no', uma arvore sem filhos
Arv* arv_no(unsigned char c, int peso);

//liga um no' raiz a uma subarvore na esquerda e uma na direita
Arv* liga_arvores(Arv* arv, Arv* sae, Arv* sad);

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a);

//retorna true se a árvore estiver vazia e false
//caso contrário
int arv_vazia (Arv* a);

//indica a ocorrência (1) ou não (0) do caracter c
int arv_pertence (Arv* a, char c);

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a);

//retorna o pai de um dado no
Arv* arv_pai (Arv* a, char c);

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a);

//retorna o numero de ocorrencias de um dado caracter na arvore
int ocorrencias (Arv* a, char c);

//retorna a altura da arvore
int altura (Arv* a);

//retorna o caracter da arvore
unsigned char arv_retornac(Arv* a);

//retorna a frequencia do caracter na arvore
int arv_retornapeso(Arv* a);

//altera o caracter da arvore
Arv* arv_alterac(Arv* a, unsigned char c);

//altera o peso do caracter da arvore
Arv* arv_alterapeso(Arv*a, int peso);

//retorna a subarvore da esquerda
Arv* arv_retornasae(Arv* a);

//retorna a subarvore da direita
Arv* arv_retornasad(Arv* a);

void GeraTabela(Arv* arv, tTabela* t, char* cod, int i);


void GravaArvore(Arv* arv, FILE* saida);


Arv* GeraArvore(Arv* a, FILE* comp);

#endif /*ARVORE_H_*/
