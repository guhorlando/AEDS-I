/*Gustavo Silva Orlando;
28/03/2025
Universidade Federeal de ALfenas - Unifal
AEDs I - Prática
Objetivo: Classificar um candidato à uma vaga de emprego com base em sua idade, nível de escolaridade, anos de experiência da área e quantas certificações tem*/

#include <stdio.h>

int main (){

    int idade, escolaridade, nenhuma, ensino_medio, ensino_superior, pos_graduacao, anos_de_experiencia, numero_de_certificacoes;
    
    //Na entrada do código, serão necessários dados do usuário, como:
    //Idade;
    //Escolaridade;
    //Anos de experiência;
    //Quantidade de certifições que possui na área.

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite sua escolaridade: ");
    scanf("%d", &escolaridade);
    nenhuma = 0;
    ensino_medio = 1;
    ensino_superior = 2;
    pos_graduacao = 3;

    printf("Digite quantos anos de experiência na área tem: ");
    scanf("%d", &anos_de_experiencia);

    printf("Digite quantas certificações possui: ");
    scanf("%d", &numero_de_certificacoes);


    //No processamento do código, a partir dos dados que o ususário fornecer, haverão as seguintes classificações para ele:
    //Candidato Rejeitado: não for maior de idade, sem escolaridade mínima (ensino médio) ou apenas possuir 1 ano de experência da área sem nenhuma certificação;
    //Candidato Júnior: maior de idade, possuir ensino médio completo, pelo menos 1 ano de experiência ou 1 certificação na área;
    //Candidato Pleno: maior de idade, ensino superior completo e pelo menos 3 anos de experiência na área ou pelo menos um 1 ano de experiência na área mas com duas ou mais certificações;
    //Candidato Sênior: maior de idade, ensino superior completo, pelo menos 5 anos de experiência na área, pelo menos uma certificação ou possuir uma pòs graduação e pelo menos 3 anos de experiência.
    
    
    if (idade < 18 || escolaridade == 0 || (anos_de_experiencia < 1 && numero_de_certificacoes == 0)){
        printf("Candidato Rejeitado!");
    } else {
        if ((idade >= 18 && escolaridade == 1 && anos_de_experiencia >= 1) || numero_de_certificacoes == 1){
            printf("Candidato Júnior!");
        } else {
            if ((idade >= 18 && escolaridade == 2 && anos_de_experiencia >= 5 && numero_de_certificacoes >= 1) || (escolaridade == 3 && anos_de_experiencia >= 3)){
                printf("Candidato Sênior!");
            } else {
                if ((idade >= 18 && escolaridade == 2 && anos_de_experiencia >= 3) || anos_de_experiencia >= 1 || numero_de_certificacoes > 2){
                     printf("Candidato Pleno!");
                } else {
                    printf("Não há classificação para esse candidato!");
                }
            }
        }
    }

   
    return 0;
}