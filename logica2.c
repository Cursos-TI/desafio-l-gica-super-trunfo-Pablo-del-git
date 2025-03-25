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

void compararCartas(struct Carta carta1, struct Carta carta2, int atributo) {
    switch (atributo) {
        case 1: // Comparar População
            printf("Vencedor (População): %s\n", carta1.populacao > carta2.populacao ? carta1.nome : carta2.nome);
            break;
        case 2: // Comparar Área
            printf("Vencedor (Área): %s\n", carta1.area > carta2.area ? carta1.nome : carta2.nome);
            break;
        case 3: // Comparar PIB
            printf("Vencedor (PIB): %s\n", carta1.pib > carta2.pib ? carta1.nome : carta2.nome);
            break;
        case 4: // Comparar Densidade Populacional
            {
                float densidade1 = (carta1.area > 0) ? (carta1.populacao / carta1.area) : 0;
                float densidade2 = (carta2.area > 0) ? (carta2.populacao / carta2.area) : 0;
                printf("Vencedor (Densidade Populacional): %s\n", densidade1 > densidade2 ? carta1.nome : carta2.nome);
            }
            break;
        default:
            printf("Atributo inválido!\n");
            break;
    }
}

void exibirCarta(struct Carta carta) {
    printf("\nInformações da Carta:\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

int main() {
    struct Carta carta1, carta2;
    int opcao;

    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&carta1);
    exibirCarta(carta1);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&carta2);
    exibirCarta(carta2);

    do {
        printf("\nEscolha um atributo para comparar:\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Densidade Populacional\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 4) {
            compararCartas(carta1, carta2, opcao);
        } else if (opcao != 5) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    printf("Saindo do programa...\n");
    return 0;
}