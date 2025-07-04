#include <stdio.h>
#include <stdlib.h>

#include "merge_stack.h"

void le_vetor(double vet[])
{

    FILE *arq_txt;

    arq_txt = fopen ("reverse_ordered-input-10000-float.txt", "r");

    for (int i = 0; i < TAM; i++)
    {

        int verifica = fscanf(arq_txt, "%lf", &vet[i]);

        if (verifica != 1)
        {
            break;
        }
    }
    fclose(arq_txt);
}

void separa_vetor(double vet[], int inicio, int fim)
{
    if (inicio < fim)
    {

        int meio = inicio + (fim - inicio)/2;

        separa_vetor(vet, inicio, meio);
        separa_vetor(vet, meio + 1, fim);

        junta_vetor(vet, inicio, fim);
    }
}

void junta_vetor(double vet[], int inicio, int fim)
{

    int meio = inicio + (fim - inicio)/2;

    int esquerda_meio = meio - inicio + 1;
    int direita_meio = fim - meio;

    double aux_esquerda[esquerda_meio];
    double aux_direita[direita_meio];

    for(int i = 0; i < esquerda_meio; i++)
    {
        aux_esquerda[i] = vet[inicio + i];
    }

    for(int j = 0; j < direita_meio; j++)
    {
        aux_direita[j] = vet[(meio + 1) + j];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while(i < esquerda_meio && j < direita_meio)
    {
        if(aux_esquerda[i] <= aux_direita[j])
        {
            vet[k] = aux_esquerda[i];
            i++;
        }
        else
        {
            vet[k] = aux_direita[j];
            j++;
        }
        k++;
    }

    while(i < esquerda_meio)
    {
        vet[k] = aux_esquerda[i];
        i++;
        k++;
    }
    while(j < direita_meio)
    {
        vet[k] = aux_direita[j];
        j++;
        k++;
    }
}
