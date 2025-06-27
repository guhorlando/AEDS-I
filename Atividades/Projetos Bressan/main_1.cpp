/*Gustavo Silva Orlando;
21/05/2025
Universidade Federal de Alfenas - Unifal
AEDs I - Prática
Objetivo: realizar operações nos valores armazenados num vetor.
*/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    const int TAM = 100;

    ifstream arquivo("valores.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return 1;
    }

    int valores[TAM], media, soma = 0;
    int i = 0;

    while (i < TAM && arquivo >> valores[i]) {
        soma += valores[i];
        i++;
    }

    arquivo.close();

    int opcao = -1; // Inicializar a variável "opcao".
    do {
        // Exibir o menu de opções.
        cout << "\nMenu de Opções:\n";
        cout << "0. Sair\n";
        cout << "1. Exibir todos os valores do vetor\n";
        cout << "2. Contar a quantidade de ocorrências que um valor aparece\n";
        cout << "3. Contar a quantidade de ocorrências de valores de um intervalo\n";
        cout << "4. Buscar pela primeira ocorrência de um valor e informar a posição\n";
        cout << "5. Excluir a primeira ocorrência de um valor informado, se existir, deslocando os valores da direita para esquerda\n";
        cout << "6. Inserir um valor informado numa posição também informada, quando o vetor não estiver cheio\n";
        cout << "7. Retirar todos os valores repetidos\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 0: {
                // Sair do programa.
                cout << "Saindo do programa..." << endl;
                break;
            }

            case 1: {
                // Exibir todos os valores do vetor.
                cout << "Valores do vetor: ";
                for (int j = 0; j < i; j++) {
                    cout << valores[j] << " ";
                }
                cout << endl;
                break;
            }

            case 2: {
                // Contar a quantidade de ocorrências de um valor informado pelo usuário.
                int valorBusca, cont = 0;
                cout << "Digite o valor que deseja buscar: ";
                cin >> valorBusca;

                // Percorre o vetor e conta as ocorrências do valor.
                for (int j = 0; j < i; j++) {
                    if (valores[j] == valorBusca) {
                        cont++;
                    }
                }

                cout << "O valor " << valorBusca << " aparece " << cont << " vez(es) no vetor." << endl;
                break;
            }

            case 3: {
                // Contar a quantidade de ocorrências de valores dentro de um intervalo informado pelo usuário.
                int inicio, fim, cont = 0;
                cout << "Digite o valor inicial do intervalo: ";
                cin >> inicio;
                cout << "Digite o valor final do intervalo: ";
                cin >> fim;

                // Percorre o vetor e conta quantos valores estão dentro do intervalo [inicio, fim].
                for (int j = 0; j < i; j++) {
                    if (valores[j] >= inicio && valores[j] <= fim) {
                        cont++;
                    }
                }

                cout << "Existem " << cont << " valor(es) no intervalo de " << inicio << " até " << fim << " no vetor." << endl;
                break;
            }

            case 4: {
            // Buscar pela primeira ocorrência de um valor e informar a posição.
            int valorBusca, pos = -1;
            cout << "Digite o valor que deseja buscar: ";
            cin >> valorBusca;

            // Percorre o vetor procurando a primeira ocorrência.
            for (int j = 0; j < i; j++) {
                if (valores[j] == valorBusca) {
                    pos = j; // Guarda a posição da primeira ocorrência.
                    break;   // Sai do loop ao encontrar.
                }
            }

            if (pos != -1) {
                // Se encontrou o valor, informa a posição da primeira ocorrência.
                cout << "O valor " << valorBusca << " foi encontrado na posição " << pos << " do vetor." << endl;
            } else {
                // Se não encontrou o valor, informa que não está presente no vetor.
                cout << "O valor " << valorBusca << " não foi encontrado no vetor." << endl;
            }
            break;  
            }

            case 5: {
                // Excluir a primeira ocorrência de um valor informado, se existir, deslocando os valores da direita para esquerda.
                int valorExclui, pos = -1;
                cout << "Digite o valor que deseja excluir: ";
                cin >> valorExclui;

                // Procurar a posição da primeira ocorrência.
                for (int j = 0; j < i; j++) {
                    if (valores[j] == valorExclui) {
                        pos = j;
                        break;
                    }
                }

                if (pos != -1) {
                    // Deslocar os elementos à direita para a esquerda.
                    for (int j = pos; j < i - 1; j++) {
                        valores[j] = valores[j + 1];
                    }
                    i--; // Reduz o tamanho lógico do vetor.
                    cout << "Valor " << valorExclui << " excluído com sucesso." << endl;
                } else {
                    cout << "Valor não encontrado no vetor." << endl;
                }
                break;
            }

            case 6: {
            //Inserir um valor em uma determinada posição.
                if (i < TAM) {
                int pos;
                float valor;
                // Solicita ao usuário a posição onde deseja inserir o valor.
                cout << "Digite a posição (0 a " << i << ") para inserir o valor: ";
                cin >> pos;
                // Verifica se a posição informada é válida.
            if (pos >= 0 && pos <= i) {
                // Solicita ao usuário o valor a ser inserido.
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;
                for (int j = i; j > pos; j--) {
                    valores[j] = valores[j - 1];
                }
                // Insere o valor na posição informada.
                valores[pos] = valor;
                i++; // Atualiza o tamanho lógico do vetor.
                // Exibe o vetor atualizado.
                cout << "Valor inserido!\nVetor atualizado: ";
                for (int j = 0; j < i; j++) {
                    cout << valores[j] << " ";
                }
                cout << endl;
            } else {
                cout << "Posição inválida!" << endl;
            }
        } else {
            cout << "O vetor está cheio! Não é possível inserir mais valores." << endl;
        }
        break;
            }

            case 7: {
            //Remover todos os valores repetidos.
            // Para cada elemento do vetor, verifica se há outro igual à frente.
            for (int j = 0; j < i; j++) {
            for (int k = j + 1; k < i; ) {
                // Se encontrar um valor repetido.
                if (valores[j] == valores[k]) {
                    // Desloca todos os elementos à direita para a esquerda, sobrescrevendo o repetido.
                    for (int l = k; l < i - 1; l++) {
                        valores[l] = valores[l + 1];
                    }
                    i--;
                    // Reduz o tamanho lógico do vetor.
                // Não incrementa k, pois o novo valor em k precisa ser verificado.
                } else {
                    k++; // Só incrementa k se não houve remoção.
                }
            }
        }
         // Exibe o vetor atualizado, agora sem valores repetidos.
        cout << "Valores repetidos removidos!\nVetor atualizado: ";
        for (int j = 0; j < i; j++) {
            cout << valores[j] << " ";
        }
        cout << endl;
        break;
            }
        }
    } while (opcao != 0);

    return 0;
}