#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 4000000

void le_vetor(double *vet);
void separa_vetor(double *vet, int inicio, int fim);
void merge(double *vet, int inicio, int fim);

int main()
{
    double *vet;
    vet = malloc (sizeof(double) * TAM);

    clock_t inicio = clock();

    le_vetor(vet);

    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de leitura: %.3f segundos\n", tempo);

    separa_vetor(vet, 0, TAM - 1);

    for(int i = 0; i < 40000; i++)
    {
        printf("%.2lf ", vet[i]);
    }

    free(vet);

    return 0;
}

void le_vetor(double *vet)
{

    FILE *arq_txt;

    arq_txt = fopen ("reverse_ordered-input-4000000-float.txt", "r");

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

void separa_vetor(double *vet, int inicio, int fim)
{
    if (inicio < fim)
    {

        int meio = inicio + (fim - inicio)/2;

        separa_vetor(vet, inicio, meio);
        separa_vetor(vet, meio + 1, fim);

        merge(vet, inicio, fim);
    }
}

void merge(double *vet, int inicio, int fim)
{

    int meio = inicio + (fim - inicio)/2;

    int esquerda_meio = meio - inicio + 1;
    int direita_meio = fim - meio;

    double *aux_esquerda = malloc(sizeof(double) * esquerda_meio);
    double *aux_direita = malloc(sizeof(double) * direita_meio);

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
        vet[k] = aux_direita[i];
        j++;
        k++;
    }
}
