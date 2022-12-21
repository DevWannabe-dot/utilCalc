// Inclusões

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <locale.h>
#include "erros.h"
#include "formulas.h"
#include "cel_fah.h"

// Tipos
typedef uint8_t bool_t;

// Constantes

// -----------------------------------------------------------------
int main(int argc, char** argv) {
	int opcao;
	char lixo;
	
	// Define a linguagem local para suportar acentos
	setlocale(LC_ALL, "");
	
	// Interação com o usuário
		do {
			printf("\nSeja bem-vindo à calculadora! Qual do nossos calculos desejas testar?\n"
				"0	|	SAIR\n"
				"1	|	Cálculo IMC\n"
				"2	|	Cálculo Fahrenheit-Celsius\n"
				">> ");
			if (scanf("%i%c", &opcao, &lixo) == 2) {
				switch (opcao) {
				case 0:
					fprintf(stdout, "\nVocê escolheu sair.\n\a\a");
					break;
				case 1:
					if (main_IMC() != 0) fprintf(stderr, "\nErro <%i> desconhecido em IMC.\n", ERRO_IMC);
					break;
				case 2:
					if(main_cel_fah() != 0) fprintf(stderr, "\nErro <%i> desconhecido em Celsius-Fahrenheit.\n", ERRO_CEL_FAH);
					break;
				default:
					fprintf(stderr, "\nErro <%i> na leitura da opcao.\n", ERRO_LENDO_OPCAO);
					break;
				}
			}
		} while (opcao != 0);

	return SUCESSO;
}