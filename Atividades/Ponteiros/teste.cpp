/*Gustavo Silva Orlando
27/06/2025
Universidade Federal de Alfenas - Unifal
AEDs I - Prática
Objetivo: implementar uma biblioteca com a função de realizar operações em matrizes.
*/

#include "matriz.h"
#include <iostream>

using namespace std;

int main() {
    Vetor mat = {0};      // Matriz original
    Vetor transposta = {0}; // Matriz para armazenar a transposta
    int linhas = 3, colunas = 4;

    // Preenche a matriz com valores sequenciais para facilitar a visualização
    int valor = 1;
    for (int i = 0; i < linhas; ++i)
        for (int j = 0; j < colunas; ++j)
            mat[i][j] = valor++;

    // Exibe a matriz original
    cout << "Matriz original:" << endl;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j)
            cout << mat[i][j] << "\t";
        cout << endl;
    }

    // Multiplica todos os valores por 2
    multiplicarMatriz(mat, linhas, colunas, 2);
    cout << "\nMatriz após multiplicar por 2:" << endl;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j)
            cout << mat[i][j] << "\t";
        cout << endl;
    }

    // Calcula a transposta
    transporMatriz(mat, transposta, linhas, colunas);
    cout << "\nMatriz transposta:" << endl;
    for (int i = 0; i < colunas; ++i) {
        for (int j = 0; j < linhas; ++j)
            cout << transposta[i][j] << "\t";
        cout << endl;
    }

    // Inverte as colunas da matriz original
    inverterColunas(mat, linhas, colunas);
    cout << "\nMatriz após inverter colunas:" << endl;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j)
            cout << mat[i][j] << "\t";
        cout << endl;
    }

    // Inverte as linhas da matriz original
    inverterLinhas(mat, linhas, colunas);
    cout << "\nMatriz após inverter linhas:" << endl;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j)
            cout << mat[i][j] << "\t";
        cout << endl;
    }

    return 0;
}