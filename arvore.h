/**************************************************
*
* Nome dos(as) estudantes: 
    Isabela Fernandes Lopes (RGA: 202419060170)
    Maria Eduarda da Silva Gonçalves (RGA: 202419060269)
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
* Definir a estrutura da árvore binária que representa expressões
* aritméticas, além de declarar as funções para criar, manipular,
* imprimir e avaliar essas árvores.
*/
#include "pilha.h"

typedef struct arv {
    int valor;
    char operador;
    int e_operador; // 1 = verdadeiro (operador), 0 = falso (numero)
    struct arv* esq;
    struct arv* dir;
} Arv;

Arv* arv_criavazia(void);
Arv* arv_cria_num(int valor);
Arv* arv_cria_ope(char operador, Arv* sae, Arv* sad);
Arv* arv_libera(Arv* a);
int arv_vazia(Arv* a);
void arv_imprime(Arv* a);
Arv* arv_constroi(char** expressao);
Pilha* avaliar_posordem(Arv* a, Pilha* pilha);
int avaliar_arvore(Arv* a);


