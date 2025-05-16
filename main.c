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
#include <string.h>
#include "arvore.h"
#define MAX 100

int main() {
    int menu;
    
    do {
        printf("Menu:\n 1 - Inserir nova expressão\n 2 - Sair\n"); 
        printf("Insria opção desejada:");
        scanf("%d", &menu);
        getchar(); // usei para limpar o buffer, sem ele tava dando erro
        
        switch(menu) {
            case 1: {
                char expressao[MAX];
                char *p;

                //Inserir nova expressao:
                printf("Insira nova expressão: ");
                fgets(expressao, MAX, stdin);
                p = expressao;

                //Impressao da árvore inserida:
                printf("Expressão: %s\n", expressao);

                //Construir arvore:
                Arv *arv = arv_constroi(&p);

                //Impressao da arvore:
                printf("Árvore (pós-ordem): ");
                arv_imprime(arv);
                printf("\n");

                //Avaliacao da arvore:
                int result = avaliar_arvore(arv);
                printf("Resultado: %d\n\n", result);
                arv_libera(arv);
                break;
            }
            case 2:
                printf("Programa Finalizado!\n");
                break;

            default:
                printf("Opção invalida. Tente novamente.\n");
    }

} while (menu != 2);
    return 0;
}
