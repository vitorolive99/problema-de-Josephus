#include <stdio.h>
#include <string.h>

/*Lista circular*/
typedef struct no{
char* dado[30];
struct no *proxNo;
}tipoNo;

typedef struct listaGerenciada{
tipoNo *fim;
int quant;
}tipoLista;

void inicializa(tipoLista *listaEnc){
    listaEnc->fim = NULL;
    listaEnc->quant = 0;
}

void insereListaVazia(tipoLista *listaEnc, char* valor[]){
tipoNo *novoNo;
novoNo = (tipoNo*) malloc(sizeof (novoNo));
if(novoNo == NULL)
    return 0;
strcpy(novoNo->dado, valor); /*Coloca o dado dentro do n� criado*/
novoNo->proxNo = novoNo; /*Faz o pr�ximo do n� criado ser ele pr�prio*/
listaEnc->fim = novoNo;
listaEnc->quant++;
}

void exibeLista(tipoLista *listaEnc){
   tipoNo *atual;
   atual = listaEnc->fim->proxNo;
   printf("\n\nLista armazenada:");
   printf("%8s",atual->dado);
   while(atual != listaEnc->fim){
      atual = atual->proxNo;
      printf("%8s",atual->dado);
   }
}

int insereNaFrente(tipoLista *listaEnc, char* valor[]){
  tipoNo *novoNo;
   novoNo = (tipoNo*) malloc(sizeof (novoNo));
    if(novoNo == NULL)
        return 0;
    strcpy(novoNo->dado, valor);
    novoNo->proxNo = listaEnc->fim->proxNo;
    listaEnc->fim->proxNo = novoNo;
    listaEnc->quant++;
return 1;
}

int buscaDado(tipoLista *listaEnc, int valor){
    tipoNo *atual;
    int cont=1;
    atual=listaEnc->fim;
    do{
        atual=atual->proxNo;
        if(atual->dado == valor)
           return cont;
        cont++;
    }while(atual != listaEnc->fim);
    return 0;
}


void main(){
tipoLista lista;
int op, resp;
char num[30];
inicializa(&lista);
do{
    printf("\nMenu\n\n 1 - Insere elemento em lista vazia");
    printf("\n 2 - Insere na frente da lista");
    printf("\n 3 - Buscar dado na lista");
    printf("\n10 - Exibe a lista");
    printf("\n 0 - Sair do programa");
    printf("\nDigite sua opcao: ");
    scanf("%d",&op);
    switch(op){
    case 1: printf("\nDigite o elemento que deseja inserir:");
          scanf("%s",num);
          insereListaVazia(&lista, num);
          break;
    case 2: printf("\nDigite o elemento que deseja inserir:");
          scanf("%s",num);
          insereNaFrente(&lista, num);
          printf("%d", lista.quant);
          break;
    case 3: printf("\nDigite o elemento que deseja buscar:");
          scanf("%d",&num);
          if(resp = buscaDado(&lista, num))
            printf("\nO dado foi encontrado na posicao %d",resp);
          else
            printf("\nO dado n�o foi encontrado");
          break;
    case 10: exibeLista(&lista);
        break;
    case 0: printf("\nEncerrando programa...");
        break;
           }
   }while(op != 0);
}
