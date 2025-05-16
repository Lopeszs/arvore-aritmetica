/**************************************************
*
* Nome dos(as) estudantes: 
    Isabela Fernandes Lopes (RGA: 202419060170S)
    Maria Eduarda da Silva Gonçalves (RGA: 202419060269)
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
* Declarar a estrutura e as operações básicas para uma pilha de inteiros,
* usada para auxiliar na avaliação das expressões representadas nas árvores.
*/

typedef struct pilha {
    int valor;
    struct pilha *prox;
} Pilha;

Pilha* empilhar(Pilha *pilha, int valor);
Pilha* desempilhar(Pilha *pilha, int *valor);
Pilha* criarPilha();