/*Gustavo Silva Orlando
27/06/2025
Universidade Federal de Alfenas - Unifal
AEDs I - Prática
Objetivo: implementar uma biblioteca com a função de realizar operações em matrizes.
*/

#ifndef MATRIZ_H
#define MATRIZ_H

const int TAM = 128; // Define o tamanho máximo das matrizes
typedef int Vetor[TAM][TAM]; // Define o tipo Vetor como uma matriz 2D de inteiros

// Multiplica todos os elementos da matriz por um valor
void multiplicarMatriz(Vetor mat, int linhas, int colunas, int valor);

// Calcula a matriz transposta de 'origem' e armazena em 'destino'
void transporMatriz(Vetor origem, Vetor destino, int linhas, int colunas);

// Inverte as colunas da matriz (horizontalmente)
void inverterColunas(Vetor mat, int linhas, int colunas);

// Inverte as linhas da matriz (verticalmente)
void inverterLinhas(Vetor mat, int linhas, int colunas);

#endif // MATRIZ_H