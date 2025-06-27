// ...cabeçalho omitido...

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int MAX_IMOVEIS = 200;

// Estrutura que representa um imóvel com todos os campos necessários
struct Imovel
{
    string tipo, finalidade, endereco, bairro, cidade, cozinha, sala, varanda, area_de_servico, conservacao, armarios, ar_condicionado, aquecedor, ventilador, piso;
    int area, valor, iptu, quartos, suites, banheiros, vagas;
};

// Função para ler os imóveis do arquivo e preencher o vetor
int lerImoveis(Imovel imoveis[], int max)
{
    ifstream arquivo("BD_Imoveis2.txt");
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
        return 0;
    }

    string cabecalho;
    getline(arquivo, cabecalho); // Ignora o cabeçalho

    int n = 0;
    while (n < max)
    {
        arquivo >> imoveis[n].tipo;
        if (imoveis[n].tipo == "fim")
            break;
        // Lê todos os campos do imóvel
        arquivo >> imoveis[n].finalidade >> imoveis[n].endereco >> imoveis[n].bairro >> imoveis[n].cidade >> imoveis[n].area >> imoveis[n].valor >> imoveis[n].iptu >> imoveis[n].quartos >> imoveis[n].suites >> imoveis[n].banheiros >> imoveis[n].vagas >> imoveis[n].cozinha >> imoveis[n].sala >> imoveis[n].varanda >> imoveis[n].area_de_servico >> imoveis[n].piso >> imoveis[n].conservacao >> imoveis[n].armarios >> imoveis[n].ar_condicionado >> imoveis[n].aquecedor >> imoveis[n].ventilador;
        n++;
    }
    arquivo.close();
    return n; // Retorna a quantidade de imóveis lidos
}

// Função para adicionar um novo imóvel ao vetor
void adicionarImovel(Imovel imoveis[], int &nImoveis)
{
    if (nImoveis >= MAX_IMOVEIS)
    {
        cout << "Base de dados cheia!\n";
        return;
    }

    // Coleta os dados do novo imóvel
    cout << "Digite o tipo: ";
    cin >> imoveis[nImoveis].tipo;

    cout << "Digite a finalidade: ";
    cin >> imoveis[nImoveis].finalidade;

    cout << "Digite o endereço: ";
    cin.ignore();
    getline(cin, imoveis[nImoveis].endereco);

    cout << "Digite o bairro: ";
    getline(cin, imoveis[nImoveis].bairro);

    cout << "Digite o cidade: ";
    getline(cin, imoveis[nImoveis].cidade);

    cout << "Digite o area: ";
    cin >> imoveis[nImoveis].area;

    cout << "Digite o valor: ";
    cin >> imoveis[nImoveis].valor;

    cout << "Digite o IPTU: ";
    cin >> imoveis[nImoveis].iptu;

    cout << "Digite quantos quartos: ";
    cin >> imoveis[nImoveis].quartos;

    cout << "Digite quantas suites: ";
    cin >> imoveis[nImoveis].suites;

    cout << "Digite quantos banheiros: ";
    cin >> imoveis[nImoveis].banheiros;

    cout << "Digite quantas vagas: ";
    cin >> imoveis[nImoveis].vagas;

    cout << "Possui cozinha: ";
    cin >> imoveis[nImoveis].cozinha;

    cout << "Possui sala: ";
    cin >> imoveis[nImoveis].sala;

    cout << "Possui varanda: ";
    cin >> imoveis[nImoveis].varanda;

    cout << "Possui área de serviço: ";
    cin >> imoveis[nImoveis].area_de_servico;

    cout << "Tipo de piso: ";
    cin >> imoveis[nImoveis].piso;

    cout << "Estado de conservação: ";
    cin >> imoveis[nImoveis].conservacao;

    cout << "Possui armários: ";
    cin >> imoveis[nImoveis].armarios;

    cout << "Possui ar-condicionado: ";
    cin >> imoveis[nImoveis].ar_condicionado;

    cout << "Possui aquecedor: ";
    cin >> imoveis[nImoveis].aquecedor;

    cout << "Possui ventilador: ";
    cin >> imoveis[nImoveis].ventilador;

    nImoveis++; // Incrementa o número de imóveis cadastrados
    cout << "Imóvel adicionado!\n";
}

// Função para salvar todos os imóveis no arquivo
void salvarImoveis(Imovel imoveis[], int nImoveis)
{
    ofstream arquivo("BD_Imoveis2.txt");
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
        return;
    }

    // Escreve o cabeçalho
    arquivo << "Tipo Finalidade Endereço Bairro Cidade Área Valor IPTU Quartos Suítes Banheiros Vagas Cozinha Sala Varanda Área_de_Serviço Piso Conservação Armários Ar-condicionado Aquecedor Ventilador" << endl;

    // Salva apenas os imóveis válidos
    for (int i = 0; i < nImoveis; i++)
    {
        arquivo << imoveis[i].tipo << " ";
        arquivo << imoveis[i].finalidade << " ";
        arquivo << imoveis[i].endereco << " ";
        arquivo << imoveis[i].bairro << " ";
        arquivo << imoveis[i].cidade << " ";
        arquivo << imoveis[i].area << " ";
        arquivo << imoveis[i].valor << " ";
        arquivo << imoveis[i].iptu << " ";
        arquivo << imoveis[i].quartos << " ";
        arquivo << imoveis[i].suites << " ";
        arquivo << imoveis[i].banheiros << " ";
        arquivo << imoveis[i].vagas << " ";
        arquivo << imoveis[i].cozinha << " ";
        arquivo << imoveis[i].sala << " ";
        arquivo << imoveis[i].varanda << " ";
        arquivo << imoveis[i].area_de_servico << " ";
        arquivo << imoveis[i].piso << " ";
        arquivo << imoveis[i].conservacao << " ";
        arquivo << imoveis[i].armarios << " ";
        arquivo << imoveis[i].ar_condicionado << " ";
        arquivo << imoveis[i].aquecedor << " ";
        arquivo << imoveis[i].ventilador << " " << endl;
    }
    arquivo.close();
}

// Função utilitária para converter espaços em underline (usada na busca)
string espacoParaUnderline(string texto)
{
    for (size_t i = 0; i < texto.size(); i++)
    {
        if (texto[i] == ' ')
            texto[i] = '_';
    }
    return texto;
}

int main()
{
    Imovel imoveis[MAX_IMOVEIS];
    int nImoveis = lerImoveis(imoveis, MAX_IMOVEIS); // Lê imóveis do arquivo ao iniciar

    int opcao = -1; // Inicializa a variável de opção do menu
    do
    {
        // Exibe o menu principal
        cout << "\nMenu de Opções:\n";
        cout << "0. Sair\n";
        cout << "1. Inclusão de um novo imóvel na base de dados\n";
        cout << "2. Busca de um imóvel pela rua, e se encontrado, permitir a exclusão da base de dados\n";
        cout << "3. Busca de imóveis por uma faixa de valores para locação, aluguel  ou  temporada\n";
        cout << "4. Busca de imóveis pelas características: armários, ar-condicionado, aquecedor e ventilador\n";
        cout << "5. Busca de imóveis pelo número de quartos e suítes\n";
        cout << "6. Relatório de estatísticas: porcentagens de imóveis por finalidade, porcentagens de casas com suítes, porcentagem de pisos com cerâmica nas salas comerciais\n";
        cout << "7. Listagem de todos os imóveis disponíveis\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 0:
        {
            // Salva os imóveis antes de sair
            salvarImoveis(imoveis, nImoveis);
            cout << "Saindo do programa..." << endl;
            break;
        }
        case 1:
        {
            // Adiciona um novo imóvel
            adicionarImovel(imoveis, nImoveis);
            break;
        }
        case 2:
        {
            // Busca e possível exclusão de imóvel pelo endereço
            string ruaBusca;
            cout << "Digite o endereço (rua) do imóvel que deseja buscar (separe os nomes por underline (_)): ";
            cin.ignore();
            getline(cin, ruaBusca);

            bool encontrado = false;
            for (int i = 0; i < nImoveis; i++)
            {
                if (imoveis[i].endereco == espacoParaUnderline(ruaBusca))
                {
                    encontrado = true;
                    cout << "\nImóvel encontrado!\n";
                    cout << "Tipo: " << imoveis[i].tipo << endl;
                    cout << "Finalidade: " << imoveis[i].finalidade << endl;
                    cout << "Endereço: " << imoveis[i].endereco << endl;
                    cout << "Bairro: " << imoveis[i].bairro << endl;
                    cout << "Cidade: " << imoveis[i].cidade << endl;

                    char confirma;
                    cout << "Deseja excluir este imóvel? (s/n): ";
                    cin >> confirma;
                    if (confirma == 's' || confirma == 'S')
                    {
                        // Remove o imóvel deslocando os próximos para trás
                        for (int j = i; j < nImoveis - 1; j++)
                        {
                            imoveis[j] = imoveis[j + 1];
                        }
                        nImoveis--;
                        cout << "Imóvel excluído!\n";
                    }
                    break; // Para após encontrar o primeiro imóvel
                }
            }
            if (!encontrado)
            {
                cout << "Imóvel não encontrado!\n";
            }
            break;
        }
        case 3:
        {
            // Busca imóveis por faixa de valor
            int valorMin, valorMax;
            cout << "Digite o valor mínimo: ";
            cin >> valorMin;
            cout << "Digite o valor máximo: ";
            cin >> valorMax;

            bool encontrou = false;
            for (int i = 0; i < nImoveis; i++)
            {
                if (imoveis[i].valor >= valorMin && imoveis[i].valor <= valorMax)
                {
                    encontrou = true;
                    cout << "\nImóvel encontrado:\n";
                    cout << "Tipo: " << imoveis[i].tipo << endl;
                    cout << "Finalidade: " << imoveis[i].finalidade << endl;
                    cout << "Endereço: " << imoveis[i].endereco << endl;
                    cout << "Bairro: " << imoveis[i].bairro << endl;
                    cout << "Cidade: " << imoveis[i].cidade << endl;
                    cout << "Valor: " << imoveis[i].valor << endl;
                }
            }
            if (!encontrou)
            {
                cout << "Nenhum imóvel encontrado na faixa de valores informada.\n";
            }
            break;
        }
        case 4:
        {
            // Busca imóveis por características
            string buscaArmarios, buscaArCond, buscaAquecedor, buscaVentilador;

            cout << "O imóvel deve ter armários? (sim/nao): ";
            cin >> buscaArmarios;
            cout << "O imóvel deve ter ar-condicionado? (sim/nao): ";
            cin >> buscaArCond;
            cout << "O imóvel deve ter aquecedor? (sim/nao): ";
            cin >> buscaAquecedor;
            cout << "O imóvel deve ter ventilador? (sim/nao): ";
            cin >> buscaVentilador;

            bool encontrou = false;
            for (int i = 0; i < nImoveis; i++)
            {
                if ((imoveis[i].armarios == buscaArmarios || buscaArmarios == "tanto-faz") &&
                    (imoveis[i].ar_condicionado == buscaArCond || buscaArCond == "tanto-faz") &&
                    (imoveis[i].aquecedor == buscaAquecedor || buscaAquecedor == "tanto-faz") &&
                    (imoveis[i].ventilador == buscaVentilador || buscaVentilador == "tanto-faz"))
                {
                    encontrou = true;
                    cout << "\nImóvel encontrado:\n";
                    cout << "Tipo: " << imoveis[i].tipo << endl;
                    cout << "Finalidade: " << imoveis[i].finalidade << endl;
                    cout << "Endereço: " << imoveis[i].endereco << endl;
                    cout << "Bairro: " << imoveis[i].bairro << endl;
                    cout << "Cidade: " << imoveis[i].cidade << endl;
                }
            }
            if (!encontrou)
            {
                cout << "Nenhum imóvel encontrado com as características informadas.\n";
            }
            break;
        }
        case 5:
        {
            // Busca imóveis por número de quartos e suítes
            int buscaQuartos, buscaSuites;
            cout << "Digite o número de quartos desejado: ";
            cin >> buscaQuartos;
            cout << "Digite o número de suítes desejado: ";
            cin >> buscaSuites;

            bool encontrou = false;
            for (int i = 0; i < nImoveis; i++)
            {
                if (imoveis[i].quartos == buscaQuartos && imoveis[i].suites == buscaSuites)
                {
                    encontrou = true;
                    cout << "\nImóvel encontrado:\n";
                    cout << "Tipo: " << imoveis[i].tipo << endl;
                    cout << "Finalidade: " << imoveis[i].finalidade << endl;
                    cout << "Endereço: " << imoveis[i].endereco << endl;
                    cout << "Bairro: " << imoveis[i].bairro << endl;
                    cout << "Cidade: " << imoveis[i].cidade << endl;
                    cout << "Quartos: " << imoveis[i].quartos << endl;
                    cout << "Suítes: " << imoveis[i].suites << endl;
                }
            }
            if (!encontrou)
            {
                cout << "Nenhum imóvel encontrado com a quantidade de quartos e suítes informada.\n";
            }
            break;
        }
        case 6:
        {
            // Relatório de estatísticas
            int total = nImoveis;
            int contVenda = 0, contLocacao = 0, contTemporada = 0;
            int contCasas = 0, contCasasComSuite = 0;
            int contSalasComercial = 0, contSalasComCeramica = 0;

            for (int i = 0; i < nImoveis; i++)
            {
                // Conta imóveis por finalidade
                if (imoveis[i].finalidade == "venda")
                    contVenda++;
                else if (imoveis[i].finalidade == "locacao")
                    contLocacao++;
                else if (imoveis[i].finalidade == "temporada")
                    contTemporada++;

                // Conta casas com suíte
                if (imoveis[i].tipo == "casa")
                {
                    contCasas++;
                    if (imoveis[i].suites > 0)
                        contCasasComSuite++;
                }

                // Conta salas comerciais com piso cerâmico
                if (imoveis[i].tipo == "sala_comercial")
                {
                    contSalasComercial++;
                    if (imoveis[i].piso == "ceramica")
                        contSalasComCeramica++;
                }
            }

            cout << fixed << setprecision(2);

            // Exibe estatísticas
            cout << "\nPorcentagem de imóveis por finalidade:\n";
            cout << "Venda: " << (total ? (contVenda * 100.0 / total) : 0) << "%\n";
            cout << "Locação: " << (total ? (contLocacao * 100.0 / total) : 0) << "%\n";
            cout << "Temporada: " << (total ? (contTemporada * 100.0 / total) : 0) << "%\n";

            cout << "\nPorcentagem de casas com suíte: ";
            cout << (contCasas ? (contCasasComSuite * 100.0 / contCasas) : 0) << "%\n";

            cout << "\nPorcentagem de salas comerciais com piso cerâmico: ";
            cout << (contSalasComercial ? (contSalasComCeramica * 100.0 / contSalasComercial) : 0) << "%\n";

            break;
        }
        case 7:
        {
            // Lista todos os imóveis cadastrados
            if (nImoveis == 0)
            {
                cout << "Nenhum imóvel cadastrado.\n";
            }
            else
            {
                cout << "\nLista de imóveis disponíveis:\n";
                for (int i = 0; i < nImoveis; i++)
                {
                    cout << "\nImóvel " << (i + 1) << ":\n";
                    cout << "Tipo: " << imoveis[i].tipo << endl;
                    cout << "Finalidade: " << imoveis[i].finalidade << endl;
                    cout << "Endereço: " << imoveis[i].endereco << endl;
                    cout << "Bairro: " << imoveis[i].bairro << endl;
                    cout << "Cidade: " << imoveis[i].cidade << endl;
                    cout << "Área: " << imoveis[i].area << endl;
                    cout << "Valor: " << imoveis[i].valor << endl;
                    cout << "IPTU: " << imoveis[i].iptu << endl;
                    cout << "Quartos: " << imoveis[i].quartos << endl;
                    cout << "Suítes: " << imoveis[i].suites << endl;
                    cout << "Banheiros: " << imoveis[i].banheiros << endl;
                    cout << "Vagas: " << imoveis[i].vagas << endl;
                    cout << "Cozinha: " << imoveis[i].cozinha << endl;
                    cout << "Sala: " << imoveis[i].sala << endl;
                    cout << "Varanda: " << imoveis[i].varanda << endl;
                    cout << "Área de serviço: " << imoveis[i].area_de_servico << endl;
                    cout << "Piso: " << imoveis[i].piso << endl;
                    cout << "Conservação: " << imoveis[i].conservacao << endl;
                    cout << "Armários: " << imoveis[i].armarios << endl;
                    cout << "Ar-condicionado: " << imoveis[i].ar_condicionado << endl;
                    cout << "Aquecedor: " << imoveis[i].aquecedor << endl;
                    cout << "Ventilador: " << imoveis[i].ventilador << endl;
                }
            }
            break;
        }
        }
    } while (opcao != 0);

    return 0;
}