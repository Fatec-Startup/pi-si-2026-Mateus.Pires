#include <stdio.h>
#include <stdlib.h>

struct No { 
	int valor;
	struct No *prox;
}; 
typedef struct No lista;

void inicializa (lista *cartas);
int checa_lista(lista *cartas);
void adiciona_fim(lista *cartas);
void mostra_lista(lista *cartas);
void adiciona_inicio(lista *cartas);
int tamanho_lista (lista *cartas);
void remove_inicio (lista *cartas);
void remove_final (lista *cartas);
void limpa_lista(lista *cartas);

main()
{	
	int i;
	lista *cartas = (lista *) malloc(sizeof(lista));
	if(!cartas){
		printf("Impossivel alocar memoria\n");
		exit(1);
    } 
	else
	    printf("Memoria alocada\n");
	inicializa(cartas);
	
	i = checa_lista(cartas);
	if(i == 1)
	    printf("Lista vazia\n");
	else if (i == 0)
	    printf("Lista não vazia\n");
	
	i = tamanho_lista(cartas);
	printf("Tamanho da lista = %d\n", i);
	
	adiciona_fim(cartas);
	adiciona_fim(cartas);
	adiciona_inicio(cartas);    
	mostra_lista(cartas);
	
	//remove_inicio(cartas);
	//mostra_lista(cartas);
	
	i = tamanho_lista(cartas);
	printf("Tamanho da lista = %d\n", i);
	
	//remove_final(cartas);
	
	limpa_lista(cartas);
	mostra_lista(cartas);
	
	free(cartas);
	getch();
}

void inicializa (lista *cartas)
{
 	cartas->prox = NULL;
 	printf("Lista cartas inicializada\n");
}

int checa_lista(lista *cartas)
{
	if(cartas->prox == NULL)
		return 1;
	else
		return 0;
}

void adiciona_fim(lista *cartas)
{  
	lista *novo = (lista *) malloc(sizeof(lista));
   	if(!novo)
   	{	
	   printf("Impossivel alocar memoria\n");
		exit(1);
   	} 
   	printf("Digite uma carta para inserir no baralho: "); 
   	scanf("%d", &novo->valor);
   	novo->prox = NULL;
   	if(checa_lista(cartas))
 		cartas->prox = novo;
   	else
   	{	
    	lista *aux = cartas->prox;
		while(aux->prox != NULL)
			aux = aux->prox;
		aux->prox = novo;
	}
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

void adiciona_inicio(lista *cartas)
{
	lista *novo = (lista *) malloc(sizeof(lista));
	if(!novo)
	{
		printf("Impossivel alocar memoria\n");
		exit(1);
    } 
   	printf("Digite uma carta para inserir no baralho: "); 
	scanf("%d", &novo->valor);
	lista *aux = cartas->prox;
	cartas->prox = novo;
	novo->prox = aux;
}

int tamanho_lista (lista *cartas)
{
 	int i = 0;
 	while (cartas->prox != NULL) 
	{
 		cartas = cartas->prox;
 		i++;
 	}
 	return i;
}

void remove_inicio (lista *cartas)
{
	lista *aux = cartas->prox;
	printf("Removendo o primeiro elemento do baralho \n");
	cartas->prox = cartas->prox -> prox;
	free(aux);
}

void remove_final (lista *cartas)
{
   	while (cartas->prox->prox != NULL)
  	{
       	cartas = cartas->prox ;
   	}
   	free(cartas->prox); 
   	cartas->prox = NULL;
   	printf("Removendo o ultimo elemento do baralho \n");
}

void limpa_lista(lista *cartas)
{	
	if(!checa_lista(cartas))
	{	
		lista *aux,*atual,*head;
		head = cartas;
        	atual = cartas->prox;
		while(atual->prox != NULL)
		{   
		    aux = atual->prox;
			free(atual);
			atual = aux;
		}
		if (atual->prox == NULL)
		{   
		   	head->prox = NULL;
		   	free(atual);
        } 
        printf("Lista limpa com sucesso!!! \n");
    }
}