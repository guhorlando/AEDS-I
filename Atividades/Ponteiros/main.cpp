/*Gustavo Silva Orlando
27/06/2025
Universidade Federal de Alfenas - Unifal
AEDs I - Prática
Objetivo: implementar uma biblioteca com a função de realizar operações em matrizes.
*/

#include "matriz.h"

// Multiplica todos os valores da matriz por um valor
void multiplicarMatriz(Vetor mat, int linhas, int colunas, int valor) {
    int *ptr = &mat[0][0]; // Ponteiro para o primeiro elemento da matriz
    for (int i = 0; i < linhas * colunas; ++i, ++ptr) {
        *ptr *= valor; // Multiplica o valor apontado por ptr
    }
}

// Calcula a matriz transposta
void transporMatriz(Vetor origem, Vetor destino, int linhas, int colunas) {
    // Percorre cada elemento da matriz de origem
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            // Atribui o elemento [i][j] de origem para [j][i] em destino
            *(*(destino + j) + i) = *(*(origem + i) + j);
        }
    }
}

// Inverte as colunas da matriz (horizontalmente)
void inverterColunas(Vetor mat, int linhas, int colunas) {
    for (int i = 0; i < linhas; ++i) {
        int *esq = *(mat + i); // Ponteiro para o início da linha
        int *dir = *(mat + i) + (colunas - 1); // Ponteiro para o final da linha
        // Troca os elementos das extremidades até o meio
        for (int j = 0; j < colunas / 2; ++j, ++esq, --dir) {
            int tmp = *esq;
            *esq = *dir;
            *dir = tmp;
        }
    }
}

// Inverte as linhas da matriz (verticalmente)
void inverterLinhas(Vetor mat, int linhas, int colunas) {
    // Troca as linhas das extremidades até o meio
    for (int i = 0; i < linhas / 2; ++i) {
        int *linha1 = *(mat + i); // Ponteiro para a linha superior
        int *linha2 = *(mat + (linhas - 1 - i)); // Ponteiro para a linha inferior
        for (int j = 0; j < colunas; ++j, ++linha1, ++linha2) {
            int tmp = *linha1;
            *linha1 = *linha2;
            *linha2 = tmp;
        }
    }
}