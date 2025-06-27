#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

int main () {
    char nome[30], sobrenome[30], nomecompleto[60];

    nome[0]='G';
    nome[1]='u';
    nome[2]='s';
    nome[3]='t';
    nome[4]='a';
    nome[5]='v';
    nome[6]='o';
    nome[7]='\0';

    printf("Nome: %s.", nome);

    sobrenome[0]='O';
    sobrenome[1]='r';
    sobrenome[2]='l';
    sobrenome[3]='a';
    sobrenome[4]='n';
    sobrenome[5]='d';
    sobrenome[6]='o';

    printf("\nSobrenome: %s.", sobrenome);

    strcpy(nomecompleto, nome);
    strcat(nomecompleto, " ");
    strcat(nomecompleto, sobrenome);

    int i, j;
    for (i = 0, j = 0; nome[i] != '\0'; i++, j++){
        nomecompleto[j]= nome[i];
    }
    nomecompleto[j] = ' ';
    j++;
    
    for(i = 0; sobrenome[i] != '\0'; i++, j++) {
        nomecompleto[j] = sobrenome[i];
    }
    nomecompleto[j] = '\0';

    int k = 0;
    for (int i = 0; nomecompleto[i] != '\0'; i++) {
        if (nomecompleto[i] != ' ') {
        nomecompleto[k] = nomecompleto[i];
        k++;
    }
}
nomecompleto[k] = '\0';

    printf("\nNome completo: %s.", nomecompleto);

    char busca[30];
    printf("\nDigite a sequência que deseja buscar: ");
    scanf("%s", busca);

    if (strstr(nomecompleto, busca) != NULL) {
        printf("Sequência '%s' encontrada em '%s'.\n", busca, nomecompleto);
    } else {
        printf("Sequência '%s' NÃO encontrada em '%s'.\n", busca, nomecompleto);
    }

    printf("\nNome completo: %s.", nomecompleto);


    return 0;
}