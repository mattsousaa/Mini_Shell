/**********************************************************************
 * Write a program that will take the bits in a number and shift them
 * to the left end. For example, 01010110 (binary) would become
 * 11110000 (binary).
 **********************************************************************/

#include <stdio.h>

#define BIT_WIDTH 8 /* Largura de 1 byte do número */

int bitcounter(int number) {

	int i;          /* variável de iteração */
	int count;      /* contador de bits em 1 */

	count = 0;		/* inicializar a variável contador em 0 */

	/* Faremos uma varredura na arquitetura de 8 bits para verificar os bits que estão setados em 1 */
	for (i = 0; i < BIT_WIDTH; ++i) {
		if (number & (1 << i)) {		/* Máscara para deslocar o 0x01 a cada iteração fazendo um bitwise & p/ ver qts bits estão ativos em 1 */
			++count;					/* Retorna o contador que equivale o número de bits 1 setados.*/
		}
	}

	return count;						/* Retorno da função com o número de bits setados.*/
}

int count;          		/* Uma variável global que receberá o valor do contador da função acima */

int main() {

	unsigned char number;        /* número de 8 bits */
	int i;              		/* variável de iteração */
	
	/* 01010110b = 2 + 4 + 16 + 64 = 86 em decimal */

	number = 86;			/* Fixamos o número em 86 de acordo com a sugestão da questão */

	/* Esperado: 11110000b = 16 + 32 + 64 + 128 = 240 em decimal */

	count = bitcounter(number);

	printf("\n");

	/*
		Começaremos colocando os primeiros quatro 1's na esquerda dentro do "if", depois vamos zerando com o "else".
	*/
	for (i = BIT_WIDTH - 1; i >= 0; --i) {
		if (count) {
			/* Seta o bit pra 1 */
			printf("Setar bit %d para 1.\n", i);
			number |= (1 << i);

			/* Decrementar o contador até chegar em 0 */
			--count;

		} else {
			/* Seta o bit pra 0 */
			printf("Setar bit %d para 0.\n", i);
			number &= ~(1 << i);
		}
	}

	printf("\n");

	printf("Resultado esperado (240 em decimal): %d\n", number);
	printf("Resultado esperado (F0 em hexadecimal): %x\n", number);

	return(0);
}

