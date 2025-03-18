#include <stdio.h>

typedef struct {
    char estado[3]; // Sigla do estado
    char codigo[10]; // Código da carta
    char nome[50];   // Nome da cidade
    unsigned long int populacao; // População
    float area;     // Área
    float pib;      // PIB
    int pontos_turisticos; // Número de pontos turísticos
} Carta;

void cadastrarCarta(Carta *carta) {
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

void compararCartas(Carta carta1, Carta carta2) {
    printf("\nComparação de Atributos:\n");

    // Comparação de População
    printf("Vencedor (População): %s\n", (carta1.populacao > carta2.populacao) ? carta1.nome : carta2.nome);
    
    // Comparação de Área
    printf("Vencedor (Área): %s\n", (carta1.area > carta2.area) ? carta1.nome : carta2.nome);
    
    // Comparação de PIB
    printf("Vencedor (PIB): %s\n", (carta1.pib > carta2.pib) ? carta1.nome : carta2.nome);
    
    // Comparação de Densidade Populacional
    float densidade1 = (carta1.area > 0) ? (carta1.populacao / carta1.area) : 0;
    float densidade2 = (carta2.area > 0) ? (carta2.populacao / carta2.area) : 0;
    printf("Vencedor (Densidade Populacional): %s\n", (densidade1 < densidade2) ? carta1.nome : carta2.nome);
}

void exibirCarta(Carta carta) {
    printf("\nInformações da Carta:\n");
    printf("Estado: %s\nCódigo: %s\nNome da Cidade: %s\nPopulação: %lu\nÁrea: %.2f\nPIB: %.2f\nPontos Turísticos: %d\n",
           carta.estado, carta.codigo, carta.nome, carta.populacao, carta.area, carta.pib, carta.pontos_turisticos);
}

int main() {
    Carta carta1, carta2;

    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&carta1);
    exibirCarta(carta1);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&carta2);
    exibirCarta(carta2);

    // Comparação das cartas
    compararCartas(carta1, carta2);

    return 0;
}