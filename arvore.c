/**************************************************
*
* Nome dos(as) estudantes: 
    Isabela Fernandes Lopes (RGA:)
    Maria Eduarda da Silva Gonçalves (RGA: 202419060269)
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
*/
#include "arvore.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Arv *arv_criavazia(void)
{
    return NULL;
}

Arv *arv_cria(char c, Arv *sae, Arv *sad)
{
    Arv *p = (Arv *)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int arv_vazia(Arv *a)
{
    return a == NULL;
}

Arv *arv_libera(Arv *a)
{
    if (!arv_vazia(a))
    {
        arv_libera(a->esq); 
        arv_libera(a->dir); 
        free(a);           
    }
    return NULL;
}

int arv_pertence(Arv *a, char c)
{
    if (arv_vazia(a))
        return 0; 
    else
        return a->info == c ||
               arv_pertence(a->esq, c) ||
               arv_pertence(a->dir, c);
}
//implementando considerando pos-ordem
void arv_imprime(Arv *a)
{
    if (!arv_vazia(a))
    {
        arv_imprime(a->esq);      
        arv_imprime(a->dir);       
        printf("%c ", a->info);
    }
}

//usei essa função auxiliar para testar, provavel que vamos usar outra
int verifica_operador(Arv *a) {
    return a->info == '+' || a->info == '-' || a->info == '*' || a->info == '/';
}
//Verificar essa função com a isa
Pilha* avaliar_arvore(Arv *a, Pilha *pilha) {
    if (arv_vazia(a)){
        return pilha;
    }

    pilha = avaliar_posordem(a->esq, pilha);
    pilha = avaliar_posordem(a->dir, pilha);

    if (!verifica_operador(a)) {
        // Se for número, empilha
        int x = a->info - '0'; //eu usei esse somente para testar, mas ele é falho quando tem mais de um char
        pilha = empilhar(pilha, a->info); 
    } 

    else {
        int b, c, resultado;
        pilha = desempilhar(pilha, &b);
        pilha = desempilhar(pilha, &c);

        switch (a->info) {
            case '+': 
                resultado = c + b; 
                break;
            case '-': 
                resultado = c - b; 
                break;
            case '*': 
                resultado = c * b; 
                break;
            case '/': 
                resultado = c / b; 
                break;
        }

        pilha = empilhar(pilha, resultado);
    }

    return pilha;
}

// Essa função chama a recursão
int avaliar_arvore(Arv *a) {
    Pilha *pilha = criarPilha();
    pilha = avaliar_posordem(a, pilha);

    int resultado;
    pilha = desempilhar(pilha, &resultado);
    return resultado;
}
