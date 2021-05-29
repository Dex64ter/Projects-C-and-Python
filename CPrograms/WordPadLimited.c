/**
 * Fa�a um editor de textos, inspirado no NotePad (Bloco de Notas) ou
WordPad/Word, que permite ao usu�rio inicialmente ler um texto de um arquivo
texto armazenado em disco, armazene este texto em um vetor de strings em
mem�ria, onde cada linha do texto ter� um n�mero indicando a linha
correspondente. Uma vez lido o arquivo, o programa deve ler comandos do
usu�rio, que poder� ser um dos seguintes comandos:

Listar (op��o 1: indicar o intervalo de linhas que deseja exibir na tela, linha inicial
at� linha final);

Editar (op��o 2: indicar qual a linha deseja editar, mostrar o seu conte�do atual,
ler um novo conte�do e substituir o conte�do da linha antiga pelo novo
conte�do);

Inserir (op��o 3: indicar depois de qual linha desejo inserir uma nova linha de
texto, �abrindo espa�o� ap�s esta linha e inserindo um novo texto);

Apagar (op��o 4: indicar qual linha deseja apagar, exibir seu conte�do, confirmar
a remo��o e remover esta linha do texto);

Abandonar (op��o 5: sair do programa, sem salvar o texto editado, onde �
pedida uma confirma��o do usu�rio sobre a execu��o desta op��o);

Sair (op��o 6: sair do programa, onde o texto ser� salvo em um arquivo em
disco sobrescrevendo o arquivo original, sendo pedida uma confirma��o do
usu�rio sobre a execu��o desta op��o).

O programa no final deve portanto ter a capacidade de ler um arquivo de
texto do disco, editar (listar, incluir, excluir, modificar linhas de texto) e salvar em
disco o texto novo que foi editado, executando as opera��es usuais de um editor
de textos simples.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void Listar(char l[][100], int *j){
	int i, li, lf;
	printf("Digite o intervalo de linhas que deseja visualizar:\n");
	scanf("%d%d", &li, &lf);
	if(lf <= *j){
		for(i=li-1; i<lf; i++){
			printf("%s\n", l[i]);
		}
	}else{
		printf("N�o foi poss�vel listar, linha final n�o existente\n");
	}
}

void Editar(char l[][100], int i){
	char arr[100];
	fflush(stdin);
	printf("Editando para:  ");
	gets(arr);
	strcpy(l[i-1], arr);
	strcat(l[i-1],"\n");
}

void Inserir(char l[][100], int li, int *i){
	int j;
	char aux[100];
	for(j=*i; j>=li; j--){
		strcpy(l[j+1], l[j]);
	}
	fflush(stdin);
	printf("Insira um novo texto: \n");
	gets(aux);
	strcpy(l[li+1], aux);
	strcat(l[li+1],"\n");
	*i = *i + 1;
	printf("	Texto agora possui %d linhas\n\n", *i);
}

void Apagar(char l[][100], int li, int *i){
	int j;
	char r;
	printf("%s \n", l[li]);
	fflush(stdin);
	printf("Tem certeza que deseja apagar esta linha? (s/n)\n");
	scanf("%c", &r);
	if(r == 's'){
		for(j=li; j<*i-1; j++){
			strcpy(l[j], l[j+1]);
		}
		*i = *i-1;
		printf("	Texto agora possui %d linhas\n\n", *i);
	}else{
		printf("Opera��o Cancelada\n");
	}
	
}

int Abandonar(){
	char rs;
	printf("Confirmar opera��o de abandono? (s/n)\n");
	while(rs != 's' || rs != 'n'){
		scanf("%c", &rs);
		if(rs == 's'){
			return 1;
		}else if(rs == 'n'){
			return 0;
		}
	}
	return -1;
}

int Sair(char l[][100] ,int *p){
	FILE *f1;
	int i;
	char r;
	f1 = fopen("arquivo.txt", "w");
	
	if(f1 == NULL){		// verifica se o arquivo foi aberto
		printf("ERROR: N�o foi poss�vel abrir o arquivo\n");
		return 0;
	}
	
	fflush(stdin);
	printf("Confirmar op��o de salvar e sair? (s/n)\n");
	scanf("%c", &r);
	if(r == 's'){
		for(i=0; i<*p; i++){
			fputs(l[i], f1);
		}
		return 1;
	}else if(r == 'n'){
		return 0;
	}
	
	fclose(f1);
	return -1;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	FILE *aply;
	char linhasT[51][100];
	int op, x, i=0, sair=0;
	char a[100];
	
	aply = fopen("arquivo.txt", "r");
	
	if(aply == NULL){		// verifica se o arquivo foi aberto
		printf("ERROR: N�o foi poss�vel abrir o arquivo\n");
		return 0;
	}
	
	while(fgets(a, 100, aply) != NULL){
		strcpy(linhasT[i], a);
		i++;
	}
	
	fclose(aply);
	
	for(x=0; x<=i; x++){
		printf("%s", linhasT[x]);
	}
	printf("\n\n");
	
	printf("### -------------------------------- ###\n");
	printf("### BEM-VINDO A NOSSA NOVA APLICA��O ###\n");
	printf("### -------------------------------- ###\n");
	while(1){
		printf("\n	Menu de Op��es:\n 1. Listar		4. Apagar\n 2. Editar		5. Abandonar\n 3. Inserir		6. Sair\nR:  ");
		scanf("%d", &op);
		switch(op){
		case 1:
			Listar(linhasT, &i);
			break;
		case 2:
			printf("Digite a linha a qual vc deseja trocar: \n");
			scanf("%d", &x);
			if(x <= i){
				Editar(linhasT, x);
			}else{
				printf("Imposs�vel realizar opera��o, linha n�o existente\n\n");
			}
			break;
		case 3:
			printf("Deseja inserir depois de qual linha do texto?\n R: ");
			scanf("%d", &x);
			if(x <= i){
				Inserir(linhasT, x-1, &i);
			}else{
				printf("Imposs�vel realizar opera��o, linha n�o existente\n\n");
			}
			break;
		case 4:
			printf("Qual linha do texto deseja apagar?\n R: ");
			scanf("%d", &x);
			if(x <= i){
				Apagar(linhasT, x-1, &i);
			}else{
				printf("Imposs�vel realizar opera��o, linha n�o existente\n\n");
			}
			break;
		case 5:
			sair = Abandonar();
			break;
		case 6:
			sair = Sair(linhasT, &i);
			break;
		
		default:
			printf("Op��o inv�lida");
			break;
		}
		
		if(sair == 1){
			break;
		}
	}
	
	return 0;
}