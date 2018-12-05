#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{

FILE    *infile_nome;

char    *nome_buffer;//buffer
char	nome[60];
char	cpf[22];
char	nome_txt[51];
char	rg[14];
char	data[35];
char	pais[150];
char	k;
int 	fp, i;
long    numbytes;
 
// abre um arquivo existente para leitura
infile_nome = fopen("nome.txt", "r");
 
if(infile_nome == NULL) {
    return 1; }
 
// Obtém o número de bytes 
fseek(infile_nome, 0L, SEEK_END);
numbytes = ftell(infile_nome);
 
// redefinir o indicador de posição do arquivo para o início do arquivo 
fseek(infile_nome, 0L, SEEK_SET);	
 
// pega memória suficiente para o buffer conter o texto
nome_buffer = (char*)calloc(numbytes, sizeof(char));	
 
// erro de memoria
if(nome_buffer == NULL) {
    return 1; }
 
// copiar todo o texto para o buffer
fread(nome_buffer, sizeof(char), numbytes, infile_nome);
fclose(infile_nome);

FILE    *infile_cpf;
char    *cpf_buffer;
long    numbytes_cpf;

infile_cpf = fopen("cpf.txt", "r");
 
if(infile_cpf == NULL) {
    return 1; }
 
fseek(infile_cpf, 0L, SEEK_END);
numbytes_cpf = ftell(infile_cpf);
 
fseek(infile_cpf, 0L, SEEK_SET);	
 
cpf_buffer = (char*)calloc(numbytes_cpf, sizeof(char));	
 
if(cpf_buffer == NULL) {
    return 1; }
 
fread(cpf_buffer, sizeof(char), numbytes_cpf, infile_cpf);
fclose(infile_cpf);

FILE    *infile_rg;
char    *rg_buffer;
long    numbytes_rg;

infile_rg = fopen("rg.txt", "r");
 
if(infile_rg == NULL) {
    return 1; }
 
fseek(infile_rg, 0L, SEEK_END);
numbytes_rg = ftell(infile_rg);
 
fseek(infile_rg, 0L, SEEK_SET);	

rg_buffer = (char*)calloc(numbytes_rg, sizeof(char));	

if(rg_buffer == NULL) {
    return 1; }
 
fread(rg_buffer, sizeof(char), numbytes_rg, infile_rg);
fclose(infile_rg);

FILE    *infile_data;
char    *data_buffer;
long    numbytes_data;

infile_data = fopen("data_nasc.txt", "r");
 
if(infile_data == NULL) {
    return 1; }
 
fseek(infile_data, 0L, SEEK_END);
numbytes_data = ftell(infile_data);
 
fseek(infile_data, 0L, SEEK_SET);	

data_buffer = (char*)calloc(numbytes_data, sizeof(char));	
 
if(data_buffer == NULL) {
    return 1; }
 
fread(data_buffer, sizeof(char), numbytes_data, infile_data);
fclose(infile_data);

FILE    *infile_pais;
char    *pais_buffer;
long    numbytes_pais;

infile_pais = fopen("pais.txt", "r");
 
if(infile_pais == NULL) {
    return 1; }
 
fseek(infile_pais, 0L, SEEK_END);
numbytes_pais = ftell(infile_pais);
 
fseek(infile_pais, 0L, SEEK_SET);	

pais_buffer = (char*)calloc(numbytes_pais, sizeof(char));	
 
if(pais_buffer == NULL) {
    return 1; }
 
fread(pais_buffer, sizeof(char), numbytes_pais, infile_pais);
fclose(infile_pais);


int len_nome, len_cpf, len_rg, len_data, len_pais;

strcpy(nome, &nome_buffer[0]);
strcpy(nome_txt, &nome_buffer[0]); 
strcat(nome_txt,".txt");
strcpy(cpf, &cpf_buffer[0]);
strcpy(rg, &rg_buffer[0]);
strcpy(data, &data_buffer[0]);
strcpy(pais, &pais_buffer[0]);

len_nome = strlen(nome_txt);
len_cpf = strlen(cpf);
len_rg = strlen(rg);
len_data = strlen(data);
len_pais = strlen(pais);

//printf("tamanho = %d\n", len_nome);

fp = open (nome_txt, O_RDWR | O_CREAT, S_IRWXU);
if(fp==-1)
	{
	printf ("Erro na abertura do arquivo.\n");
	exit (1);
	}
for(i=0; nome[i]; i++) { 
	if (i == (len_nome-4)){	
		write(fp, "\n", 1); 	
		}	
	else {
		if (i == 0){	
			write(fp, "NOME: ", 6);			
			}
		write(fp, &(nome[i]), 1); // Grava a string, caractere a caractere
		}
	}
write(fp, "\n", 1);
write(fp, "CPF: ", 5);
write(fp, cpf, len_cpf);
write(fp, "\n", 1);
write(fp, "RG: ", 4);
write(fp, rg, len_rg);
write(fp, "\n", 1);
write(fp, "DATA DE NASCIMENTO: ", 20);
write(fp, data, len_data);
write(fp, "\n", 1);
write(fp, "NOME DOS PAIS: ", 15);
write(fp, pais, len_pais);
write(fp, "\n", 1);
close(fp);

return 0;
}
