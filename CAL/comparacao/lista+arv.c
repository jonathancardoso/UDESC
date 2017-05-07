#include "lista+arv.h"
//----------------
//Funções p/ Hash
//----------------
int stringToInt(char nome[100],char sobrenome[100]){
	int a=0,b=0,c=0;
	a = strlen(nome);
	a += strlen(sobrenome);
	b = nome[0];
	c = sobrenome[0];
	return ((a*b)-(c-a))*37;
}

int geraHash(int prehash, int tamanhotabela){
	return prehash % tamanhotabela;
}

// int buscarHash(tLista lista[5000],int tabelatam, char nome[100],char sobrenome[100]){
// 	int aux=0;
// 	aux = geraHash(stringToInt(&nome,&sobrenome),tabelatam);
// 	printf("\nGerei\n");
// 	if((strcmp(lista.cabecalho->nome,nome)==0)&&(strcmp(lista.cabecalho->sobrenome,sobrenome))==0){
// 		printf("\nPrint 1\n");
// 		return lista[aux].cabecalho->number;
// 	}
// 	else{
// 		while(!COMPARA || lista[aux].cabecalho == NULL){
// 			  printf("\nPrint 2\n");
// 				lista[aux].cabecalho = lista[aux].cabecalho->prox;
// 		}
// 		if ((lista[aux].cabecalho) == NULL) {
// 			printf("\nPrint 3\n");
// 			return ERRO;
// 		}
// 		else{
// 			printf("\nPrint 4\n");
// 			return ((lista[aux].cabecalho)->number);
// 		}
// 	}
// }

//----------------
//Funções Arvore
//----------------
Nodo *iniciaArvore(){
    return NULL;
}

void insere(int valor, char nome[100],char sobrenome[100], Nodo **raiz)
{
    if( *raiz == NULL )
    {
        *raiz = (Nodo*) malloc( sizeof( Nodo ) );
        (*raiz)->number = valor;
        strcpy((*raiz)->nome,nome);
        strcpy((*raiz)->sobrenome,sobrenome);
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    }else {
          if (valor < (*raiz)->number){
            insere(valor,nome,sobrenome,&(*raiz)->esq);
        }
        if (valor > (*raiz)->number){
            insere(valor,nome,sobrenome,&(*raiz)->dir);
        }
    }
}

void mostra(Nodo *raiz)
{
   if (raiz != NULL){
        mostra(raiz->esq);
        printf ("\n %i\n", raiz->number);
        mostra(raiz->dir);
    }
}

unsigned int busca(char nome[100],char sobrenome[100], Nodo *raiz){
    if((strcmp(raiz->nome,nome)==0)&&(strcmp(raiz->sobrenome,sobrenome))==0){
     return raiz->number;
    }
    while (raiz != NULL){
      if(raiz->dir == NULL){
        return busca(nome,sobrenome,raiz->esq);
      }
      else{
        return busca(nome,sobrenome,raiz->dir);
      }
    }
  return ERRO;
}

//----------------
//Funções Lista
//----------------
void inicializaLista(tLista *lista){
    lista->n_elem = 0;
    lista->cabecalho = (tNo *) malloc(sizeof(tNo));
    }

int listaVazia(tLista lista){
    if(lista.n_elem == 0){
        return SIM;
    }
    else {
        return NAO;
    }
}

void inserirNoInicio(tLista *lista, int number, char nome[100],char sobrenome[100]){
    tNo *no;
    no = (tNo *) malloc(sizeof(tNo));
    no->number = number;
    strcpy(no->nome, nome);
    strcpy(no->sobrenome, sobrenome);
    if(lista->n_elem == 0){
    no->prox = NULL;
    lista->cabecalho = no;
    lista->n_elem = lista->n_elem +1 ;
    }
    else{
        no->prox = lista->cabecalho;
        lista->cabecalho = no;
        lista->n_elem = lista->n_elem +1 ;
    }
}

void mostraLista(tLista lista){
    int i;
    printf("\nDados da lista:\n");
    for(i=0;i<lista.n_elem;i++){
    printf("\tId: %i\tNome: %s\tSobrenome: %s\n",lista.cabecalho->number,lista.cabecalho->nome,lista.cabecalho->sobrenome);
    lista.cabecalho = lista.cabecalho->prox;
    }
}


unsigned int buscarNomeSobrenome(tLista lista, char nome[100],char sobrenome[100]){
  unsigned int i;
  for(i=0;i<lista.n_elem;i++){
    if((strcmp(lista.cabecalho->nome,nome)==0)&&(strcmp(lista.cabecalho->sobrenome,sobrenome))==0){
      return lista.cabecalho->number;
    }
    lista.cabecalho = lista.cabecalho->prox;
  }
  return ERRO;
}
