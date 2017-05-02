#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvoreb.h"

int main()
{
    // int valor;
    // Nodo *raiz=iniciaArvore();
    //
    // printf("Digita o valor que deseja inserir:\n");
    // while(scanf("%i", &valor), valor>=0){
    //             printf("Digite o dado(-1 para sair):\t");
    //             insere(valor, &raiz);
    // }

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
    Nodo *raiz=iniciaArvore();
    unsigned int n=0,i=0,number,found;
    char nome[100],sobrenome[100];
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    //Primeiro n
    fscanf(arq,"%i\n",&n);
    tempoInicial = clock();
    for(i=0;i<n;i++){
      fscanf(arq,"%i %s %s\n", &number,nome,sobrenome);
      insere(number, nome, sobrenome, &raiz);
    }
    tempoFinal = clock();
    tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
    printf("Tempo Gasto Insercao: %fs\n", tempoGasto );
    //Segundo n
    fscanf(arq,"%i\n", &n);
    tempoInicial = clock();
    for(i=0;i<n;i++){
      fscanf(arq,"%s %s\n",nome,sobrenome);
      found = busca(nome,sobrenome,raiz);
    //	printf("Encontrado:%i para %s %s\n",found,nome,sobrenome);
      fprintf(saida, "%i\n", found );
    }
    tempoFinal = clock();
    tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
    printf("Tempo Gasto Busca: %fs\n", tempoGasto );

    fclose(saida);
    fclose(arq);

    //mostra(raiz);

    return 0;
}
