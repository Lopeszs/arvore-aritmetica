/**************************************************
*
* Nome dos(as) estudantes: 
    Isabela Fernandes Lopes (RGA:)
    Maria Eduarda da Silva Gonçalves (RGA: 202419060269)
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo: 
*/

struct pilha {
    int valor;
    struct pilha *prox;
};
typedef struct pilha Pilha;

Pilha* empilhar(Pilha *pilha, int valor);
Pilha* desempilhar(Pilha *pilha, int *valor);
Pilha* criarPilha();