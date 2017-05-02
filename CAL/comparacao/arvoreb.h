#define ERRO 987654321

typedef struct no{
   struct no *dir;
   struct no *esq;
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
