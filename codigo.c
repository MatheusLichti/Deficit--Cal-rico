#include <stdio.h>

int main() {
    int sexo, idade, objetivo;
    float peso, imc, imcIdeal, tmb, caloriasRecomendadas, altura;

    printf("=== Calculadora de IMC com Recomendação de Dieta ===\n");

    printf("Digite 1 para Homem ou 2 para Mulher: ");
    scanf("%d", &sexo);
    if (sexo != 1 && sexo != 2) {
        printf("Opção inválida. Use 1 para Homem ou 2 para Mulher.\n");
        return 1;
    }

    printf("Digite a idade: ");
    scanf("%d", &idade);

    printf("Digite a altura (em metros): ");
    scanf("%f", &altura);

    printf("Digite o peso (em kg): ");
    scanf(" %f", &peso);

    if (altura <= 0 || peso <= 0) {
        printf("Altura e peso devem ser positivos.\n");
        return 1;
    }

    imc = peso / (altura * altura);

    if (sexo == 1) {
        imcIdeal = (0.5 * imc) + (0.03 * idade) + 11.5;
    } else {
        imcIdeal = (0.5 * imc) + (0.03 * idade) + 10.5;
    }

    printf("\nSeu IMC e: %.2f\n", imc);
    printf("IMC ideal estimado: %.2f\n", imcIdeal);

    printf("\nEscolha seu objetivo:\n");
    printf("1 - Perder peso\n");
    printf("2 - Ganhar massa muscular\n");
    printf("Opcao: ");
    scanf("%d", &objetivo);

    if (objetivo != 1 && objetivo != 2) {
        printf("Objetivo invalido.\n");
        return 1;
    }

    float altura_cm = altura * 100;
    if (sexo == 1) {
        tmb = 10 * peso + 6.25 * altura_cm - 5 * idade + 5;
    } else {
        tmb = 10 * peso + 6.25 * altura_cm - 5 * idade - 161;
    }

    if (objetivo == 1) {
        caloriasRecomendadas = tmb - 500;
    } else {
        caloriasRecomendadas = tmb + 300;
    }

    printf("\nRecomendaçoes:\n");
    if (objetivo == 1) {
        printf("Objetivo: Perda de peso\n");
        if (imc <= imcIdeal - 1)
            printf("Atencao: Voce je este abaixo do IMC ideal.\n");
        printf("Recomenda-se uma dieta com déficit calorico.\n");
    } else {
        printf("Objetivo: Ganho de massa muscular\n");
        if (imc >= imcIdeal + 2)
            printf("Atencao: IMC elevado. Avalie antes o emagrecimento.\n");
        printf("Recomenda-se uma dieta com superavit calorico.\n");
    }

    printf("TMB estimada: %.2f kcal/dia\n", tmb);
    printf("Calorias recomendadas por dia: %.2f kcal\n", caloriasRecomendadas);

    return 0;
}
