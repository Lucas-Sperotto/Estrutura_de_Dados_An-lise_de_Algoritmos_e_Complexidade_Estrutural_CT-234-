#include <stdlib.h>
#include <stdio.h>

//-----------------------------------------------------------------------------------------------------
//Criação da Estrutura de Dados LISTA........
//-----------------------------------------------------------------------------------------------------

int size=0;
typedef int TipoChave;

typedef struct {
  int Chave;
  int info;
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
} TipoLista;

//--------------------------------------------------------------------------------------------------------------
// Funções Básicas da Estrutura.....
//--------------------------------------------------------------------------------------------------------------

void FLVazia(TipoLista *Lista)
{ Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
  size++;
}

int Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{ Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Item = x;
  Lista -> Ultimo -> Prox = NULL;
  size++;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{ /*  ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- */
  TipoApontador q;
  if (Vazia(*Lista) || p == NULL || p -> Prox == NULL)
  { printf(" Erro   Lista vazia ou posi  c   a o n  a o existe\n");
    return;
  }
  q = p -> Prox;
  *Item = q -> Item;
  p -> Prox = q -> Prox;
  if (p -> Prox == NULL) Lista -> Ultimo = p;
  free(q);
 size--;
}

void Imprime(TipoLista Lista)
{ TipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL)
    { printf("%d\n", Aux -> Item.Chave);
      Aux = Aux -> Prox;
    }
}

//------------------------------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------------------------------
/*
void push(x){//empilha x
if (size() == N)
    return ERROR;
S[++t]=x;
}
void pop(){//desempilha o topo
    if (isempty())
        return ERROR;
    S[t--] = null;
}
int top(){//retorna o topo sem desempilhá-lo
if (isEmpty())
    return ERROR;
return S[t];
}

int size() {//retorna o tamanho atual da pilha
return t+1;
}

int isEmpty(){//verifica se a pilha está vazia
return (t<0);
}

*/
int main(){

    TipoLista lista;
    TipoItem item;

    TipoApontador p;
    int i=0, MAX=23;


    FLVazia(&lista);

   // printf("Digite o Numero de vitimas: ");
    //scanf("%d", MAX);

  /*Insere cada chave na lista */
  for (i = 0; i <= MAX; i++)
    { item.Chave = i;
      Insere(item, &lista);
      //printf("Inseriu: %d \n", item.Chave);
    }

  //Imprime(lista);



  /*Mata Elementos*/
    p=lista.Primeiro;

  for(i = 0; i <= MAX; i++)
    {
         if ( p == NULL || p -> Prox == NULL){
            p=lista.Primeiro;}


        if(size>2){
            Retira(p, &lista, &item);
            printf("MATOU: %d\n", item.Chave);
            p = p->Prox;
            //size--;
        }

    }

  printf("SOBREVIVENTE: %d\n", lista.Primeiro->Prox->Item.Chave);
  Imprime(lista);
  return(0);
}
