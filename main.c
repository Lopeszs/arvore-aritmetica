/**************************************************
*
* Nome dos(as) estudantes:
    Isabela Fernandes Lopes (RGA: 202419060170)
    Maria Eduarda da Silva Gonçalves (RGA: 202419060269)
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
* Implementar o programa principal que lê expressões aritméticas,
* constrói suas árvores binárias, imprime a árvore em pós-ordem e
* exibe o resultado da avaliação da expressão.
* Serve para testar e demonstrar o funcionamento das funções das outras
* unidades (arvore e pilha).
*/
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {
    // PEGUEI ESSE TESTE DO CHAT P VC TESTAR MARIA
    // Expressões que você quer testar
    char expr1[] = "(3 + (2 * 5))";
    char expr2[] = "((17 - 5) * (6 + 4))";

    char *p;

    // Teste da primeira expressão
    printf("Expressão: %s\n", expr1);
    p = expr1;
    Arv *arv1 = arv_constroi(&p);
    printf("Árvore (pós-ordem): ");
    arv_imprime(arv1);
    printf("\n");
    int res1 = avaliar_arvore(arv1);
    printf("Resultado: %d\n\n", res1);
    arv_libera(arv1);

    // Teste da segunda expressão
    printf("Expressão: %s\n", expr2);
    p = expr2;
    Arv *arv2 = arv_constroi(&p);
    printf("Árvore (pós-ordem): ");
    arv_imprime(arv2);
    printf("\n");
    int res2 = avaliar_arvore(arv2);
    printf("Resultado: %d\n", res2);
    arv_libera(arv2);

    return 0;
}
