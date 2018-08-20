# Makefile para o Projeto 1 de Sistemas Operacionais

# Temos vários arquivos que serão vários processos. O programa constitui um MiniShell com um Menu Principal
# que terá a opção de escolha para 4 programas. Esse menu principal será o processo raiz, o pai de todos que 
# serão filhos e netos. No momento que o comando make no terminal for digitado, vários arquivos serão criados
# ao mesmo tempo. O arquivo que deve ser executado primeiro é o arquivo exec1, que irá constituir o menu 
# principal. Os arquivos exec2, app1, app2 e app3 constituem os executáveis dos outros programas que serão
# filhos do menu principal. O exec2 constitui uma calculadora, com outro menu. A calculadora será filha do 
# menu principal, que por sua vez será pai de outros processos. Os outros processos são as operações que a 
# calculadora irá executar. Logo os executáveis soma, mult, sub, rest e divid são processos filhos do menu
# da calculadora. 

output: main.o menu.o split_bits.o shift_transf.o cont_1_bits.o calc.o soma.o mult.o div.o menu_calc.o subt.o resto.o

	gcc -o exec1 main.o menu.o
	gcc -o exec2 calc.o menu_calc.o 
	gcc -o app1 split_bits.o
	gcc -o app2 shift_transf.o
	gcc -o app3 cont_1_bits.o
	gcc -o soma soma.o
	gcc -o mult mult.o
	gcc -o sub subt.o
	gcc -o rest resto.o
	gcc -o divid div.o

main.o: main.c
	gcc -c main.c

menu.o: menu.c menu.h
	gcc -c menu.c

split_bits.o: split_bits.c
	gcc -c split_bits.c

shift_transf.o: shift_transf.c
	gcc -c shift_transf.c

cont_1_bits.o: cont_1_bits.c
	gcc -c cont_1_bits.c

calc.o: calc.c
	gcc -c calc.c

menu_calc.o: menu_calc.c calc.h
	gcc -c menu_calc.c

sum.o: soma.c
	gcc -c soma.c

sub.o: subt.c
	gcc -c subt.c

div.o: div.c
	gcc -c div.c

mult.o: mult.c
	gcc -c mult.c

resto.o: resto.c
	gcc -c resto.c

clean: 
	rm *.o exec1 exec2 app1 app2 app3 soma mult sub rest divid
