/*
 * Super Trunfo - Paises
 * Nivel: Aventureiro
 * Descricao: Cadastro de duas cartas com dados de cidades.
 *            Calcula e exibe densidade populacional e PIB per capita.
 * Autor: Pedro
 */

#include <stdio.h>  /* Biblioteca padrao de entrada e saida */

int main() {

    /* --------------------------------------------------------
     * DECLARACAO DAS VARIAVEIS - CARTA 1
     * densidade e pib_per_capita sao calculados, nao lidos
     * -------------------------------------------------------- */
    char  estado1;
    char  codigo1[4];
    char  cidade1[50];
    int   populacao1;
    float area1;
    float pib1;
    int   pontos1;
    float densidade1;       /* populacao / area → hab/km²          */
    float pib_per_capita1;  /* (pib * 1bi) / populacao → R$/hab    */

    /* --------------------------------------------------------
     * DECLARACAO DAS VARIAVEIS - CARTA 2
     * -------------------------------------------------------- */
    char  estado2;
    char  codigo2[4];
    char  cidade2[50];
    int   populacao2;
    float area2;
    float pib2;
    int   pontos2;
    float densidade2;
    float pib_per_capita2;

    /* --------------------------------------------------------
     * ENTRADA DE DADOS - CARTA 1
     * scanf le do teclado e armazena no endereco da variavel (&)
     * %[^\n] le nome completo incluindo espacos
     * -------------------------------------------------------- */
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado (letra A a H): ");
    scanf(" %c", &estado1);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("Populacao: ");
    scanf("%d", &populacao1);

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
    scanf("%d", &populacao2);

    printf("Area em km2: ");
    scanf("%f", &area2);

    printf("PIB em bilhoes de reais: ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos2);

    /* --------------------------------------------------------
     * PROCESSAMENTO - CALCULOS (modulo entrada → processamento → saida)
     *
     * densidade = populacao / area
     *   Cast (float) em populacao evita divisao inteira:
     *   sem cast: 12325000 / 1521.11 funcionaria pois area ja e float,
     *   mas o cast deixa a intencao explicita e evita bugs futuros.
     *
     * pib_per_capita = pib (em bilhoes) convertido para reais / populacao
     *   pib esta em bilhoes → multiplica por 1.000.000.000 antes de dividir
     *   1000000000.0f garante que a multiplicacao seja em ponto flutuante
     * -------------------------------------------------------- */
    densidade1      = (float)populacao1 / area1;
    pib_per_capita1 = (pib1 * 1000000000.0f) / (float)populacao1;

    densidade2      = (float)populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000.0f) / (float)populacao2;

    /* --------------------------------------------------------
     * SAIDA DE DADOS
     * %.2f exibe float com exatamente 2 casas decimais
     * -------------------------------------------------------- */
    printf("\n=========================================\n");

    printf("Carta 1:\n");
    printf("Estado: %c\n",                          estado1);
    printf("Codigo: %s\n",                          codigo1);
    printf("Nome da Cidade: %s\n",                  cidade1);
    printf("Populacao: %d\n",                       populacao1);
    printf("Area: %.2f km2\n",                      area1);
    printf("PIB: %.2f bilhoes de reais\n",          pib1);
    printf("Numero de Pontos Turisticos: %d\n",     pontos1);
    printf("Densidade Populacional: %.2f hab/km2\n",densidade1);
    printf("PIB per Capita: %.2f reais\n",          pib_per_capita1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n",                          estado2);
    printf("Codigo: %s\n",                          codigo2);
    printf("Nome da Cidade: %s\n",                  cidade2);
    printf("Populacao: %d\n",                       populacao2);
    printf("Area: %.2f km2\n",                      area2);
    printf("PIB: %.2f bilhoes de reais\n",          pib2);
    printf("Numero de Pontos Turisticos: %d\n",     pontos2);
    printf("Densidade Populacional: %.2f hab/km2\n",densidade2);
    printf("PIB per Capita: %.2f reais\n",          pib_per_capita2);

    printf("=========================================\n");

    return 0;  /* 0 = programa encerrado com sucesso */
}