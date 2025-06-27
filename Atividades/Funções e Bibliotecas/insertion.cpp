#include <iostream>
#include <stdio.h>
#include "ordenacao.h"

using namespace std;

void listaVetor (int v[], int tam);

// Assinatura do Insertion Sort.
void insertion (int v[], int tam);


int main (int argc, char** argv) {
    int i, j, aux;
    int aleat[] = {10, 20, 24, 78, 5, 3, 95, 15, 42, 88};
    int vCres[] = {3, 5, 10, 15, 20, 24, 42, 78, 88, 95};
    int vDecre[] = {95, 88, 78, 42, 24, 20, 15, 10, 5, 3};

    cout << endl << "Vetor antes da ordenação" << endl;
    //Lista os valores na tela antes de ordenar.
    listaVetor(aleat, 10);

    // Chamada da função Insertion Sort.
    insertion(aleat, 10);

    cout << endl << "Vetor depois da ordenação" << endl;
    // Lista valores na tela depois da ordenação.
    listaVetor(aleat, 10);

    cout << endl << "Vetor antes da ordenação" << endl;
    //Lista os valores na tela antes de ordenar.
    listaVetor(vCres, 10);

    // Chamada da função Insertion Sort.
    insertion(vCres, 10);

    cout << endl << "Vetor depois da ordenação" << endl;
    // Lista valores na tela depois da ordenação.
    insertion(vCres, 10);

    cout << endl << "Vetor antes da ordenação" << endl;
    //Lista os valores na tela antes de ordenar.
    listaVetor(vDecre, 10);

    // Chamada da função Insertion Sort.
    insertion(vDecre, 10);

    cout << endl << "Vetor depois da ordenação" << endl;
    // Lista valores na tela depois da ordenação.
    listaVetor(vDecre, 10);
    return 0;
}