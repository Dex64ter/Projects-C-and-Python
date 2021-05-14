/*
Escreva um programa que leia as medidas dos lados de n triângulos.
O valor de n deve ser fornecido  pelo usuário. Para cada triângulo imprimir
a sua classificação: equilátero, isósceles ou escaleno. Caso  as medidas não
formem um triângulo, imprimir apenas “Nao eh um triangulo”. Para verificar se as
medidas formam um triângulo, usar a função ehTriangulo. O programa deve aceitar apenas
valores  positivos para as medidas dos lados (utilize a função lePositivo). Para descobrir
o tipo de triângulo,  utilize a função tipoTriangulo.

Nome: lePositivo Descrição: Faz a leitura de um valor. Se ele for negativo ou zero, a leitura deve ser repetida até que o
valor  lido seja positivo. Parâmetros: Nenhum. Retorno: (float) o valor correto lido.

Nome: tipoTriangulo Descrição: A partir das medidas dos lados de um triângulo, verifica o tipo do triângulo.
Parâmetros: (float) 3 valores dos possíveis lados de um triângulo. Retorno: (int) 0 se não formam um triângulo.
1 se for um triângulo equilátero. 2 se for um triângulo isósceles. 3 se for um triângulo escaleno.

Nome: ehTriangulo Descrição: Verifica se as 3 medidas informadas permitem formar um triângulo.
Para formar um triângulo é  necessário que a medida de cada lado seja menor que a soma dos outros
2. Parâmetros: (float) 3 valores dos possíveis lados de um triângulo Retorno: (int) 1 se os 3 valores
formarem um triângulo e 0 caso contrário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float lePositivo(){
	float lado;
	scanf("%f", &lado);
	if(lado <= 0){
		printf("Valor ainda inválido, digite novamente:\n");
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
	printf("Digite o número de triângulos que serão analisados: \n");
	scanf("%d", &n);
	printf("\n");
	
	for(i=0; i<n; i++){
		printf("Digite os valores dos lados do triângulo %d: \n", i+1);
		scanf("%f%f%f", &l1, &l2, &l3);
		if(l1<=0){
			printf("Digite novamente um valor válido para o lado 1 do triângulo:\n");
			l1 = lePositivo();
		}		
		if(l2<=0){
			printf("Digite novamente um valor válido para o lado 2 do triângulo:\n");
			l2 = lePositivo();
		}
		if(l3<=0){
			printf("Digite novamente um valor válido para o lado 3 do triângulo:\n");
			l3 = lePositivo();
		}
		switch(tipoTriangulo(l1, l2, l3)){
		case 0:
			printf("-------------------------");
			printf("\nNão é um triângulo\n");
			printf("-------------------------\n\n");
			break;
		case 1:
			printf("-------------------------");
			printf("\nTriângulo Equilátero\n");
			printf("-------------------------\n\n");
			break;
		case 2:
			printf("-------------------------");
			printf("\nTriângulo Isósceles\n");
			printf("-------------------------\n\n");
			break;
		case 3:
			printf("-------------------------");
			printf("\nTriângulo Escaleno\n");
			printf("-------------------------\n\n");
			break;
		}
	}
	printf("FIM DO PROGRAMA");
	
	return 0;
}

