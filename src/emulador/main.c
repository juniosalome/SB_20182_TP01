#include "func.h"

/*
 * Junio Leonardo Soares Salome 2013007528
 */

int main(int argc, char * argv[]){
	/*Inicialização dos argumentos*/

	//Valor Inicial de PC
	PC = atoi(argv[1]); 

	//Valor de AP
	AP = atoi(argv[2]);

	//Posição Inicial da Memoria.
	PosicaoMemoria = atoi(argv[3]); 

	//Modo de exibicao
	mododeexibir = (char)*argv[4];

	//Recebe nome do arquivo teste
	nomearq = argv[5];
	



	/*
	 *Variaveis para sistema
	 */
	PEP[0]='0';
        PEP[1]='0';
        int halt = 0;
        int instrucao;
        /*
	 *Carrega programa na memoria.
	 */
        Inicializa(nomearq); 

	/*
         *Maquina Virtual.
         */
	while(halt == 0){
        	instrucao = memory[PosicaoMemoria + PC]; // primeira instrucao.
        	PC = PC + 1; //Aponta para proxima instrucao.
		if (mododeexibir == 'v'){
			printf("PC = %d, AP = %d, PEP= %c %c, instrucao %d\n",PC,AP,PEP[0],PEP[1],instrucao);
	        	printf("Register R0 \tR1  \tR2  \tR3  \tR4  \tR5  \tR6  \tR7\n");
	        	printf("         %d  \t%d  \t%d  \t%d  \t%d  \t%d  \t%d  \t%d \n",reg[0],reg[1],reg[2],reg[3],reg[4],reg[5],reg[6], reg[7]);
		}  
	        halt = Executa_Instrucao(instrucao);
    }
    return 0;
}


