#include <stdio.h>
#include <string.h>

// Definição da estrutura para guardar os dados de uma carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

// Função para preencher os dados de uma carta
void cadastrarCarta(Carta *c) {
    // Aqui, você pode trocar pelos dados que desejar
    printf("Cadastrando carta %s (%s)...\n", c->nome, c->codigo);
    printf("População: %d\nÁrea: %.2f\nPIB: %.2f\nPontos turisticos: %d\n",
           c->populacao, c->area, c->pib, c->pontos_turisticos);

    // Calcula densidade e PIB per capita
    c->densidade = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;

    // Exibe os valores calculados
    printf("Densidade populacional: %.2f hab/km²\n", c->densidade);
    printf("PIB per capita: %.2f\n", c->pib_per_capita);
    printf("\n");
}

int main() {
    // Inicializa duas cartas com valores pré-definidos
    Carta carta1 = {
        "São Paulo", "SP01", "São Paulo",
        12300000, 1521.11f, 700000.0f, 20,
        0.0f, 0.0f
    };
    Carta carta2 = {
        "Rio de Janeiro", "RJ02", "Rio de Janeiro",
        6000000, 1182.30f, 300000.0f, 15,
        0.0f, 0.0f
    };

    // Cadastra e calcula os atributos derivados
    cadastrarCarta(&carta1);
    cadastrarCarta(&carta2);

    // Escolha do atributo para comparação (alterar como desejar)
    // Opções: 1=população, 2=área, 3=PIB, 4=densidade, 5=pib_per_capita
    int atributo = 1;

    // Exibe qual atributo será comparado
    char nomeAtributo[30];
    switch (atributo) {
        case 1: strcpy(nomeAtributo, "População"); break;
        case 2: strcpy(nomeAtributo, "Área"); break;
        case 3: strcpy(nomeAtributo, "PIB"); break;
        case 4: strcpy(nomeAtributo, "Densidade Populacional"); break;
        case 5: strcpy(nomeAtributo, "PIB per capita"); break;
        default: strcpy(nomeAtributo, "Desconhecido"); break;
    }
    printf("Comparação de cartas (Atributo: %s)\n\n", nomeAtributo);

    // Obtém os valores do atributo selecionado
    float valor1, valor2;
    switch (atributo) {
        case 1:
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            break;
        case 2:
            valor1 = carta1.area;
            valor2 = carta2.area;
            break;
        case 3:
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            break;
        case 4:
            valor1 = carta1.densidade;
            valor2 = carta2.densidade;
            break;
        case 5:
            valor1 = carta1.pib_per_capita;
            valor2 = carta2.pib_per_capita;
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }

    // Exibe os valores das cartas
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.codigo, valor1);
    printf("Carta 2 - %s (%s): %.2f\n\n", carta2.nome, carta2.codigo, valor2);

    // Verifica o vencedor
    int venceu1 = 0, venceu2 = 0;
    if (atributo == 4) {
        // Densidade: quem tiver menor valor vence
        if (valor1 < valor2) venceu1 = 1;
        else if (valor2 < valor1) venceu2 = 1;
    } else {
        // Nos outros atributos, maior valor vence
        if (valor1 > valor2) venceu1 = 1;
        else if (valor2 > valor1) venceu2 = 1;
    }

    // Exibe resultado final
    if (venceu1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (venceu2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
