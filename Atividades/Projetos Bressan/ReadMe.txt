Projeto: Sistema de Cadastro e Consulta de Imóveis

Descrição:
Este projeto é um sistema em C++ para cadastro, consulta, exclusão e geração de relatórios de imóveis residenciais e comerciais. Os dados são armazenados em um arquivo texto ("BD_Imoveis2.txt") e o sistema permite diversas operações sobre a base de imóveis.

Funcionalidades principais:
- Inclusão de novos imóveis
- Busca de imóvel pelo endereço (com possibilidade de exclusão)
- Busca por faixa de valores
- Busca por características (armários, ar-condicionado, aquecedor, ventilador)
- Busca por número de quartos e suítes
- Relatórios estatísticos
- Listagem de todos os imóveis cadastrados

Como utilizar:
1. Compile o arquivo `main.cpp` usando um compilador C++ (exemplo: `g++ main.cpp -o main.exe`).
2. Execute o programa (`main.exe` no Windows).
3. O menu será exibido no terminal. Digite o número da opção desejada e siga as instruções.
4. Para cadastrar ou buscar imóveis, digite as informações solicitadas. Para endereços, utilize espaços normalmente; o sistema converte automaticamente para o padrão do arquivo.
5. Ao sair do programa (opção 0), os dados serão salvos automaticamente no arquivo `BD_Imoveis2.txt`.

Observações:
- O arquivo de dados deve estar na mesma pasta do executável.
- Não edite o arquivo de dados manualmente para evitar corromper a base.
- Para buscas por endereço, digite o nome da rua/avenida com espaços (ex: "Rua das Flores").
