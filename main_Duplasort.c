#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "funcoes.h"

int main(){
	/* Referencia para o proximo da lista */
    celula *lst;
	/* Refeferencia para o final da lista */
    celula *fim;
	/* Referencia para cabeca da lista */
    celula *p;
    celula c, r;
    clock_t start, end;
    double cpu_time_used;

    int i, n=3000000;

    lst = &c;
    fim = &r;
    lst->seg = fim;
    lst->ant = NULL;
    fim->seg = NULL;
    fim->ant = lst;
    p=lst;

    tamanho += sizeof(celula)*n;

    srand(time(NULL));
    for(i=1; i<=n; i++)
        p = inserirLista(p, rand()%9999);

    printf("Antes de Ordenar\n");
    ImprimeLista(lst);
    printf("\n\n\n");

    start = clock();
	/* Chama a funcao Qsort */
    QuickSort(lst->seg, fim->ant);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Lista Ordenada \n");
    ImprimeLista(lst);
    printf("\nEspaco usado : %d", tamanho);
    printf("\n tempo de execução %.7f", cpu_time_used);
    printf("\n");
    return 0;
}

