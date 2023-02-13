#include "func.h"

/*
 * Junio Leonardo Soares Salome 2013007528
 */

void Inicializa(char *nome_arquivo) {

	FILE *ArquivoEntrada;
	ArquivoEntrada = fopen(nome_arquivo, "r");
	if (ArquivoEntrada == NULL) {
		printf("\nArquivo com o nome ' %s ' não encontrado.......\n",
				nome_arquivo);
		exit(0);
	}

	int i;
	i = PosicaoMemoria;
	while (!feof(ArquivoEntrada)) {
		fscanf(ArquivoEntrada, "%d", &memory[i]);
		i++;
	}

	fclose(ArquivoEntrada);

}

void funcao_add() {

	int primeiro = 0, segundo = 0;
	primeiro = memory[PC];
	PC++;
	segundo = memory[PC];
	PC++;
	reg[primeiro] = reg[primeiro] + reg[segundo];
	PEP[0] = '0';
	PEP[1] = '0';
	if (reg[primeiro] == 0) {
		PEP[0] = '1';
	} else {
		if (reg[primeiro] < 0) {
			PEP[1] = '1';
		}
	}
}

void funcao_or() {
	int primeiro = 0, segundo = 0;
	primeiro = memory[PC];
	PC++;
	segundo = memory[PC];
	PC++;
	reg[primeiro] = reg[primeiro] | reg[segundo];
	PEP[0] = '0';
	PEP[1] = '0';
	if (reg[primeiro] == 0) {
		PEP[0] = '1';
	} else {
		if (reg[primeiro] < 0) {
			PEP[1] = '1';
		}
	}

}

void funcao_sub() {
	int primeiro = 0, segundo = 0;
	primeiro = memory[PC];
	PC++;
	segundo = memory[PC];
	PC++;
	reg[primeiro] = reg[primeiro] - reg[segundo];
	PEP[0] = '0';
	PEP[1] = '0';
	if (reg[primeiro] == 0) {
		PEP[0] = '1';
	} else {
		if (reg[primeiro] < 0) {
			PEP[1] = '1';
		}
	}
}

void funcao_and() {
	int primeiro = 0, segundo = 0;
	primeiro = memory[PC];
	PC++;
	segundo = memory[PC];
	PC++;
	reg[primeiro] = reg[primeiro] & reg[segundo];
	PEP[0] = '0';
	PEP[1] = '0';
	if (reg[primeiro] == 0) {
		PEP[0] = '1';
	} else {
		if (reg[primeiro] < 0) {
			PEP[1] = '1';
		}
	}
}

void funcao_xor() {
	int primeiro = 0, segundo = 0;
	primeiro = memory[PC];
	PC++;
	segundo = memory[PC];
	PC++;
	reg[primeiro] = reg[primeiro] ^ reg[segundo];
	PEP[0] = '0';
	PEP[1] = '0';
	if (reg[primeiro] == 0) {
		PEP[0] = '1';
	} else {
		if (reg[primeiro] < 0) {
			PEP[1] = '1';
		}
	}
}

void funcao_not() {
	int primeiro = 0;
	primeiro = memory[PC];
	PC++;
	reg[primeiro] = ~(reg[primeiro]);
	PEP[0] = '0';
	PEP[1] = '0';
	if (reg[primeiro] == 0) {
		PEP[0] = '1';
	} else {
		if (reg[primeiro] < 0) {
			PEP[1] = '1';
		}
	}

}

void funcao_jump() {
	int primeiro = 0;
	primeiro = memory[PC];
	PC++;
	PC = PC + primeiro;
}

void funcao_jnz() {
	int primeiro = 0;
	primeiro = memory[PC];
	PC++;
	if (PEP[0] != '1') {
		PC = PC + primeiro;
	}
}

void funcao_jz() {
	int primeiro = 0;
	primeiro = memory[PC];
	PC++;
	if (PEP[0] == '1') {
		PC = PC + primeiro;
	}
}

void funcao_ret() {
	PC = memory[AP];
	AP = AP + 1;
}

void funcao_jn() {
	int primeiro = 0;
	primeiro = memory[PC];
	PC++;
	if (PEP[1] == '1') {
		PC = PC + primeiro;
	}
}

void funcao_jnn() {
	int primeiro = 0;
	primeiro = memory[PC];
	PC++;
	if (PEP[1] != '1') {
		PC = PC + primeiro;
	}
}

void funcao_pop() {
	int primeiro = 0;
	primeiro = memory[PC];
	PC++;
	reg[primeiro] = memory[AP];
	AP++;
}

void funcao_push() {
	int primeiro = 0;
	AP--;
	primeiro = memory[PC];
	PC++;
	memory[AP] = reg[primeiro];
}

void funcao_call() {
	int segundo = 0;
	AP--;
	segundo = memory[PC];
	PC++;
	memory[AP] = PC;
	PC = PC + segundo;
}

void funcao_load() {
	int primeiro = 0, segundo = 0;
	primeiro = memory[PC];
	PC++;
	segundo = memory[PC];
	PC++;
	reg[primeiro] = memory[segundo + PC];
}

void funcao_store() {
	int primeiro = 0, segundo = 0;
	primeiro = memory[PC];
	PC++;
	segundo = memory[PC];
	PC++;
	memory[segundo + PC] = reg[primeiro];
}

void funcao_read() {
	int valor_lido = 0, primeiro = 0;
	primeiro = memory[PC];
	PC++;
	scanf("%d%*c", &valor_lido);
	reg[primeiro] = valor_lido;
}

void funcao_write() {
	int primeiro = 0;
	primeiro = memory[PC];
	PC++;
	printf("%d\n", reg[primeiro]);
}

void funcao_copy() {
	int primeiro = 0, segundo = 0;
	primeiro = memory[PC];
	PC++;
	segundo = memory[PC];
	PC++;
	reg[primeiro] = reg[segundo];
	PEP[0] = '0';
	PEP[1] = '0';
	if (reg[primeiro] == 0) {
		PEP[0] = '1';
	} else {
		if (reg[primeiro] < 0) {
			PEP[1] = '1';
		}
	}
}

int Executa_Instrucao(int instrucao) {

	switch (instrucao) {

	/*ADD*/
	case 1:
		funcao_add();
		break;

		/*SUB*/
	case 2:
		funcao_sub();
		break;

		/*AND*/
	case 3:
		funcao_and();
		break;

		/*OR*/
	case 4:
		funcao_or();
		break;

		/*XOR*/
	case 5:
		funcao_xor();
		break;

		/*NOT*/
	case 6:
		funcao_not();
		break;

		/*JUMP*/
	case 7:
		funcao_jump();
		break;

		/*JZ*/
	case 8:
		funcao_jz();
		break;

		/*JNZ*/
	case 9:
		funcao_jnz();
		break;

		/*JN*/
	case 10:
		funcao_jn();
		break;

		/*JNN*/
	case 11:
		funcao_jnn();
		break;

		/*PUSH*/
	case 12:
		funcao_push();
		break;

		/*POP*/
	case 13:
		funcao_pop();
		break;

		/*CALL*/
	case 14:
		funcao_call();
		break;

		/*LOAD*/
	case 15:
		funcao_load();
		break;

		/*STORE*/
	case 16:
		funcao_store();
		break;

		/*READ*/
	case 17:
		funcao_read();
		break;

		/*WRITE*/
	case 18:
		funcao_write();
		break;

		/*COPY*/
	case 19:
		funcao_copy();
		break;

		/*RET*/
	case 20:
		funcao_ret();
		break;

		/*HALT*/
	case 21:
		/*
		 *Parada
		 *
		 *Retorna 1 para finalizar o programa
		 */
		return 1;
		break;
	}
	return 0;
}

