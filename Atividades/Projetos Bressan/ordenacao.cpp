/*Gustavo Silva Orlando
18/06/2025
Universidade Federal de Alfenas - Unifal
AEDs I - Prática
Objetivo: implementar uma biblioteca de métodos de ordenação em C++ utilizando exclusivamente ponteiros para manipulação dos elementos dos vetores, sem o uso de índices em nenhuma situação.
*/

#include "ordenacao.h"
#include <iostream>

using namespace std;

// Bubble Sort usando ponteiros
// Percorre o vetor várias vezes, trocando elementos adjacentes se estiverem fora de ordem.
// Não utiliza índices, apenas aritmética de ponteiros.
void bubbleSort(int* begin, int* end) {
    // Ponteiro 'i' percorre do início até o penúltimo elemento
    for (int* i = begin; i < end - 1; ++i) {
        // Ponteiro 'j' percorre do início até o elemento antes do último já ordenado
        for (int* j = begin; j < end - (i - begin) - 1; ++j) {
            // Se o elemento atual é maior que o próximo, troca os valores
            if (*j > *(j + 1)) {
                int temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;
            }
        }
    }
}

// Selection Sort usando ponteiros
// Encontra o menor elemento e o coloca na posição correta, repetindo para o restante do vetor.
// Utiliza apenas ponteiros para percorrer e trocar elementos.
void selectionSort(int* begin, int* end) {
    // Ponteiro 'i' marca a posição atual onde o menor elemento será colocado
    for (int* i = begin; i < end - 1; ++i) {
        int* min = i; // Ponteiro para o menor elemento encontrado
        // Ponteiro 'j' percorre o restante do vetor à procura do menor valor
        for (int* j = i + 1; j < end; ++j) {
            if (*j < *min) {
                min = j; // Atualiza o ponteiro do menor elemento
            }
        }
        // Se encontrou um elemento menor, faz a troca
        if (min != i) {
            int temp = *i;
            *i = *min;
            *min = temp;
        }
    }
}

// Insertion Sort usando ponteiros
// Insere cada elemento na posição correta em relação aos anteriores, deslocando elementos maiores.
// Todo o controle é feito com ponteiros, sem uso de índices.
void insertionSort(int* begin, int* end) {
    // Ponteiro 'i' percorre do segundo elemento até o final
    for (int* i = begin + 1; i < end; ++i) {
        int key = *i;      // Valor a ser inserido na posição correta
        int* j = i - 1;    // Ponteiro para comparar com elementos anteriores
        // Desloca elementos maiores que 'key' uma posição à frente
        while (j >= begin && *j > key) {
            *(j + 1) = *j;
            --j;
        }
        // Insere o valor na posição correta
        *(j + 1) = key;
    }
}
// Função auxiliar para imprimir o vetor usando ponteiros
void printArray(int* begin, int* end) {
    for (int* p = begin; p < end; ++p) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;
}

// Função principal para testar os métodos de ordenação
int main() {
    int vetor[] = {5, 2, 9, 1, 5, 6};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    std::cout << "Vetor original: ";
    printArray(vetor, vetor + tamanho);

    // Testando Bubble Sort
    bubbleSort(vetor, vetor + tamanho);
    std::cout << "Bubble Sort: ";
    printArray(vetor, vetor + tamanho);

    // Reorganizando o vetor para testar Selection Sort
    int vetor2[] = {5, 2, 9, 1, 5, 6};
    selectionSort(vetor2, vetor2 + tamanho);
    std::cout << "Selection Sort: ";
    printArray(vetor2, vetor2 + tamanho);

    // Reorganizando o vetor para testar Insertion Sort
    int vetor3[] = {5, 2, 9, 1, 5, 6};
    insertionSort(vetor3, vetor3 + tamanho);
    std::cout << "Insertion Sort: ";
    printArray(vetor3, vetor3 + tamanho);

    return 0;
}