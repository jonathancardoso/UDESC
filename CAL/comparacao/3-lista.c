#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista+arv.h"

int main()
{
    //////////////////Manipulação de Arquivos//////////////////
    //entrada
    char url[]="entrada-5.txt";
    FILE *arq;
    arq = fopen(url, "r");
    //saida
    FILE *saida;
    char url2[]="saida-5.txt";
    saida = fopen(url2, "w+");
    //////////////////////////////////////////////////////////
    unsigned int n=0,i=0,number=0,found=0,ret=0,tabelatam=0;
    char nome[100],sobrenome[100];
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    //Primeiro n
    fscanf(arq,"%i\n",&n);
		tabelatam = n/10;
		tLista lista[tabelatam]; //tabela hash (vetor de lista)
		inicializaLista(&lista);
    tempoInicial = clock();
    for(i=0;i<n;i++){
      fscanf(arq,"%i %s %s\n", &number,nome,sobrenome);
			ret = geraHash(stringToInt(nome,sobrenome),tabelatam);
			inserirNoInicio(&lista[ret],number,nome,sobrenome);
    }
    tempoFinal = clock();
    tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
    printf("Tempo Gasto Insercao: %fs\n", tempoGasto );
    //Segundo n
    fscanf(arq,"%i\n", &n);
    tempoInicial = clock();
    for(i=0;i<n;i++){
      fscanf(arq,"%s %s\n",nome,sobrenome);
      found = geraHash(stringToInt(nome,sobrenome),tabelatam);
    //	printf("Encontrado:%i para %s %s\n",found,nome,sobrenome);
      fprintf(saida, "%i\n", lista[found].cabecalho->number);
    }
    tempoFinal = clock();
    tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
    printf("Tempo Gasto Busca: %fs\n", tempoGasto );

    fclose(saida);
    fclose(arq);

    //mostra(raiz);
/*
	char nome[100]="Hellen";
	char sobrenome[100]="Jonathan";
    	int ret,number=10;
	tLista lista[5000]; //tabela hash (vetor de lista)
	inicializaLista(&lista);
	ret = stringToInt(nome,sobrenome);
	printf("\n%i\n",ret);
	ret = geraHash(stringToInt(nome,sobrenome),5000);
	printf("\n%i\n",ret);
	inserirNoInicio(&lista[ret],number,nome,sobrenome);
	inserirNoInicio(&lista[ret],12,nome,sobrenome);
	printf("\nEsse: %i\n",(lista[ret].cabecalho)->number);*/
    return 0;
}
