/**************************************************
*
* Nome dos(as) estudantes: 
    Isabela Fernandes Lopes (RGA: 202419060170)
    Maria Eduarda da Silva Gonçalves (RGA: 202419060269)
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
*/
#include "pilha.h"

typedef struct arv {
    int valor;  // numeros
    char operador; //ver se vamos mudar para considerar uma string // apenas peradores
    int e_operador; // 1 = verdadeiro (operador), 0 = falso (numero)
    struct arv* esq;
    struct arv* dir;
} Arv;

Arv* arv_criavazia(void);
//Arv* arv_cria(char c, Arv* e, Arv* d);
Arv* arv_cria_num(int valor);
Arv* arv_cria_ope(char operador, Arv* sae, Arv* sad);
Arv* arv_libera(Arv* a);
int arv_vazia(Arv* a);
//int arv_pertence(Arv* a, char c);
void arv_imprime(Arv* a);
Arv* arv_constroi(char** expressao);
Pilha* avaliar_posordem(Arv* a, Pilha* pilha);
int avaliar_arvore(Arv* a);
//int verifica_operador(Arv* a);

//OBS: tem algumas dessas funções que não sei se iremos usar, no caso se nao usar devemos dxar mesmo assim?

