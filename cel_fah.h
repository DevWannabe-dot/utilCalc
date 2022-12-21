#pragma once

#ifndef __CEL_FAH_h__
#define __CEL_FAH_h__

// Inclusões
#include <stdio.h>
#include "erros.h"

// Constantes

// Tipos

// Funções

// C -> F
float CF(float C) {
	return((C * 1.8f) + 32.0f);
}
// F -> C
float FC(float F) {
	return(((F - 32) * 5) / 9);
}
// MAIN
int main_cel_fah(void) {

	int tipo = 3, tamanhoVetor, i;
	float temperatura, temperaturas[100], F, C;

	do {
		switch (tipo) {
		case 0:
			printf("Voce escolheu sair.");
			break;

		case 1:
			printf("\nInsere um valor em graus Centigrados (C): ");
			if (scanf("%f", &temperatura)) printf("\n%.2fC = %.2fF\n", temperatura, CF(temperatura));;
			tipo = 3;
			break;

		case 2:
			printf("\nInsere um valor em graus Fahrenheit (F): ");
			if (scanf("%f", &temperatura)) printf("\n%.2fF = %.2fC\n", temperatura, FC(temperatura));;
			tipo = 3;
			break;

		case 3:
			printf("\n\n\t1 para conversao C -> F ............... 2 para conversao F -> C\n\t4 para opcao 1 em massa  .............. 5 para opcao 2 em massa\n\t........................0 para encerrar........................\n");
			if (scanf("%d", &tipo)) break;
			break;

		case 4:
			printf("\nCom quantas temperaturas deseja trabalhar (no maximo 100 por vez)? ");
			if (scanf("%d", &tamanhoVetor)) printf("\nInsere varios valores em graus Centigrados (C) separados por espaco, <enter> para submeteres: ");

			for (i = 0; i < tamanhoVetor; i++) {
				printf("\nValor [%d]: ", (i + 1));
				if (scanf("%f", &temperaturas[i])) continue;
			}

			for (i = 0; i < tamanhoVetor; i++) {
				F = (temperaturas[i] * 1.8f) + 32.0f;
				printf("\n%7.1fC = %7.1fF", temperaturas[i], F);
			}

			tipo = 3;
			break;

		case 5:
			printf("\nCom quantas temperaturas deseja trabalhar (no maximo 100 por vez)? ");
			(void)scanf("%d", &tamanhoVetor);
			printf("\nInsere varios valores em graus Fahrenheit (F) separados por espaco, <enter> para submeteres: ");

			for (i = 0; i < tamanhoVetor; i++) {
				printf("\nValor [%d]: ", (i + 1));
				if (scanf("%f", &temperaturas[i])) continue;
			}

			for (i = 0; i < tamanhoVetor; i++) {
				C = ((temperaturas[i] - 32) * 5) / 9;
				printf("\n%7.1fF = %7.1fC", temperaturas[i], C);
			}

			tipo = 3;
			break;

		default:
			printf("Erro desconhecido");
			break;
		}
	} while (tipo != 0);

	return SUCESSO;
}

#endif