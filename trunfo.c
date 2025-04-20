/*
Carta 1:

Estado: A

Código: A01

Nome da Cidade: São Paulo

População: 12325000

Área: 1521.11 km²

PIB: 699.28 bilhões de reais

Número de Pontos Turísticos: 50

 

Carta 2:

Estado: B

Código: B02

Nome da Cidade: Rio de Janeiro

População: 6748000

Área: 1200.25 km²

PIB: 300.50 bilhões de reais

Número de Pontos Turísticos: 30  
*/

#include <stdio.h>

    int main(){

        // Declaração de variáveis
        char estado1[50], estado2[50], codigo1[4], codigo2[4], nome_cidade1[50], nome_cidade2[50];
        int populacao1, populacao2, pontos_turisticos1, pontos_turisticos2;
        float area1, area2, pib1, pib2;

        // Lendo os dados da primeira carta
        printf("Digite o estado: ");
        scanf("%s", estado1);
        printf("Digite o código: ");
        scanf("%4s", codigo1);
        printf("Digite o nome da cidade: ");
        scanf("%s", nome_cidade1);
        printf("Digite a população: ");
        scanf("%d", &populacao1);
        getchar();
        printf("Digite a área (em km²): ");
        scanf("%f", &area1);
        getchar();
        printf("Digite o PIB (em bilhões de reais): ");
        scanf("%f", &pib1);
        getchar();
        printf("Digite o número de pontos turísticos: ");
        scanf("%d", &pontos_turisticos1);
        getchar();

        // Lendo os dados da segunda carta

          printf("Digite o estado: ");
          scanf("%s", estado2);
          printf("Digite o código: ");
          scanf("%4s", codigo2); 
          printf("Digite o nome da cidade: ");
          scanf("%s", nome_cidade2);
          printf("Digite a população: ");
          scanf("%d", &populacao2);
          printf("Digite a área (em km²): ");
          scanf("%f", &area2);
          printf("Digite o PIB (em bilhões de reais): ");
          scanf("%f", &pib2);
          printf("Digite o número de pontos turísticos: ");
          scanf("%d", &pontos_turisticos2);

        // Exibindo as duas cartas
        printf("\n**Dados da primeira carta:**\n");
        printf("\nEstado: %s\n", estado1);
        printf("Código: %s\n", codigo1);
        printf("Nome da Cidade: %s\n", nome_cidade1);
        printf("População: %d\n", populacao1);
        printf("Área: %.2f km²\n", area1);
        printf("PIB: %.2f bilhões de reais\n", pib1);
        printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);

        printf("\n**Dados da segunda carta:**\n");
        printf("\nEstado: %s\n", estado2);
        printf("Código: %s\n", codigo2);
        printf("Nome da Cidade: %s\n", nome_cidade2);
        printf("População: %d\n", populacao2);
        printf("Área: %.2f km²\n", area2);
        printf("PIB: %.2f bilhões de reais\n", pib2);
        printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);

    
        return 0;
    }


// Mudanças a fazer -> Colocar Nome de Estados completos(ler com espaços e caracteres especiais)
// Fazer o aventureiro e o mestre
// Mudar para Lógica do trunfo