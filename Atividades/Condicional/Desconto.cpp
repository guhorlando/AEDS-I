#include <stdio.h>

int main(){
    float valor_da_compra, valor;

    printf("Digite o valor do produto: ");
    scanf("%f", &valor);

    if (valor > 100.0 & valor < 499.99){
        valor_da_compra = valor *0.1;
		printf("%f", valor_da_compra);
    } else {
        if (valor > 500.0 & valor < 999.99){
            valor_da_compra = valor*0.15;
			printf("%f", valor_da_compra);
        } else {
            if (valor > 1000.0){
                valor_da_compra = valor*0.2;
				printf("%f", valor_da_compra);
            } else {
                if (valor_da_compra == 500.0){
                    valor_da_compra = valor_da_compra/3;
					printf("%f", valor_da_compra);
                } else {
                    if (valor_da_compra == 1000.0){
                        valor_da_compra = valor_da_compra/6;
						printf("%f", valor_da_compra);
                    } else {
                        if (valor_da_compra > 1000.0){
                            valor_da_compra = valor_da_compra/12;
							printf("%f", valor_da_compra);
                        } else {
                            if (valor_da_compra <= 100.0){
                                printf("Nao ha parcela a serem realizadas!");
                            }
                        }
                    }

                }
            }
        }
    }

    return 0;
}
