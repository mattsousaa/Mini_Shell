#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <time.h>
#include <unistd.h>
#include "menu.h"

void main(void){
	int opcao_escolhida, status1, status2, status3, status4; /* Status para os processos */
  int escolha; /* Opção de escolha para usuário matar ou não o processo */

	pid_t child1; /* Filho 1 */
	pid_t child2; /* Filho 2 */
	pid_t child3; /* Filho 3 */
	pid_t child4; /* Filho 4 */

  aqui: /* Label de retorno para o processo pai */

  system("/usr/bin/clear");

	printf("Oi eu sou um processo pai, meu pid é: %d\n\n", getpid());
	
	// PRECISAMOS CRIAR UM PROCESSO PAI PARA INICIALIZAR O "SHELL"
	// A PARTIR DESSE PROCESSO PAI , É QUE SELECIONAMOS OS OUTROS PROGRAMAS
	// QUE SERÃO PROCESSOS FILHOS 

	opcao_escolhida = menu();  /* Chama arquivo de menu - Processo pai(raiz) */

	switch(opcao_escolhida){
		// CASO A OPCAO SEJA A DE SPLIT
		case 1: 

			if((child1 = fork()) < 0){
        		perror("Erro na criação do processo filho. Ou ele não existe ou ele já foi morto.");
        		exit(1);
    		}

    		if(child1 == 0){
        	//O código aqui dentro será executado no processo filho
   			printf("Oi, eu sou um processo filho, meu pid é: %d\n", getpid());
   			system("./app1"); /* Invoca processo Filho1 */
   			printf("\n");
	   		printf("Deseja matar o processo?\n\n");
        printf("1 - Sim\n\n2 - Não \n\n");
        printf("\n");
        scanf("%d", &escolha);
          if(escolha == 1){
            printf("Processo com pid %d aniquilado pelo usuário.....\n", getpid());
            sleep(3); 
            kill(getpid(), SIGQUIT);  /* Mata o processo (kill) */ 
          }else{
            printf("Processo com pid %d terminado. (exit)\n", getpid());
            sleep(3);
            _exit(0);   /* Termina o programa normalmente sem matá-lo */
          }
        }

        wait(&status1); /* Espera o processo do Filho1 terminar e voltar para o processo pai */

        goto aqui;

      break;

		//CASO A OPCAO SEJA A DE SHIFT
		case 2:

			if((child2 = fork()) < 0){
        		perror("Erro na criação do processo filho. Ou ele não existe ou ele já foi morto.");
        		exit(1);
    		}

    		if(child2 == 0){
        	//O código aqui dentro será executado no processo filho
   			printf("Oi, eu sou um processo filho, meu pid é: %d\n", getpid());
   			system("./app2"); /* Invoca processo Filho2 */
   			printf("\n");
	   		printf("Deseja matar o processo?\n\n");
        printf("1 - Sim\n\n2 - Não \n\n");
        scanf("%d", &escolha);
          if(escolha == 1){
            printf("Processo com pid %d aniquilado pelo usuário.....\n", getpid());
            sleep(3); 
            kill(getpid(), SIGQUIT); /* Mata o processo (kill) */ 
          }else{
            printf("Processo com pid %d terminado. (exit)\n", getpid());
            sleep(3);
            _exit(0); /* Termina o programa normalmente sem matá-lo */
          }
        }

        wait(&status2); /* Espera o término da execução do programa Filho2 */

        goto aqui;

      break;

		// CASO A OPCAO SEJA A DE COUNT

		case 3:

			if((child3 = fork()) < 0){
        		perror("Erro na criação do processo filho. Ou ele não existe ou ele já foi morto.");
        		exit(1);
    		}

			if(child3 == 0){
        	//O código aqui dentro será executado no processo filho
   			printf("Oi, eu sou um processo filho, meu pid é: %d\n", getpid());
   			system("./app3");
   			printf("\n");
        printf("Deseja matar o processo?\n\n");
        printf("1 - Sim\n\n2 - Não \n\n");
        scanf("%d", &escolha);
          if(escolha == 1){
            printf("Processo com pid %d aniquilado pelo usuário.....\n", getpid());
            sleep(3); 
            kill(getpid(), SIGQUIT);  /* Mata o processo (kill) */ 
          }else{
            printf("Processo com pid %d terminado. (exit)\n", getpid());
            sleep(3);
            _exit(0);   /* Termina o programa normalmente sem matá-lo */
          }
    		}

        wait(&status3);

        goto aqui;

			break;

		case 4:

			if((child4 = fork()) < 0){
        		perror("Erro na criação do processo filho. Ou ele não existe ou ele já foi morto.");
        		exit(1);
    		}

    		if(child4 == 0){
        	//O código aqui dentro será executado no processo filho
        system("/usr/bin/clear");
   			printf("Oi, eu sou um processo filho, meu pid é: %d\n", getpid());
        sleep(3);
   			system("./exec2");
   			printf("\n");
	   			_exit(0);    /* Termina o programa normalmente sem matá-lo */
    		}

    		wait(&status4); // espera a execução do processo
                
			break;

    case 5:
        printf("Processo com pid %d terminado. (exit)\n", getpid());
        _exit(0);     /* Termina o programa normalmente sem matá-lo */
      break;

		default:
			printf("Opção inválida.\n");
	}


}