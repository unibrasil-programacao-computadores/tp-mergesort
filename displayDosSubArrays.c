#include <stdio.h>

void separa_matriz(int arr[], int esquerda, int direita);

int main()
{
    int vet[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int TAM = sizeof(vet)/sizeof(vet[0]);

    printf("vetor original: \n");
    for(int i = 0; i < TAM ; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n\n");

    separa_matriz(vet, 0, TAM - 1);

    printf("vetor ordenado: \n");
    for(int i = 0; i < TAM; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}

void separa_matriz(int arr[], int esquerda, int direita) {
    if(esquerda < direita) {
        int meio = esquerda + (direita - esquerda)/2;

        separa_matriz(arr, esquerda, meio);      // metade esquerda
        separa_matriz(arr, meio + 1, direita);   // metade direita

        printf("Subvetor esquerda [%d..%d]: ", esquerda, meio);
        for(int i = esquerda; i <= meio; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Subvetor direita [%d..%d]: ", meio + 1, direita);
        for(int j = meio + 1; j <= direita; j++){
            printf("%d ", arr[j]);
        }
        printf("\n\n");
    }
}
