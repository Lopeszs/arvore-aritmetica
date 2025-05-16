/**************************************************
*
* Nome dos(as) estudantes: 
    Isabela Fernandes Lopes (RGA:)
    Maria Eduarda da Silva Gonçalves (RGA: 202419060269)
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
*/
#include "pilha.h" //sera que pode incluir outra tad?
typedef struct arv {
    char info; //ver se vamos mudar para considerar uma string
    struct arv* esq;
    struct arv* dir;
} Arv;

Arv* arv_criavazia(void);
Arv* arv_cria(char c, Arv* e, Arv* d);
Arv* arv_libera(Arv* a);
int arv_vazia(Arv* a);
int arv_pertence(Arv* a, char c);
void arv_imprime(Arv* a);
int avaliar_arvore(Arv* a);
Pilha* avaliar_posordem(Arv* a, Pilha* pilha);
int verifica_operador(Arv* a);

//OBS: tem algumas dessas funções que não sei se iremos usar, no caso se nao usar devemos dxar mesmo assim?

