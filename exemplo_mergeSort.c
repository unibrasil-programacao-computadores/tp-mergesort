#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int esquerda_metade, int meio, int direita_metade);
void mergeSort(int arr[], int l, int r);

int main()
{
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	int i;

	printf("Array Original: \n");
	for ( i = 0; i < arr_size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	mergeSort(arr, 0, arr_size - 1);

	printf("\nArray Ordenado: \n");

	for ( i = 0; i < arr_size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

void merge(int arr[], int esquerda_metade, int meio, int direita_metade)
{
	int i, j, k;
	int n1 = meio - esquerda_metade + 1;
	int n2 = direita_metade - meio;
	int L[n1], R[n2];

	for (i = 0; i < n1; i++){
		L[i] = arr[esquerda_metade + i];
	}
	for (j = 0; j < n2; j++){
		R[j] = arr[meio + 1 + j];
	}
	i = 0;
	j = 0;
	k = esquerda_metade;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
