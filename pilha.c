/**************************************************
*
* Nome dos(as) estudantes:
    Isabela Fernandes Lopes (RGA: 202419060170)
    Maria Eduarda da Silva Gonçalves (RGA: 202419060269)
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
* Implementar as operações básicas de uma pilha dinâmica, como empilhar,
* desempilhar e criar a pilha, para suporte à avaliação das expressões
* na árvore.
*/
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criarPilha(){
    return NULL;
}

Pilha* empilhar(Pilha *pilha, int valor) {
    Pilha *novo = (Pilha*) malloc(sizeof(Pilha));

    if (!novo) {
        printf("Erro ao empilhar um novo valor!\n");
        return pilha;
    }

    novo->valor = valor;
    novo->prox = pilha;
    return novo;
}

//Verificar essa função com a isa
Pilha* desempilhar(Pilha *pilha, int *valor) {
    if (pilha == NULL) {
        printf("Pilha vazia!\n");
        return NULL;
    }
    Pilha *aux = pilha;
    *valor = pilha->valor;
    pilha = pilha->prox;
    free(aux);
    return pilha;
}
