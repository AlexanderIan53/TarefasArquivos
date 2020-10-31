#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct _Endereco Endereco;
struct _Endereco{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};
void main(){
FILE *f;
f=fopen("cap.dat","r");
Endereco e;
int n;
int maior= e.cep[8];
int menor= e.cep[0];
int resultado=-1;
while(resultado!=0) {
n=(maior+menor)/2;
printf("Valor de n:%d ",n);
fseek(f,n,SEEK_SET);
fseek(f,-1,SEEK_CUR);
char t;
do{
fseek(f,-1,SEEK_CUR);
if(ftell(f)==0) {
break;
}
t=fgetc(f);
if(t=='\n') {
break;
}
fseek(f,-1,SEEK_CUR);
} while(t!='\n');
fgets(e.cep,8,f);
resultado=strcmp(e.cep,strcat(e.logradouro,"\n"));
printf("Resultado:%d ",resultado);
if(resultado==1) {
maior=n;
}
else if(resultado==-1) {
menor=n;
}
else if(resultado==0) {
printf("Palavra encontrada");
}}
fclose(f);
return (0);
}
