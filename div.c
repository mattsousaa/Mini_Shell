#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

	float num1, num2;

	aqui:

	printf("Digite dois números: \n");
    scanf("%f", &num1);
    scanf("%f", &num2);

    if(num2 == 0){
    	printf("Impossível dividir por zero. Digite novamente.\n\n");
    	num1 = 0;
    	num2 = 0;
    	goto aqui;
    }

	printf("O resultado é: %f\n", (num1/num2));

	return 0;
}
