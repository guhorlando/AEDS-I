#include <iostream>
#include <stdio.h>

using namespace std;

// Listagem do Vetor.
void listaVetor(int v[], int tam) {
    for(int i = 0; i < tam; i++){
        cout << i + 1 << "º valor:" << " " << v[i] << endl;
    }
    fflush(NULL);
}

// Declaração do Insertion Sort.
void insertion(int v[], int tam){
    int i, j, aux;
    for(i = 1; i < tam; i++){
        aux = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > aux){
            v[j+1] = v[j];
            j = j - 1;
        }
        v[j+1] = aux;        
    }
}