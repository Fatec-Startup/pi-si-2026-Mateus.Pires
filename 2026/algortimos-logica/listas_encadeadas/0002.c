#include <stdlib.h>
#include <stdio.h>

struct No
{
    int valor;
    struct No *proximo;
};
typedef struct No lista;

void inicializa(lista *cartas);

void adiciona_ordenada(lista *cartas);

int checar_lista(lista *cartas);

void mostra_lista(lista *cartas);

int main()
{
    lista *cartas = (lista *)malloc(sizeof(lista));
    if (!cartas)
    {
        printf("Impossivel alocar memoria\n");
        exit(1);
    }

    inicializa(cartas);

    int opcao;

    do
    {
        printf("\n=== MENU ===\n");
        printf("1 - Adicionar ordenado\n");
        printf("2 - Mostrar lista\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adiciona_ordenada(cartas);
            break;
        case 2:
            mostra_lista(cartas);
            break;
        case 3:
            checar_lista(cartas);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida\n");
        }

    } while (opcao != 0);

    free(cartas);
}

void inicializa(lista *cartas)
{
    cartas->proximo = NULL;
    printf("Cartas Inicializadas");
}

void adiciona_ordenada(lista *cartas)
{
    lista *novo = (lista *)malloc(sizeof(lista));
    if (!novo)
    {
        printf("Impossivel alocar memoria\n");
        exit(1);
    }
    printf("Digite um valor: ");
    scanf("%d", &novo->valor);

    lista *anterior = cartas;
    lista *aux = cartas->proximo;

    while (aux != NULL && aux->valor < novo->valor)
    {
        anterior = aux;
        aux = aux->proximo;
    }
    novo->proximo = aux;
    anterior->proximo = novo;
}

int checar_lista(lista *cartas)
{
    if (cartas->proximo == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void mostra_lista(lista *cartas)
{
    if (checar_lista(cartas))
    {
        printf("a lista esta vazia\n");
    }
    lista *aux = cartas->proximo;
    printf("Cartas -> ");
    while (aux != NULL)
    {
        printf("%i ", aux->valor);
        aux = aux->proximo;
    }
    printf("NULL");
}