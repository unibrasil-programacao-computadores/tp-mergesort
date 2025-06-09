#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdlib.h>

void quicksort(double* arr, long arr_size);

void selectionsort(double* arr, long arr_size);
void insertionsort(double* arr, long arr_size);

void shellsort(double* arr, long arr_size);
void heapsort(double* arr, long arr_size);

void countingsort(double* arr, long arr_size);
void radixsort(double* arr, long arr_size);
void bucketsort(double* arr, long arr_size);


										//MERGESORT
//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//

void mergesort(double* arr, long arr_size);
void separa_vetor(double *arr, int inicio, int fim);
void junta_vetor(double *arr, int inicio, int fim);

//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//

#endif // SORT_H_INCLUDED
