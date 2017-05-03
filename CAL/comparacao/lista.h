#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIM 1
#define NAO 0
#define ERRO -987654321
typedef struct no{
    unsigned int number;
    char nome[100];
    char sobrenome[100];
    struct no *prox;
}tNo;
typedef struct lista{
    tNo *cabecalho;
    int n_elem;
}tLista;


void inicializaLista(tLista *lista);
int listaVazia(tLista lista);
void mostraLista(tLista lista);
void inserirNoInicio(tLista *lista, int number, char nome[100],char sobrenome[100]);
unsigned int buscarNomeSobrenome(tLista lista, char nome[100],char sobrenome[100]);
