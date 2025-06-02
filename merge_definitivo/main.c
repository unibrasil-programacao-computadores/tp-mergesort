#include <stdio.h>
#include <stdlib.h>

#include "merge.h"

int main()
{
    double *vet;
    vet = malloc (sizeof(double) * TAM);

    le_vetor(vet);

    separa_vetor(vet, 0, TAM - 1);

    for(int i = 0; i < TAM; i++)
    {
        printf("%.2lf ", vet[i]);
    }

    free(vet);

    return 0;
}





