/**********************************************************************
 * Write a program that takes a 32-bit integer (long int) and splits it
 * into eight 4-bit values. (Be careful of the sign bit.)
 **********************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {


	long int number;        /* variável inteira de 32 bits */
	number = 843734;     	/* um número qualquer fixado */
	int i, j;           	/* iteradores para os loops */
	int pos;            	/* posição para os bits */
	int store_results[8];	/* armazena os valores de cada grupo de 8 bits, cada posição guarda 1 valor correspondente a 4 bits*/
	pos = 0;            	/* começar com a posição em 0 */

	/* Fazer um laço passando por 32 bits, varrer 8 grupos de 4 bits*/

	/***************************************************** 
	   Representação de 32 bits de 843.734.

	   Cada grupo de 4 bits no final vai armazenar um valor 
	   em cada posição da variável store_results.

	   Temos um total de 8 "containers", cada um armazenando 4 bits. 

	   Container : [0]  [1]  [2]  [3]  [4]  [5]  [6]  [7]  

	   843734    = 0000 0000 0000 1100 1101 1111 1101 0110 
	   
	   store[8]  =   0    0    0   12   13   15   13   6
	*****************************************************/

	for (i = 7; i >= 0; --i) {

		store_results[i] = 0; /* inicializa o resultado da posição "i" em 0 */

		printf("Container [%d]\n", i);

		/* laço para os 4 bits */

		for (j = 0; j < 4; ++j) {

			/* Faz análise da posição do bit se é 0 ou 1 */

			printf("bit %d: ", pos);
			if ((number & (1 << pos)) != 0) {
				printf("1\n");
				store_results[i] |= (1 << j);

			} else {
				printf("0\n");
			}

			/* move p/ a proxima posição nos 32 bits */
			++pos;
		}
	}

	printf("\n");

	for (i = 0; i < 8; ++i) {

		printf("%d", store_results[i]);

		printf("  ");
	}

	printf("\n");

	return(0);
}
