#include "sort.h"

int compare(const void* a, const void* b)
{
    double diff =  *(double*)a - *(double*)b;
    return diff > 0 ? 1 : diff < 0 ? -1 : 0;
}

void quicksort(double* arr, long arr_size)
{
    qsort(arr, arr_size, sizeof(double), compare);
}

void selectionsort(double* arr, long arr_size)
{
    int i, j;
    int min;
    int x;

    for (i = 0; i < arr_size - 1; i++)
    {
        min = i;
        for ( j = i + 1; j < arr_size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        x = arr[min];
        arr[min] = arr[i];
        arr[i] = x;
    }
}

void insertionsort(double* arr, long arr_size)
{
    int i, j;
    int x;

    for (i = 2; i <= arr_size; i++)
    {
        x = arr[i];
        j = i - 1;
        arr[0] = x;

        while(x < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}

void mergesort(double* arr, long arr_size)
{	
 
 	separa_vetor(arr, 0, arr_size - 1);
 
}

void separa_vetor(double *arr, int inicio, int fim)
{

 if (inicio < fim)
    {

        int meio = inicio + (fim - inicio)/2;

        separa_vetor(arr, inicio, meio);
        separa_vetor(arr, meio + 1, fim);

        junta_vetor(arr, inicio, fim);
        
    }
}


void junta_vetor(double *vet, int inicio, int fim)
{

    int meio = inicio + (fim - inicio)/2;

    int esquerda_meio = meio - inicio + 1;
    int direita_meio = fim - meio;

    double *aux_esquerda;
    double *aux_direita;

    aux_esquerda = malloc(sizeof(double) * esquerda_meio);
    aux_direita = malloc(sizeof(double) * direita_meio);
    
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
    free(aux_esquerda);                                                          // \         /
    free(aux_direita);//esquecemos de liberar a memoria dos vetores auxiliares dnv   \(???)/
}
