#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[3]; // Sigla do estado
    char codigo[10]; // Código da carta
    char nome[50];   // Nome da cidade
    unsigned long int populacao; // População
    float area;     // Área
    float pib;      // PIB
    int pontos_turisticos; // Número de pontos turísticos
};

void cadastrarCarta(struct Carta *carta) {
    printf("Digite o estado (sigla): ");
    scanf("%s", carta->estado);
    printf("Digite o código da carta: ");
    scanf("%s", carta->codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nome);
    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);
    printf("Digite a área: ");
    scanf("%f", &carta->area);
    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

void compararCartas(struct Carta carta1, struct Carta carta2, int atributo1, int atributo2) {
    int vencedor1 = 0, vencedor2 = 0;

    // Comparação do primeiro atributo
    switch (atributo1) {
        case 1: // População
            vencedor1 = (carta1.populacao > carta2.populacao) ? 1 : (carta1.populacao < carta2.populacao) ? 2 : 0;
            break;
        case 2: // Área
            vencedor1 = (carta1.area > carta2.area) ? 1 : (carta1.area < carta2.area) ? 2 : 0;
            break;
        case 3: // PIB
            vencedor1 = (carta1.pib > carta2.pib) ? 1 : (carta1.pib < carta2.pib) ? 2 : 0;
            break;
        case 4: // Densidade Populacional
            {
                float densidade1 = (carta1.area > 0) ? (carta1.populacao / carta1.area) : 0;
                float densidade2 = (carta2.area > 0) ? (carta2.populacao / carta2.area) : 0;
                vencedor1 = (densidade1 > densidade2) ? 1 : (densidade1 < densidade2) ? 2 : 0;
            }
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    // Comparação do segundo atributo
    switch (atributo2) {
        case 1: // População
            vencedor2 = (carta1.populacao > carta2.populacao) ? 1 : (carta1.populacao < carta2.populacao) ? 2 : 0;
            break;
        case 2: // Área
            vencedor2 = (carta1.area > carta2.area) ? 1 : (carta1.area < carta2.area) ? 2 : 0;
            break;
        case 3: // PIB
            vencedor2 = (carta1.pib > carta2.pib) ? 1 : (carta1.pib < carta2.pib) ? 2 : 0;
            break;
        case 4: // Densidade Populacional
            {
                float densidade1 = (carta1.area > 0) ? (carta1.populacao / carta1.area) : 0;
                float densidade2 = (carta2.area > 0) ? (carta2.populacao / carta2.area) : 0;
                vencedor2 = (densidade1 > densidade2) ? 1 : (densidade1 < densidade2) ? 2 : 0;
            }
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    // Determinando o vencedor
    if (vencedor1 == 0 && vencedor2 == 0) {
        printf("Empate em ambos os atributos!\n");
    } else {
        printf("Resultados da comparação:\n");
        if (vencedor1 == 1) {
            printf("%s venceu no primeiro atributo!\n", carta1.nome);
        } else if (vencedor1 == 2) {
            printf("%s venceu no primeiro atributo!\n", carta2.nome);
        } else {
            printf("Empate no primeiro atributo!\n");
        }

        if (vencedor2 == 1) {
            printf("%s venceu no segundo atributo!\n", carta1.nome);
        } else if (vencedor2 == 2) {
            printf("%s venceu no segundo atributo!\n", carta2.nome);
        } else {
            printf("Empate no segundo atributo!\n");
        }
    }
}

void exibirCarta(struct Carta carta) {
    printf("\nInformações da Carta:\n");
    printf("Estado: %s\n", carta.estado