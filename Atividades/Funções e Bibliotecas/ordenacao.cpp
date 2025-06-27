#include <iostream>
#include <stdio.h>

using namespace std;

// Listagem do Vetor
void listaVetor(int v[], int tam) {
    for(int i = 0; i < tam; i++){
        cout << i + 1 << "º valor:" << " " << v[i] << endl;
    }
    fflush(NULL);
}

// Declaração do BubbleSort.
void bubblesort(int v[], int tam){
    int i, j, aux;
    for(i = tam - 1; i > 0; i--){
        for (j = 0; j < i; j++){
        if (v[j] > v[j+1]){ // Se V, troca os valores.
            aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
        
            }
        }
    }
}