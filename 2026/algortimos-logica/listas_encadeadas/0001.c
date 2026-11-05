#include <stdio.h>
#include <stdlib.h>

struct No
{
    int valor;
    struct No *prox;
};
typedef struct No lista;

void inicializa(lista *cartas);
void adiciona_ordenada(lista *cartas);
void mostra_lista(lista *cartas);
int checa_lista(lista *cartas);

int main()
{
    lista *cartas = (lista *)malloc(sizeof(lista));
    if (!cartas)
    {
        printf("Impossivel alocar memoria\n");
        exit(1);
    }
    else
    {
        printf("memoria alocada");
    }

    inicializa(cartas);
    adiciona_ordenada(cartas);
    mostra_lista(cartas);
}

void inicializa(lista *cartas)
{
    cartas->prox = NULL;
    printf("lista cartas iniciada\n");
}

void adiciona_ordenada(lista *cartas)
{
    lista *novo = (lista *)malloc(sizeof(lista));
    if (!novo)
    {
        printf("Impossivel alocar memoria\n");
        exit(1);
    }

    printf("digite um numero para inserir: ");
    scanf("%i",&novo->valor);

    lista *anterior = cartas;
    lista *aux = cartas ->prox;

    while (aux != NULL && aux->valor < novo -> valor)
    {
        anterior = aux;
        aux = aux -> prox;
    };
    
    novo ->prox = aux;
    anterior->prox = novo;

}
int checa_lista(lista *cartas)
{
	if(cartas->prox == NULL)
		return 1;
	else
		return 0;
}
void mostra_lista(lista *cartas)
{
	if(checa_lista(cartas))
	{
	    printf("Lista vazia\n");
		return ;
	}
	lista *aux = cartas->prox;
	printf("Cartas -> ");
	while( aux != NULL){
		printf("%d -> ", aux->valor);
		aux = aux->prox;
	}
	printf("NULL \n\n");
} 