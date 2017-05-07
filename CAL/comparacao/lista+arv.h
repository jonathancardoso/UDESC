#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIM 1
#define NAO 0
#define ERRO 987654321
#define COMPARA ((strcmp(lista->cabecalho->nome,nome)==0)&&(strcmp(lista->cabecalho->sobrenome,sobrenome))==0)
//----------------
//Estrutura Arvore
//----------------
typedef struct No{
   struct No *dir;
   struct No *esq;
   unsigned int number;
   char nome[100];
   char sobrenome[100];
}Nodo;

void insere(int valor, char nome[100],char sobrenome[100], Nodo **raiz);
void mostra(Nodo *raiz); //infixada
Nodo * removerNodo(int valor,Nodo *raiz);
Nodo* FindMin(Nodo* raiz);
int deleteNodo(int dado, Nodo* raiz);
int removeNodo(Nodo *raiz, int dado);
unsigned int busca(char nome[100],char sobrenome[100], Nodo *raiz);

//----------------
//Estrutura Lista
//----------------
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
//----------------
