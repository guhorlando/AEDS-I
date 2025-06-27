#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_AMIGOS = 20;

struct Tamigo {
    string nome;
    string cidade;
    long long celular;
    string email;
};

// Função para salvar a agenda no arquivo
void salvarAgenda(Tamigo agenda[], int quantidade) {
    ofstream arquivo("agenda.txt");

    for (int i = 0; i < quantidade; i++) {
        arquivo << agenda[i].nome << " "
                << agenda[i].cidade << " "
                << agenda[i].celular << " "
                << agenda[i].email << endl;
    }

    arquivo.close();
    cout << "Agenda salva no arquivo.\n";
}

// Função para carregar a agenda do arquivo
int carregarAgenda(Tamigo agenda[]) {
    ifstream arquivo("agenda.txt");
    int quantidade = 0;

    while (arquivo >> agenda[quantidade].nome
                   >> agenda[quantidade].cidade
                   >> agenda[quantidade].celular
                   >> agenda[quantidade].email) {
        quantidade++;
        if (quantidade >= MAX_AMIGOS) break;
    }

    arquivo.close();
    return quantidade;
}

// Função para adicionar um amigo à agenda
void adicionarAmigo(Tamigo agenda[], int &quantidade) {
    if (quantidade >= MAX_AMIGOS) {
        cout << "Agenda cheia!\n";
        return;
    }

    cout << "Digite o nome: ";
    cin >> agenda[quantidade].nome;

    cout << "Digite a cidade: ";
    cin >> agenda[quantidade].cidade;

    cout << "Digite o celular: ";
    cin >> agenda[quantidade].celular;

    cout << "Digite o email: ";
    cin >> agenda[quantidade].email;

    quantidade++;
    cout << "Amigo adicionado!\n";
}

string substituirUnderscorePorEspaco(const string& texto) {
    string resultado = texto;
    for (char& c : resultado) {
        if (c == '_') c = ' ';
    }
    return resultado;
}

// Função para listar os amigos
void listarAmigos(Tamigo agenda[], int quantidade) {
    if (quantidade == 0) {
        cout << "Agenda vazia.\n";
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        cout << "\nAmigo " << i + 1 << ":\n";
        cout << "Nome: " << substituirUnderscorePorEspaco(agenda[i].nome) << endl;
        cout << "Cidade: " << substituirUnderscorePorEspaco(agenda[i].cidade) << endl;
        cout << "Celular: " << agenda[i].celular << endl;
        cout << "Email: " << substituirUnderscorePorEspaco(agenda[i].email) << endl;
    }
}

int main() {
    Tamigo agenda[MAX_AMIGOS];
    int quantidade = carregarAgenda(agenda);
    int opcao = 0;

    while (opcao != 3) {
        cout << "\nMenu:\n";
        cout << "1. Adicionar amigo\n";
        cout << "2. Listar amigos\n";
        cout << "3. Salvar e sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            adicionarAmigo(agenda, quantidade);
        }
        else if (opcao == 2) {
            listarAmigos(agenda, quantidade);
        }
        else if (opcao == 3) {
            salvarAgenda(agenda, quantidade);
            cout << "Saindo...\n";
        }
        else {
            cout << "Opcao invalida.\n";
        }
    }

    return 0;
}