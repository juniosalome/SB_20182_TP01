#include <stdio.h>
#include <stdlib.h>

#ifndef FUNC_H
#define FUNC_H


/*
 * Junio Leonardo Soares Salome 2013007528
 */


//Variaveis globais
int memory[1000];
int reg[8];
int PC;
int AP;
int PosicaoMemoria; //Posicao inicial da memoria.
char PEP[2];

char mododeexibir; //para verificar de e verboso ou nao
char *nomearq;


/*Le o arquivo e carrega as entradas entradas
 */
void Inicializa(char *nome_arquivo);

/*Executa as instruções
 */
int Executa_Instrucao(int instrucao);

/*ADD
 *
 *Soma dois registradores
 *
 */
void funcao_add();

/*SUB
 *
 *Subtrai dois registradores
 *
 */
void funcao_sub();

/*AND
 *
 *AND (bit a bit) de dois registradores
 *
 */
void funcao_and();

/*OR
 *
 *OR (bit a bit) de dois registradores
 *
 */
void funcao_or();

/*XOR
 *
 *XOR (bit a bit) de dois registradores
 *
 */
void funcao_xor();

/*NOT
 *
 *NOT (bit a bit) de um registrador
 *
 */
void funcao_not();

/*JUMP
 *
 *Desvio incondicional
 *
 */
void funcao_jump();

/*JZ
 *
 *Desvia se zero
 *
 */
void funcao_jz();

/*JNZ
 *
 *Desvia se não zero
 *
 */
void funcao_jnz();

/*JN
 *
 *Desvia se negativo
 *
 */
void funcao_jn();

/*JNN
 *
 *Desvia se não negativo
 *
 */
void funcao_jnn();

/*PUSH
 *
 *Empilha valor do registrador
 *
 */
void funcao_push();

/*POP
 *
 *Desempilha valor no registrador
 *
 */
void funcao_pop();

/*CALL
 *
 *Chamada de subrotina
 *
 */
void funcao_call();

/*LOAD
 *
 *Carrega Registrador
 *
 */
void funcao_load();

/*STORE
 *
 *Armazena Registrador
 *
 */
void funcao_store();

/*READ
 *
 *Le valor para registrador
 *
 */
void funcao_read();    

/*WRITE
 *
 *Escreve conteúdo do registrador
 *
 */
void funcao_write();

/*COPY
 *
 *Copia registrador
 *
 */
void funcao_copy();

/*RET
 *
 *Retorno de subrotina
 *
 */
void funcao_ret();

#endif
