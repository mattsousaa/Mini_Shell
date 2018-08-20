#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "calc.h"

int main(){

    int recebe, escolha; //variaveis de escolha do usuario
    int status1, status2, status3, status4, status5; //variaveis de status para cada filho 
    pid_t child1; // filho 1
    pid_t child2; // filho 2
    pid_t child3; // filho 3
    pid_t child4; // filho 4
    pid_t child5; // filho 5
    
    aqui: // label de retorno

    system("/usr/bin/clear");    

    printf("Oi eu sou um processo pai, meu pid é: %d\n\n", getpid());

    recebe = menu_calc();

    switch(recebe){
        case 1:
            if((child1 = fork()) < 0){
                perror("Erro na criação do processo filho. Ou ele não existe ou ele já foi morto.");
                exit(1);
            }

            if(child1 == 0){
            //O código aqui dentro será executado no processo filho
            printf("Oi, eu sou um processo filho, meu pid é: %d\n", getpid());
            system("./soma");
            printf("\n");
            printf("Deseja matar o processo?\n\n");
            printf("1 - Sim\n\n2 - Não \n\n");
            printf("\n");
            scanf("%d", &escolha);
                 if(escolha == 1){
                    printf("Processo com pid %d aniquilado pelo usuário.....\n", getpid());
                    sleep(3); 
                    kill(getpid(), SIGQUIT);  // mata o processo
                }else{
                    printf("Processo com pid %d terminado. (exit)\n", getpid());
                    sleep(3);
                    _exit(0);   // termina o processo sem matá-lo
                }
            }

        wait(&status1); // espera o processo na sua execução

        goto aqui;

        case 2:
            if((child2 = fork()) < 0){
                perror("Erro na criação do processo filho. Ou ele não existe ou ele já foi morto.");
                exit(1);
            }

            if(child2 == 0){
            //O código aqui dentro será executado no processo filho
            printf("Oi, eu sou um processo filho, meu pid é: %d\n", getpid());
            system("./sub");
            printf("\n");
            printf("Deseja matar o processo?\n\n");
            printf("1 - Sim\n\n2 - Não \n\n");
            printf("\n");
            scanf("%d", &escolha);
                 if(escolha == 1){
                    printf("Processo com pid %d aniquilado pelo usuário.....\n", getpid());
                    sleep(3); 
                    kill(getpid(), SIGQUIT);  // mata o processo
                }else{
                    printf("Processo com pid %d terminado. (exit)\n", getpid());
                    sleep(3);
                    _exit(0);   // termina o processo normalmente
                }
            }

        wait(&status2); // espera a execução do processo

        goto aqui;

        case 3:

            if((child3 = fork()) < 0){
                perror("Erro na criação do processo filho. Ou ele não existe ou ele já foi morto.");
                exit(1);
            }

            if(child3 == 0){
            //O código aqui dentro será executado no processo filho
            printf("Oi, eu sou um processo filho, meu pid é: %d\n", getpid());
            system("./mult");
            printf("\n");
            printf("Deseja matar o processo?\n\n");
            printf("1 - Sim\n\n2 - Não \n\n");
            printf("\n");
            scanf("%d", &escolha);
                 if(escolha == 1){
                    printf("Processo com pid %d aniquilado pelo usuário.....\n", getpid());
                    sleep(3); 
                    kill(getpid(), SIGQUIT);  //mata o processo
                }else{
                    printf("Processo com pid %d terminado. (exit)\n", getpid());
                    sleep(3);
                    _exit(0);   // termina a execução do processo
                }
            }

        wait(&status3); // espera a execução do processo

        goto aqui;

        case 4:
            if((child4 = fork()) < 0){
                perror("Erro na criação do processo filho. Ou ele não existe ou ele já foi morto.");
                exit(1);
            }

            if(child4 == 0){
            //O código aqui dentro será executado no processo filho
            printf("Oi, eu sou um processo filho, meu pid é: %d\n", getpid());
            system("./divid");
            printf("\n");
            printf("Deseja matar o processo?\n\n");
            printf("1 - Sim\n\n2 - Não \n\n");
            printf("\n");
            scanf("%d", &escolha);
                 if(escolha == 1){
                    printf("Processo com pid %d aniquilado pelo usuário.....\n", getpid());
                    sleep(3); 
                    kill(getpid(), SIGQUIT);  // mata o processo
                }else{
                    printf("Processo com pid %d terminado. (exit)\n", getpid());
                    sleep(3);
                    _exit(0);   // termina a execução do processo normalmente
                }
            }

        wait(&status4); // espera a execução do processo

        goto aqui;

        case 5:
            if((child5 = fork()) < 0){
                perror("Erro na criação do processo filho. Ou ele não existe ou ele já foi morto.");
                exit(1);
            }

            if(child5 == 0){
            //O código aqui dentro será executado no processo filho
            printf("Oi, eu sou um processo filho, meu pid é: %d\n", getpid());
            system("./rest");
            printf("\n");
            printf("Deseja matar o processo?\n\n");
            printf("1 - Sim\n\n2 - Não \n\n");
            printf("\n");
            scanf("%d", &escolha);
                 if(escolha == 1){
                    printf("Processo com pid %d aniquilado pelo usuário.....\n", getpid());
                    sleep(3); 
                    kill(getpid(), SIGQUIT);  //mata o processo
                }else{
                    printf("Processo com pid %d terminado. (exit)\n", getpid());
                    sleep(3);
                    _exit(0);   // termina o processo normalmente
                }
            }

        wait(&status5); // espera a execução do processo

        goto aqui;

        case 6:

            system("./exec1"); // volta ao menu principal como novo processo pai
            
            break;

        default:
            printf("Opção inválida.\n");
    }
}


