#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    const int TAM = 20;

    ifstream arquivo("entrada.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return 1;
    }

    int v[TAM];
    int unicos[TAM];
    int qtdUnicos = 0;
    int i = 0;

    for (int i = 0; i < TAM; i++) {
        arquivo >> v[i]; 
    }


    cout << "Valores do vetor: ";
    for (int j = 0; j < TAM; j++) {
        cout << v[j] << " ";
    }
    cout << endl;
            

    for (int i = 0; i < TAM; i++) {
        int jaExiste = 0;
        for (int j = 0; j < qtdUnicos; j++) {
            if (v[i] == unicos[j]) {
                jaExiste = 1;
                break;
            }
        }
        if (jaExiste == 0) {
            unicos[qtdUnicos] = v[i];
            qtdUnicos++;
        }
    }

    
    cout << "Valores sem repetição: ";
    for (int i = 0; i < qtdUnicos; i++) {
        cout << unicos[i] << " ";
    }
    cout << endl; 

    int outroVetor[TAM];
    for (int i = 0; i < qtdUnicos; i++) {
    outroVetor[i] = unicos[i];
    }

    // Ordena outroVetor em ordem crescente (bubble sort)
    for (int i = 0; i < qtdUnicos - 1; i++) {
        for (int j = 0; j < qtdUnicos - 1 - i; j++) {
            if (outroVetor[j] > outroVetor[j + 1]) {
                int temp = outroVetor[j];
                outroVetor[j] = outroVetor[j + 1];
                outroVetor[j + 1] = temp;
            }
        }
    }

    cout << "Outro vetor sem repetição: ";
    for (int i = 0; i < qtdUnicos; i++) {
    cout << outroVetor[i] << " ";
    }
    cout << endl;

    return 0;
}