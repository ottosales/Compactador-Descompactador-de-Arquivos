#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "tabela.h"

struct arv{
    unsigned char c;
	int peso;
    Arv* sae;
    Arv* sad;
};

Arv* arv_criavazia (){
    return NULL;
}

Arv* arv_no(unsigned char c, int peso){
    Arv* arv = (Arv*) malloc (sizeof(Arv));

    arv->c = c;
    arv->peso = peso;
    arv->sae = NULL;
    arv->sad = NULL;

    return arv;
}

Arv* liga_arvores(Arv* arv, Arv* sae, Arv* sad){
    arv->sae = sae;
    arv->sad = sad;

    return arv;
}
Arv* arv_cria (unsigned char c, int peso, Arv* e, Arv* d){
    Arv* arv = (Arv*) malloc (sizeof(Arv));

    arv->peso = peso;
    arv->c = c;
    arv->sae = e;
    arv->sad = d;

    return arv;
}

int arv_vazia (Arv* a){
    return a == NULL;
}

Arv* arv_libera (Arv* a){
    if(a != NULL){
    arv_libera(a->sae);
    arv_libera(a->sad);
    free(a);
    }

    return NULL;
}

int arv_pertence (Arv* a, char c){
    if(arv_vazia(a)){
        return 0;
    }
    else
        return a->c == c || arv_pertence (a->sae, c) || arv_pertence (a->sad, c);
}

void arv_imprime (Arv* a){
    printf("<");
    if(!arv_vazia(a)){
        printf("%c", a->c);
        arv_imprime(a->sae);
        arv_imprime(a->sad);
    }
    printf(">");
}

int max(int a, int b){
    if(a>b) return a;
    else return b;
}
int altura(Arv* a){
    if(arv_vazia(a))
        return -1;
    else
        return 1 + max(altura(a->sae), altura(a->sad));
}

char info (Arv* a){
    return a->c;
}

Arv* arv_pai (Arv* a, char c){
    if(!arv_vazia(a)){
        if(info(a->sae) == c || info(a->sad))
            return a;
        else{
            Arv* aux;
            aux = arv_pai(a->sae, c);
            if(aux == NULL)
                aux = arv_pai(a->sad, c);
            return aux;
        }
    }
    else
        return NULL;
}

int folhas (Arv* a){
    if(arv_vazia(a))
        return 0;
    else if(a->sae == NULL && a->sae == NULL)
        return 1;
    else
        return folhas(a->sae) + folhas(a->sad);
}

int ocorrencias (Arv* a, char c){
    if(arv_vazia(a))
        return 0;
    else{
        if(a->c == c)
            return 1 + ocorrencias(a->sae, c) + ocorrencias (a->sad, c);
        else
            return ocorrencias(a->sae, c) + ocorrencias (a->sad, c);
    }
}

unsigned char arv_retornac(Arv* a){
    return a->c;
}

int arv_retornapeso(Arv*a){
    return a->peso;
}

Arv* arv_alterac(Arv* a, unsigned char c){
    a->c = c;
    return a;
}

Arv* arv_alterapeso(Arv*a, int peso){
    a->peso = peso;
    return a;
}

Arv* arv_retornasae(Arv* a){
    return a->sae;
}

Arv* arv_retornasad(Arv* a){
    return a->sad;
}

void GeraTabela(Arv* arv, tTabela* t, char* cod, int i){
    if(arv->sae != NULL){
        cod[i] = '1';
        cod[i+1] = '\0';
        GeraTabela(arv->sae, t, cod, i+1);
    }
    if(arv->sad != NULL){
        cod[i] = '0';
        cod[i+1] = '\0';
        GeraTabela(arv->sad, t, cod, i+1);
    }
    else{
        printf("%u - ", arv->c);
        printf("%s\n", cod);
        for(int i = 0; i < strlen(cod) + 1; i++)
            t->tabela[arv->c][i] = cod[i];
    }
}

void GravaArvore(Arv* arv, FILE* saida){
    if(arv == NULL) return;
    if(arv->sae == NULL && arv->sad == NULL){
        fprintf(saida, "1");
        fprintf(saida, "%c", arv_retornac(arv));
    }
    else{
        fprintf(saida, "0");
    }
    GravaArvore(arv->sae, saida);
    GravaArvore(arv->sad, saida);
}

Arv* GeraArvore(Arv* a, FILE* comp){
    a = arv_no('\0', 0);
    unsigned char c;
    fscanf(comp, "%c", &c);

    if(c == '0'){
        a->sae = GeraArvore(a->sae, comp);
        a->sad = GeraArvore(a->sad, comp);
    }
    else{
        fscanf(comp, "%c", &c);
        a->c = c;
    }

    return a;
}
