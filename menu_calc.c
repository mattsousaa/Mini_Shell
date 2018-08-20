#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int menu_calc(void){

int op;

	printf("\t\tCalculadora Simples\n\n");

    printf("Operações disponíveis\n");
    printf("1 - soma\n");
    printf("2 - subtracao\n");
    printf("3 - multiplicao\n");
    printf("4 - divisao\n");
    printf("5 - resto da divisao\n");
    printf("6 - Sair\n");

    printf("Digite a operação desejada: \n");
    scanf("%d", &op);

	while(op < 1 || op > 6){
		printf("Opcao Digitada Invalida !!!\n");
		printf("Digite uma Opcao Válida: ");
		scanf("%i",&op);
	}

	return op;
}
