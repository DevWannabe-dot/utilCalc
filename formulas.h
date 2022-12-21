#pragma once

#ifndef __FORMULAS_h__
#define __FORMULAS_h__

// Inclus�es
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "erros.h"

// Tipos

// Constantes

// Fun��es
void condicao_IMC(float IMC) {
	if (IMC < 18) {
		printf("Abaixo do peso.");
	}
	else if (IMC > 18 && IMC < 25) {
		printf("�ndice de m�ssa corp�reo adequado, dentro do c�lculo.");
	}
	else if (IMC > 25 && IMC < 30) {
		printf("Situa��o de sobrepeso.");
	}
	else if (IMC > 30 && IMC < 40) {
		printf("Situa��o de obesidade.");
	}
	else fprintf(stderr, "\nErro <%i> no valor do IMC.\n", ERRO_IMC);
}

int main_IMC(void) {
	float altura = 0.0f, massa = 0.0f, IMC = 0.0f;
	char lixo;

	setlocale(LC_ALL, "");

	do {
		printf("\nInsira a altura de interesse, em cm (SI): ");
		if (scanf("%f%c", &altura, &lixo)) {
			if (!altura) continue;
			printf("\nBem-feito! Agora insira o peso de interesse, em kg (SI): ");
			if (scanf("%f%c", &massa, &lixo)) {
				if (!massa) continue;
			}
		}
		break;
	} while (1);

	altura /= 100.0f;				// Convers�o para metro
	altura = (float)pow(altura, 2); // altura^2

	IMC = (massa / altura);
	condicao_IMC(IMC);
	printf("\nSeu IMC � de %.1f!\n", IMC);

	return SUCESSO;
}

#endif