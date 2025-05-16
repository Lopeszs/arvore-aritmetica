/**************************************************
*
* Nome dos(as) estudantes: 
    Isabela Fernandes Lopes (RGA: 202419060170)
    Maria Eduarda da Silva Gonçalves (RGA: 202419060269)
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
* Implementar as funções para construir árvores binárias de expressões
* aritméticas a partir de expressões infixas, imprimir a árvore em
* pós-ordem e avaliar o resultado da expressão representada pela árvore.

*/
#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

Arv *arv_criavazia(void)
{
    return NULL;
}

Arv *arv_cria_num(int valor)
{
    Arv *p = (Arv *)malloc(sizeof(Arv));
    p->e_operador = 0;
    p->valor = valor;
    p->operador = '\0';
    p->esq = NULL;
    p->dir = NULL;
    return p;
}

Arv* arv_cria_ope(char operador, Arv* sae, Arv* sad) 
{
    Arv* p = (Arv*) malloc(sizeof(Arv));
    p->e_operador = 1;
    p->operador = operador;
    p->valor = 0;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int arv_vazia(Arv *a)
{
    return a == NULL;
}

Arv* arv_libera(Arv *a)
{
    if (!arv_vazia(a))
    {
        arv_libera(a->esq); 
        arv_libera(a->dir); 
        free(a);           
    }
    return NULL;
}

/*
int arv_pertence(Arv *a, char c)
{
    if (arv_vazia(a))
        return 0; 
    else
        return a->info == c ||
               arv_pertence(a->esq, c) ||
               arv_pertence(a->dir, c);
}
*/

//implementando considerando pos-ordem
void arv_imprime(Arv *a)
{
    if (!arv_vazia(a))
    {
        arv_imprime(a->esq);      
        arv_imprime(a->dir);       
        if (a->e_operador)
            printf("%c ", a->operador);
        else
            printf("%d ", a->valor);
    }
}

Arv* arv_constroi(char **expressao) {
    while (**expressao == ' ') {
        (*expressao)++;
    }
    if (**expressao == '(') {
        (*expressao)++; // tira '('

        while (**expressao == ' ') {
            (*expressao)++;
        }
        Arv* esquerda = arv_constroi(expressao);

        while (**expressao == ' ') {
            (*expressao)++;
        }

        char operador = **expressao;
        (*expressao)++;

        while (**expressao == ' ') {
            (*expressao)++;
        }

        Arv* direita = arv_constroi(expressao);

        while (**expressao == ' ') {
            (*expressao)++;
        }

        if (**expressao == ')') {
            (*expressao)++; // tira ')'
        }

        return arv_cria_ope(operador, esquerda, direita);
    } 
    else {
        int valor = 0;

        while (**expressao >= '0' && **expressao <= '9') {
            int digito = **expressao - '0'; // usando a tabela asc 0 = 48
            valor = valor * 10 + digito; // aumenta em dezena, centena...
            (*expressao)++;
        }

        return arv_cria_num(valor);
    }
}

//Verificar essa função com a isa
Pilha* avaliar_posordem(Arv *a, Pilha *pilha) 
{
    if (arv_vazia(a)) {
        return pilha;
    }

    pilha = avaliar_posordem(a->esq, pilha);
    pilha = avaliar_posordem(a->dir, pilha);

    if (!a->e_operador) {
        pilha = empilhar(pilha, a->valor);
    } 
    else {
        int b, c, resultado;
        pilha = desempilhar(pilha, &b);
        pilha = desempilhar(pilha, &c);

        switch (a->operador) {
            case '+': resultado = c + b; break;
            case '-': resultado = c - b; break;
            case '*': resultado = c * b; break;
            case '/': resultado = c / b; break;
            default: 
                printf("Operador Inválido!\n");
                exit(1);
        }

        pilha = empilhar(pilha, resultado);
    }

    return pilha;
}


// Essa função chama a recursão
int avaliar_arvore(Arv *a) 
{
    Pilha *pilha = criarPilha();
    pilha = avaliar_posordem(a, pilha);

    int resultado;
    pilha = desempilhar(pilha, &resultado);
    return resultado;
}
