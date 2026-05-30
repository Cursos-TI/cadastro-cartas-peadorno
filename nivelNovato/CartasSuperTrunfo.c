/*
 * Super Trunfo - Paises
 * Nivel: Novato
 * Descricao: Cadastro de duas cartas com dados de cidades.
 *            Le os dados via teclado e exibe de forma organizada.
 * Autor: Pedro
 */

#include <stdio.h>  /* Biblioteca padrao de entrada e saida (printf, scanf) */

int main() {

    /* --------------------------------------------------------
     * DECLARACAO DAS VARIAVEIS - CARTA 1
     * Cada variavel armazena um atributo da carta na memoria RAM
     * -------------------------------------------------------- */
    char  estado1;        /* Letra do estado: A a H              */
    char  codigo1[4];     /* Codigo da carta: ex A01 (3 chars + \0) */
    char  cidade1[50];    /* Nome da cidade: ate 49 caracteres   */
    int   populacao1;     /* Populacao em numero de habitantes   */
    float area1;          /* Area em km quadrados                */
    float pib1;           /* PIB em bilhoes de reais             */
    int   pontos1;        /* Numero de pontos turisticos         */

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

    /* --------------------------------------------------------
     * ENTRADA DE DADOS - CARTA 1
     * scanf le do teclado e armazena no endereco da variavel (&)
     * O espaco antes de %c e %[^\n] descarta o \n do buffer
     * %[^\n] le tudo ate o Enter, incluindo espacos no nome
     * -------------------------------------------------------- */
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado (letra A a H): ");
    scanf(" %c", &estado1);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);               /* strings nao usam & */

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);          /* le nome com espacos */

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
     * Mesma logica da Carta 1
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
     * EXIBICAO DOS DADOS
     * printf com especificadores de formato:
     *   %c  -> char        %s  -> string
     *   %d  -> int         %.2f -> float com 2 casas decimais
     * -------------------------------------------------------- */
    printf("\n=========================================\n");

    printf("Carta 1:\n");
    printf("Estado: %c\n",                    estado1);
    printf("Codigo: %s\n",                    codigo1);
    printf("Nome da Cidade: %s\n",            cidade1);
    printf("Populacao: %d\n",                 populacao1);
    printf("Area: %.2f km2\n",                area1);
    printf("PIB: %.2f bilhoes de reais\n",    pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontos1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n",                    estado2);
    printf("Codigo: %s\n",                    codigo2);
    printf("Nome da Cidade: %s\n",            cidade2);
    printf("Populacao: %d\n",                 populacao2);
    printf("Area: %.2f km2\n",                area2);
    printf("PIB: %.2f bilhoes de reais\n",    pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontos2);

    printf("=========================================\n");

    return 0;  /* Retorna 0 ao sistema operacional: programa encerrado com sucesso */
}
