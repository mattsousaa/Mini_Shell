#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int num1, num2;
 
    printf("Digite dois números: \n");
    scanf("%d", &num1);
    scanf("%d", &num2);

    printf("\n");

    if(num1 % num2 == 0){
    	printf("Os 2 números produzem resto igual a 0.\n\n");
    }else{
    	printf("Os números não produzem resto igual a 0.\n\n");
    }

	return 0;
}

