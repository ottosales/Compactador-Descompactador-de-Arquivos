#ifndef LISTA_H_
#define LISTA_H_
#include "arvore.h"

/*Tipo que define a lista (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD.
  Usar lista COM Sentinela
  */
typedef struct tipolista TipoLista;

/*Inicializa o sentinela de uma lista
* inputs: nenhum
* output: Sentinela inicializado
* pre-condicao: nenhuma
* pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL
*/
TipoLista* InicializaLista();

/*Insere um aluno na primeira posi��o da lista de alunos
* inputs: aluno a ser inserido na lista (do tipo TipoItem) e a lista
* output: nenhum
* pre-condicao: aluno e lista n�o s�o nulos
* pos-condicao: lista cont�m o aluno inserido na primeira posi��o
*/
void Insere (Arv* arv, TipoLista* lista);

/*Retira um aluno de matr�cula mat da lista de alunos
* inputs: a lista e a matr�cula do aluno a ser retirado da lista
* output: o aluno (do tipo TipoItem) retirado da lista ou NULL, se o aluno n�o se encontrar na lista
* pre-condicao: lista n�o � nula
* pos-condicao: lista n�o cont�m o aluno de matr�cula mat
*/
Arv* Retira (TipoLista* lista, unsigned char c);


/*Imprime os dados de todos os alunos da lista
* inputs: a lista de alunos
* output: nenhum
* pre-condicao: lista n�o � nula
* pos-condicao: dados dos alunos impressos na saida padrao
*/
void Imprime (TipoLista* lista);

/*Libera toda a mem�ria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
* inputs: a lista encadeada de alunos
* output: Lista vazia (NULL)
* pre-condicao: lista n�o � nula
* pos-condicao: mem�ria alocada � liberada
*/
TipoLista* Libera (TipoLista* lista);


/*Inicializa um TipoItem aluno
* inputs: o nome, a matricula e o endereco do aluno
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, matricula e endereco validos
* pos-condicao: tipo item criado, com os campos nome, matricula e endereco copiados
*/
//TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco);

//ordena a lista em ordem crescente de pesos
void OrdenaLista(TipoLista* l);


//retorna o numero de elementos na lista
int retornaTamanho(TipoLista* l);

//retira incondicionalmente o primeiro elemento da lista
Arv* RetiraPrimeira(TipoLista* l);

//Cria arvore otima de codificacao
Arv* CriaArvore(TipoLista* l);

#endif /* LISTA_H_ */
