#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoreb.h"

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

// int removeNodo(Nodo *raiz, int dado)
// {
//     Nodo *subst, *paiSubst, *alvo, *paiDoAlvo, *avante;
//     paiDoAlvo = NULL;
//     alvo = raiz;
//     while (alvo != NULL && alvo->dado != dado)
//     {
//         paiDoAlvo = alvo;
//         alvo = (alvo < dado ? alvo->esq : alvo->dir);
//     }
//
//     if (alvo==NULL)   /*alvo n�o encontrado */
//         return 0;
//
//     if (alvo->esq == NULL)
//         if (alvo->dir == NULL) // alvo � uma folha
//             subst = NULL;
//         else
//             subst = alvo->dir; /*alvo possui apenas um filho � dir*/
//
//     else
//         if(alvo->dir == NULL)
//             subst = alvo->esq; /*alvo possui apenas um filho � esq*/
//
//         else  /* alvo possui os dois filhos*/
//         {       /* determinando o substituto pelo sucessor em ordem: */
//             paiSubst = alvo;
//             subst = alvo->dir;
//             avante = alvo->esq;
//             while( avante != NULL)
//             {
//                 paiSubst = subst;
//                 subst = avante;
//                 avante = avante->esq;
//             }
//             if(paiSubst != alvo)
//                 {
//                     paiSubst->esq = subst->dir;
//                     subst->dir = alvo->dir;
//                 }
//                 subst->esq = alvo->esq; /*o pai do substituto eh o proprio alvo */
//         }
//      if(raiz == alvo) // ou seja se "paiDoAlvo = NULL"
//         raiz = subst; /*alvo era a raiz*/
//      else
//         alvo == paiDoAlvo->esq ? (paiDoAlvo->esq = subst) : (paiDoAlvo->dir = subst);
//
//
//     free(alvo);
//     return 1;
// }
