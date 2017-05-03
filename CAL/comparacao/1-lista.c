#include <stdio.h>
#include <time.h>
#include "lista.h"

int main(int argc, char **argv)
{
	//Estrutura Lista
	tLista lista;
	inicializaLista(&lista);
	//////////////////Manipulação de Arquivos//////////////////
	//entrada
	char url[]="entrada-3.txt";
	FILE *arq;
	arq = fopen(url, "r");
	//saida
	FILE *saida;
	char url2[]="saida-3.txt";
	saida = fopen(url2, "w+");
	//////////////////////////////////////////////////////////
	unsigned int n=0,i=0,number,found;
	char nome[100],sobrenome[100];
	clock_t tempoInicial, tempoFinal;
	double tempoGasto;
	//Primeiro n
	fscanf(arq,"%i\n",&n);
	tempoInicial = clock();
	for(i=0;i<n;i++){
		fscanf(arq,"%i %s %s\n", &number,nome,sobrenome);
		inserirNoInicio(&lista,number,nome,sobrenome);
	}
	tempoFinal = clock();
	tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
	printf("Tempo Gasto Insercao: %fs\n", tempoGasto );
	//Segundo n
	fscanf(arq,"%i\n", &n);
	tempoInicial = clock();
	for(i=0;i<n;i++){
		fscanf(arq,"%s %s\n",nome,sobrenome);
		found = buscarNomeSobrenome(lista,nome,sobrenome);
	//	printf("Encontrado:%i para %s %s\n",found,nome,sobrenome);
		fprintf(saida, "%i\n", found );
	}
	tempoFinal = clock();
	tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
	printf("Tempo Gasto Busca: %fs\n", tempoGasto );

	fclose(saida);
	fclose(arq);

	//mostraLista(lista);
	return 0;
}
