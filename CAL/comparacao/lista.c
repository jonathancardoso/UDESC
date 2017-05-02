#include "lista.h"

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
