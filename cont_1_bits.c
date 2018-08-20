/********************************************************************************
* Write a program that counts the number of bits set in an integer. For example,
* the number 5 (decimal), which is 0000000000000101 (binary), has two bits set.
*********************************************************************************/

# include <stdio.h>

#define BIT_WIDHT 16 /* Largura de 2 bytes do número para fazer análise dentro da função de contagem de bits em 1. */

int bitcounter(int number){

	int i;          /* variável de iteração */
	int count;      /* contador de bits em 1 */

	count = 0;		/* inicializar a variável contador em 0 */

	/* Faremos uma varredura na arquitetura de 16 bits para verificar os bits que estão setados em 1 */
	for (i = 0; i < BIT_WIDHT; ++i) {
		if (number & (1 << i)) {		/* Máscara para deslocar o 0x01 a cada iteração fazendo um bitwise & p/ ver qts bits estão ativos em 1 */
			++count;					/* Retorna o contador que equivale o número de bits 1 setados.*/
		}
	}

	return count;						/* Retorno da função com o número de bits setados.*/
}


int main(){

unsigned int number; /* Variável que armazena o número para fazer análise de quantos bits estão setados em 1 */
int recebe_count;	/* Variável que recebe o retorno da função "bitcounter" */

number = 5;		/* Número fixado para fazer a análise de qts bits estão setados em 1 */

/* Temos que 5 é em binário em 16 bits é: 0000000000000101b. Precisamos retornar a qtd de número setados em 1, 
nesse caso temos que ter o retorno de 2. */

/*Chama a função "bitcounter" que faz a contagem de bits em 1.*/

recebe_count = bitcounter(number);

printf("O número de bits setados em 1 de %d é: %d.\n", number, recebe_count);

return 0;

}