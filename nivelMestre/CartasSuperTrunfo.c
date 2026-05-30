/*
 * Super Trunfo - Paises
 * Nivel: Mestre
 * Descricao: Cadastro, calculo e comparacao de duas cartas.
 *            Inclui Super Poder e comparacao atributo por atributo.
 * Autor: Pedro
 */

#include <stdio.h>

int main() {

    /* --------------------------------------------------------
     * DECLARACAO DAS VARIAVEIS - CARTA 1
     * populacao: unsigned long int → faixa 0 a 18 quintilhoes
     * especificador de formato: %lu
     * -------------------------------------------------------- */
    char              estado1;
    char              codigo1[4];
    char              cidade1[50];
    unsigned long int populacao1;
    float             area1;
    float             pib1;
    int               pontos1;
    float             densidade1;
    float             pib_per_capita1;
    float             super_poder1;

    /* --------------------------------------------------------
     * DECLARACAO DAS VARIAVEIS - CARTA 2
     * -------------------------------------------------------- */
    char              estado2;
    char              codigo2[4];
    char              cidade2[50];
    unsigned long int populacao2;
    float             area2;
    float             pib2;
    int               pontos2;
    float             densidade2;
    float             pib_per_capita2;
    float             super_poder2;

    /* Resultados das comparacoes: 1 = Carta 1 vence | 0 = Carta 2 vence */
    int resultado_populacao;
    int resultado_area;
    int resultado_pib;
    int resultado_pontos;
    int resultado_densidade;
    int resultado_pib_per_capita;
    int resultado_super_poder;

    /* --------------------------------------------------------
     * ENTRADA DE DADOS - CARTA 1
     * %lu e o especificador correto para unsigned long int
     * -------------------------------------------------------- */
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado (letra A a H): ");
    scanf(" %c", &estado1);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area em km2: ");
    scanf("%f", &area1);

    printf("PIB em bilhoes de reais: ");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos1);

    /* --------------------------------------------------------
     * ENTRADA DE DADOS - CARTA 2
     * -------------------------------------------------------- */
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado (letra A a H): ");
    scanf(" %c", &estado2);

    printf("Codigo da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area em km2: ");
    scanf("%f", &area2);

    printf("PIB em bilhoes de reais: ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos2);

    /* --------------------------------------------------------
     * PROCESSAMENTO - ETAPA 1: densidade e PIB per capita
     * Cast (float) em populacao evita problemas de conversao
     * pib em bilhoes → multiplica por 1bi antes de dividir
     * -------------------------------------------------------- */
    densidade1      = (float)populacao1 / area1;
    densidade2      = (float)populacao2 / area2;

    pib_per_capita1 = (pib1 * 1000000000.0f) / (float)populacao1;
    pib_per_capita2 = (pib2 * 1000000000.0f) / (float)populacao2;

    /* --------------------------------------------------------
     * PROCESSAMENTO - ETAPA 2: Super Poder
     * Formula: populacao + area + pib + pontos +
     *          pib_per_capita + (1 / densidade)
     *
     * O inverso da densidade (1/densidade) garante que
     * cidades menos densas contribuem mais para o Super Poder,
     * coerente com a regra: menor densidade = vantagem.
     *
     * Casts explicitos em populacao (unsigned long int → float)
     * e pontos (int → float) para garantir soma correta.
     * -------------------------------------------------------- */
    super_poder1 = (float)populacao1 + area1 + pib1 +
                   (float)pontos1 + pib_per_capita1 +
                   (1.0f / densidade1);

    super_poder2 = (float)populacao2 + area2 + pib2 +
                   (float)pontos2 + pib_per_capita2 +
                   (1.0f / densidade2);

    /* --------------------------------------------------------
     * PROCESSAMENTO - ETAPA 3: comparacoes
     * Operadores relacionais retornam 1 (verdadeiro) ou 0 (falso)
     * Densidade: MENOR vence → operador invertido (<)
     * Todos os outros: MAIOR vence → operador (>)
     * -------------------------------------------------------- */
    resultado_populacao      = populacao1 > populacao2;
    resultado_area           = area1 > area2;
    resultado_pib            = pib1 > pib2;
    resultado_pontos         = pontos1 > pontos2;
    resultado_densidade      = densidade1 < densidade2; /* menor vence */
    resultado_pib_per_capita = pib_per_capita1 > pib_per_capita2;
    resultado_super_poder    = super_poder1 > super_poder2;

    /* --------------------------------------------------------
     * SAIDA - dados completos das cartas
     * -------------------------------------------------------- */
    printf("\n=========================================\n");

    printf("Carta 1:\n");
    printf("Estado: %c\n",                           estado1);
    printf("Codigo: %s\n",                           codigo1);
    printf("Nome da Cidade: %s\n",                   cidade1);
    printf("Populacao: %lu\n",                       populacao1);
    printf("Area: %.2f km2\n",                       area1);
    printf("PIB: %.2f bilhoes de reais\n",           pib1);
    printf("Numero de Pontos Turisticos: %d\n",      pontos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
    printf("PIB per Capita: %.2f reais\n",           pib_per_capita1);
    printf("Super Poder: %.2f\n",                    super_poder1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n",                           estado2);
    printf("Codigo: %s\n",                           codigo2);
    printf("Nome da Cidade: %s\n",                   cidade2);
    printf("Populacao: %lu\n",                       populacao2);
    printf("Area: %.2f km2\n",                       area2);
    printf("PIB: %.2f bilhoes de reais\n",           pib2);
    printf("Numero de Pontos Turisticos: %d\n",      pontos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per Capita: %.2f reais\n",           pib_per_capita2);
    printf("Super Poder: %.2f\n",                    super_poder2);

    /* --------------------------------------------------------
     * SAIDA - resultados das comparacoes
     * if/else usa o resultado (0 ou 1) para decidir o texto
     * O numero entre parenteses e o proprio resultado relacional
     * -------------------------------------------------------- */
    printf("\n=========================================\n");
    printf("Comparacao de Cartas:\n");

    if (resultado_populacao == 1) {
        printf("Populacao: Carta 1 venceu (%d)\n", resultado_populacao);
    } else {
        printf("Populacao: Carta 2 venceu (%d)\n", resultado_populacao);
    }

    if (resultado_area == 1) {
        printf("Area: Carta 1 venceu (%d)\n", resultado_area);
    } else {
        printf("Area: Carta 2 venceu (%d)\n", resultado_area);
    }

    if (resultado_pib == 1) {
        printf("PIB: Carta 1 venceu (%d)\n", resultado_pib);
    } else {
        printf("PIB: Carta 2 venceu (%d)\n", resultado_pib);
    }

    if (resultado_pontos == 1) {
        printf("Pontos Turisticos: Carta 1 venceu (%d)\n", resultado_pontos);
    } else {
        printf("Pontos Turisticos: Carta 2 venceu (%d)\n", resultado_pontos);
    }

    /* Densidade: menor vence — o if verifica se Carta 1 tem MENOR densidade */
    if (resultado_densidade == 1) {
        printf("Densidade Populacional: Carta 1 venceu (%d)\n", resultado_densidade);
    } else {
        printf("Densidade Populacional: Carta 2 venceu (%d)\n", resultado_densidade);
    }

    if (resultado_pib_per_capita == 1) {
        printf("PIB per Capita: Carta 1 venceu (%d)\n", resultado_pib_per_capita);
    } else {
        printf("PIB per Capita: Carta 2 venceu (%d)\n", resultado_pib_per_capita);
    }

    if (resultado_super_poder == 1) {
        printf("Super Poder: Carta 1 venceu (%d)\n", resultado_super_poder);
    } else {
        printf("Super Poder: Carta 2 venceu (%d)\n", resultado_super_poder);
    }

    printf("=========================================\n");

    return 0;
}