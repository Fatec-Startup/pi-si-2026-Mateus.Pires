#include <stdlib.h>
#include <stdio.h>

struct No
{
    int valor;
    struct No *proximo;
    struct No *anterior
};
typedef struct No lista;

void inicializa(lista *cartas);
void menu(lista *cartas);

int main()
{
    lista *cartas = (lista *)malloc(sizeof(lista));
    if (!cartas)
    {
        printf("Impossivel alocar memoria\n");
        exit(1);
    }

    inicializa(cartas);
    menu(cartas);
    free(cartas);
}

int checa_lista(lista *cartas)
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

void inicializa(lista *cartas)
{
    cartas->proximo = NULL;
    printf("Cartas Inicializadas");
}

void menu(lista *cartas)
{
    int opcao;
    system('clc');
    do
    {
        printf("\n=== MENU ===\n");
        printf("1 - Adicionar no inicio\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adiciona_inicio(cartas);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida\n");
        }

    } while (opcao != 0);
}

void adiciona_inicio(lista *cartas)
{
    lista *novo = (lista *)malloc(sizeof(lista));

    if (!novo)
    {
        printf("nao foi possivel alocar a memoria");
        exit(1);
    }
    printf("digite um valor para alocar: ");
    scanf("%i", novo->valor);
    lista *aux = cartas->proximo;
    novo->anterior = cartas;
    novo->proximo = aux;
    aux->anterior = novo;
}