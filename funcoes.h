#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Estrutura de lista duplamente encadeada, com cabeca de no proximo e anterior */
struct cel_{
    int conteudo;
    struct cel_ *seg;
    struct cel_ *ant;
};

/* Estrutura de lista */
typedef struct cel_ celula;

/* Variavel global */
int tamanho;

/*lista vazia*/
bool lista_vazia(celula *p); //////extraaaaaaaaaaaaaaaa!!!


/* Chama o prototipo da funcao QSort */
void QuickSort(celula *p, celula *r);

/* Chama o prototipo da funcao Separa */
celula *Separa(celula *p, celula *r);

/* Chama o prototipo da funcao inserirLista */
celula *inserirLista(celula * lst, int n);

/* Chama o prototipo da funcao Iprime Lista */
void ImprimeLista(celula * lst);

/*lista vazia*/
bool lista_vazia(celula *p){//extra!!!!!!!!
    if(p==NULL){
        return false;
    }
    if(p==NULL){
        return false;}
    return true;
}

/* Funcao Qsort */
void QuickSort(celula *p, celula *r) {
    celula *j = malloc(sizeof(celula));
    if((r != NULL)&&(p!=r)&&(p != r->seg)) {
        j = Separa(p, r);
        QuickSort(p, j->ant);
        QuickSort(j->seg, r);
    }
}

/* Funcao Separa, encontra o valor medio da lista e divide com os valores menores a esquerda e maiores a direita  */
celula *Separa(celula *p, celula *r){
	
    int aux, x  = r->conteudo;
    celula *i = p->ant;
    celula *k;

    tamanho += sizeof(aux) + sizeof(aux);

    for (k = p; k != r; k = k->seg)
    {
        if (k->conteudo <= x)
        {
            i = i->seg;
            aux = i->conteudo;
            i->conteudo = k->conteudo;
            k->conteudo = aux;
        }
    }
    i = i->seg;
    aux = i->conteudo;
    i->conteudo = r->conteudo;
    r->conteudo = aux;

    return i;
}

/* Funcao para inserir um valor na lista encadeada */
celula * inserirLista(celula * p, int x){
	/* Faz alocacao de um no */
    celula * nova;
    nova = (celula*)malloc(sizeof(celula));
	/* Insere um valor ao no */
    nova->conteudo = x;
	/* Aponta para o no seguinte */
    nova->seg = p->seg;
	/* Aponta a cabeca do no de anterior para cabeca da lista */
    nova->ant = p;
    p->seg->ant = nova;
	/* Aponta a cabeca do no proximo para o proximo no */
    p->seg = nova;
    return p;
}

/* Funcao para imprimir o conteudo da lista */
void ImprimeLista(celula * lst){
	/* Auxiliar apontando para o proximo da lista */
    celula * p = lst->seg;
	/* Enquanto proximo for diferente de nulo, ele imprime e incrementa o ponteiro */
    while (p->seg != NULL){
        printf("%d ", p->conteudo);
        p=p->seg;
    }
}
