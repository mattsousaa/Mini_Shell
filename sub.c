#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int num1, num2;

	printf("Digite dois números: \n");
    scanf("%d", &num1);
    scanf("%d", &num2);
	printf("O resultado é: %d\n", (num1-num2));

	return 0;
}