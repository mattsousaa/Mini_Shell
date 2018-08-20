#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int menu(void){

	printf("------------------MINI SHELL------------------\n\n");
	printf("1 - Split Bits \n");
	printf("2 - Shift Bits \n");
	printf("3 - Count Bits\n");
	printf("4 - Calculadora\n");
	printf("5 - Sair\n\n");

	int opcao;
	printf("Selecione a opcao desejada: \n\n");
	scanf("%i",&opcao);

	printf("\n");

	while(opcao < 1 || opcao > 5){
		printf("Opcao Digitada Invalida !!!\n\n");
		printf("Digite uma Opcao Válida: \n\n");
		scanf("%i",&opcao);
	}

	return opcao;
}
