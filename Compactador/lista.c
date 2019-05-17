 #include "lista.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "arvore.h"

typedef struct tipocelula tCelula;
struct tipocelula{
    Arv* arv;
    tCelula* prox;
};

struct tipolista{
    tCelula* prim;
    tCelula* ult;
};

TipoLista* InicializaLista(){
    TipoLista* list = (TipoLista*)malloc(sizeof(TipoLista));
    list->prim = NULL;
    list->ult = NULL;
    return list;
}


void Insere (Arv* arv, TipoLista* lista){
    tCelula* cel = (tCelula*)malloc(sizeof(tCelula));
    cel->arv = arv;
    if(lista->prim==NULL){
        lista->prim = cel;
        lista->ult = cel;
        cel->prox = NULL;
    }

    else{
        lista->ult->prox = cel;
        lista->ult = cel;
        cel->prox = NULL;
    }

}

void Imprime (TipoLista* lista){
    tCelula* p = lista->prim;

    while(1){
        printf("%u - %d\n", arv_retornac(p->arv), arv_retornapeso(p->arv));
        if(p->prox == NULL) break;
        p = p->prox;
    }
        printf("\n");
}

Arv* Retira (TipoLista* lista, unsigned char c){
    tCelula* p = lista->prim;
    Arv* arv_removida = NULL;
    tCelula* ant;

    for(p; p != NULL; p = p->prox){
        if(arv_retornac(p->arv) == c){
            if(p == lista->prim && p == lista->ult){
                arv_removida = p->arv;
                lista->prim = NULL;
                lista->ult == NULL;
            }
            else if(p == lista->prim){
                arv_removida = p->arv;
                lista->prim = lista->prim->prox;

            }
            else if(p == lista->ult){
                arv_removida = p->arv;
                lista->ult = ant;
                lista->ult->prox = NULL;
            }
            else{
                arv_removida = p->arv;
                ant->prox = p->prox;
            }
        }
        ant = p;
    }
    free(p);
    return arv_removida;
}


TipoLista* Libera (TipoLista* lista){
    tCelula* p = lista->prim;
    tCelula* temp;

    while(p != NULL){
        temp = p->prox;
        arv_libera(p->arv);
        free(p);
        p = temp;
    }

    free(lista);

    return NULL;
}


void OrdenaLista(TipoLista* l){
    tCelula* aux = l->prim;
    tCelula* p;
    int itemp;
    unsigned char ctemp;
    Arv* arv1temp;
    Arv* arv2temp;
    for(aux; aux != NULL; aux = aux->prox){
        for(p = aux->prox; p != NULL; p = p->prox){
            if(arv_retornapeso(p->arv) < arv_retornapeso(aux->arv)){
                ctemp = arv_retornac(p->arv);
                itemp = arv_retornapeso(p->arv);
                arv1temp = arv_retornasae(p->arv);
                arv2temp = arv_retornasad(p->arv);
                p->arv = arv_alterac(p->arv, arv_retornac(aux->arv));
                p->arv = arv_alterapeso(p->arv, arv_retornapeso(aux->arv));
                liga_arvores(p->arv, arv_retornasae(aux->arv), arv_retornasad(aux->arv));
                aux->arv = arv_alterac(aux->arv, ctemp);
                aux->arv = arv_alterapeso(aux->arv, itemp);
                liga_arvores(aux->arv, arv1temp, arv2temp);

            }
        }
    }

}

Arv* RetiraPrimeira(TipoLista* l){
    tCelula* p = l->prim;
    Arv* arv_removida = p->arv;
    l->prim = l->prim->prox;
    free(p);
    return arv_removida;

}

int retornaTamanho(TipoLista* l){
    int contador = 0;
    tCelula* cel = l->prim;

    while(cel != NULL){
        contador++;
        cel = cel->prox;
    }
    return contador;
}


Arv* CriaArvore(TipoLista* l){
    while(retornaTamanho(l)>1){
        //printf("%d\n", retornaTamanho(l));
        Arv* arv1 = RetiraPrimeira(l);
        Arv* arv2 = RetiraPrimeira(l);
        Insere(liga_arvores(arv_no('\0', arv_retornapeso(arv1) + arv_retornapeso(arv2)), arv1, arv2), l);
        OrdenaLista(l);
        //Imprime(l);
    }

    return l->prim->arv;
}
