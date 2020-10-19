#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 30000000

void GeraAleatorios(unsigned long int numeros[],unsigned long int quantNumeros,unsigned long int Limite)
{
    unsigned long int *vetor = (unsigned long int*) malloc(sizeof(unsigned long int) * MAX);

    unsigned long int i;

    for(i = 0; i < MAX; i++)
    {
        vetor[i] = (unsigned long) rand() % MAX;
        printf("%lu\n", vetor[i]);
    }
}

int main()
{
    unsigned long int *numeros = (unsigned long int*) malloc(sizeof(unsigned long int) * MAX);

    GeraAleatorios(numeros, 0, MAX);

    return 0;
}