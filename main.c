#include <stdio.h>
#include <string.h>
#include <windows.h>
    /*Bruna Keila Oliveira Santos
      Marina Gabriela Nascimento França
      Vitor Oliveira Santos
      */
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

int insereListaVazia(tipoLista *listaEnc, char* valor[]){
    tipoNo *novoNo;
    novoNo = (tipoNo*) malloc(sizeof (novoNo));
    if(novoNo == NULL)
        return 0;
    strcpy(novoNo->dado, valor); /*Coloca o dado dentro do n� criado*/
    novoNo->proxNo = novoNo; /*Faz o pr�ximo do n� criado ser ele pr�prio*/
    listaEnc->fim = novoNo;
    listaEnc->quant++;
    return 1;
}

void exibeLista(tipoLista *listaEnc){
   tipoNo *atual;
   atual = listaEnc->fim->proxNo;
   printf("\n\nCLIENTES RESTANTES:\n");
   printf("%s\n",atual->dado);
   Sleep(1000);
   if(listaEnc->quant > 1){
       while(atual != listaEnc->fim){
          atual = atual->proxNo;
          printf("%s\n",atual->dado);
          Sleep(1000);
       }
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

int sorteio(int quant)
{
    return (rand()%quant) + 1;
}

void excluiSorteado (tipoLista* lista, int num)
{
    tipoNo* atual, *ant;
    atual = lista->fim->proxNo;
    for(int i=0; i<num; i++)
    {
        ant = atual;
        atual = atual->proxNo;
    }
    printf("\nSORTEANDO...\n"); Sleep(1000);
    printf("\nO numero foi %d, o(a) cliente excluido(a) foi %s\n", num, atual->dado); Sleep(2000);
    ant->proxNo = atual->proxNo;
    lista->quant--;
    free(atual);
}

int main(){
tipoLista lista;
int op, cont = 0;
char num[30],sn;
inicializa(&lista);
do{
    printf("\nMenu\n\n 1 - CADASTRAR CLIENTES NO SORTEIO.");
    printf("\n 2 - REALIZAR SORTEIO");
    printf("\n10 - Exibe a lista");
    printf("\n 0 - Sair do programa");
    printf("\nDigite sua opcao: ");
    scanf("%d",&op);
    switch(op){
    case 1:
        do{
            printf("\nDigite o nome do cliente: ");
            scanf("%s",num);
            cont == 0?insereListaVazia(&lista, num): insereNaFrente(&lista, num);
            cont++;
            printf("\nDeseja adicionar outro cliente? S/N");
            scanf("%s", &sn);
        }while(toupper(sn) != 'N');

          break;
    case 2:
        for(int i=1; i<cont;i++){
            excluiSorteado(&lista, sorteio(lista.quant));
            Sleep(2000);
            exibeLista(&lista);
        }
          break;
    case 10: exibeLista(&lista);
        break;
    case 0: printf("\nEncerrando programa...");
        break;
           }
   }while(op != 0);
   return 0;
}
