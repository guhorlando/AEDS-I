/*Gustavo Silva Orlando
18/06/2025
Universidade Federal de Alfenas - Unifal
AEDs I - Prática
Objetivo: implementar uma biblioteca de métodos de ordenação em C++ utilizando exclusivamente ponteiros para manipulação dos elementos dos vetores, sem o uso de índices em nenhuma situação.
*/

/*
    Biblioteca de métodos de ordenação usando apenas ponteiros.
    Implementa Bubble Sort, Selection Sort e Insertion Sort para vetores de inteiros.
    Não utiliza índices em nenhuma situação.
    Para uso, forneça ponteiros para o início e o fim do vetor.
*/
#ifndef ORDENACAO_H
#define ORDENACAO_H

// Ordena o vetor usando Bubble Sort (apenas ponteiros)
void bubbleSort(int* begin, int* end);

// Ordena o vetor usando Selection Sort (apenas ponteiros)
void selectionSort(int* begin, int* end);

// Ordena o vetor usando Insertion Sort (apenas ponteiros)
void insertionSort(int* begin, int* end);

#endif