#include <stdio.h>
#include <math.h>

int main(int argc, char** argv){
	int senha;
	while(1){
		scanf("%d", &senha);
		if(senha == 2002){
			printf("Acesso Permitido\n");
			break;
		}
		printf("Senha Invalida\n");
	}
	
	return 0;
}