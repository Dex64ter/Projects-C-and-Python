/*
Escreva um programa que leia as medidas dos lados de n tri�ngulos.
O valor de n deve ser fornecido  pelo usu�rio. Para cada tri�ngulo imprimir
a sua classifica��o: equil�tero, is�sceles ou escaleno. Caso  as medidas n�o
formem um tri�ngulo, imprimir apenas �Nao eh um triangulo�. Para verificar se as
medidas formam um tri�ngulo, usar a fun��o ehTriangulo. O programa deve aceitar apenas
valores  positivos para as medidas dos lados (utilize a fun��o lePositivo). Para descobrir
o tipo de tri�ngulo,  utilize a fun��o tipoTriangulo.

Nome: lePositivo Descri��o: Faz a leitura de um valor. Se ele for negativo ou zero, a leitura deve ser repetida at� que o
valor  lido seja positivo. Par�metros: Nenhum. Retorno: (float) o valor correto lido.

Nome: tipoTriangulo Descri��o: A partir das medidas dos lados de um tri�ngulo, verifica o tipo do tri�ngulo.
Par�metros: (float) 3 valores dos poss�veis lados de um tri�ngulo. Retorno: (int) 0 se n�o formam um tri�ngulo.
1 se for um tri�ngulo equil�tero. 2 se for um tri�ngulo is�sceles. 3 se for um tri�ngulo escaleno.

Nome: ehTriangulo Descri��o: Verifica se as 3 medidas informadas permitem formar um tri�ngulo.
Para formar um tri�ngulo �  necess�rio que a medida de cada lado seja menor que a soma dos outros
2. Par�metros: (float) 3 valores dos poss�veis lados de um tri�ngulo Retorno: (int) 1 se os 3 valores
formarem um tri�ngulo e 0 caso contr�rio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float lePositivo(){
	float lado;
	scanf("%f", &lado);
	if(lado <= 0){
		printf("Valor ainda inv�lido, digite novamente:\n");
		lado = lePositivo(lado);	
	}
	return lado;
}

int ehTriangulo(float lado1, float lado2, float lado3){
	if((abs(lado2-lado3) < lado1 && lado2+lado3 > lado1) &&
       (abs(lado1-lado3) < lado2 && lado1+lado3 > lado2) &&
       (abs(lado1-lado2) < lado3 && lado1+lado2 > lado3)){

        return 1;
    }
    return 0;
}


int tipoTriangulo(float lado1, float lado2, float lado3){
	switch(ehTriangulo(lado1, lado2, lado3)){
	case 1:
		if(lado1 == lado2 && lado1 == lado3){
			return 1;
		}else if((lado1 == lado2 && lado1 != lado3) || (lado1 != lado2 && lado1 == lado3) || (lado1 != lado2 && lado2 == lado3)){
			return 2;	
		}else if(lado1 != lado2 && lado2 != lado3){
			return 3;
		}
		break;
	case 0:
		return 0;
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int n, i;
	float l1, l2, l3;
	printf("Digite o n�mero de tri�ngulos que ser�o analisados: \n");
	scanf("%d", &n);
	printf("\n");
	
	for(i=0; i<n; i++){
		printf("Digite os valores dos lados do tri�ngulo %d: \n", i+1);
		scanf("%f%f%f", &l1, &l2, &l3);
		if(l1<=0){
			printf("Digite novamente um valor v�lido para o lado 1 do tri�ngulo:\n");
			l1 = lePositivo();
		}		
		if(l2<=0){
			printf("Digite novamente um valor v�lido para o lado 2 do tri�ngulo:\n");
			l2 = lePositivo();
		}
		if(l3<=0){
			printf("Digite novamente um valor v�lido para o lado 3 do tri�ngulo:\n");
			l3 = lePositivo();
		}
		switch(tipoTriangulo(l1, l2, l3)){
		case 0:
			printf("-------------------------");
			printf("\nN�o � um tri�ngulo\n");
			printf("-------------------------\n\n");
			break;
		case 1:
			printf("-------------------------");
			printf("\nTri�ngulo Equil�tero\n");
			printf("-------------------------\n\n");
			break;
		case 2:
			printf("-------------------------");
			printf("\nTri�ngulo Is�sceles\n");
			printf("-------------------------\n\n");
			break;
		case 3:
			printf("-------------------------");
			printf("\nTri�ngulo Escaleno\n");
			printf("-------------------------\n\n");
			break;
		}
	}
	printf("FIM DO PROGRAMA");
	
	return 0;
}

