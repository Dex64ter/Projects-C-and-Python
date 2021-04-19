#include <stdio.h>

int main(int argc, char** argv){
	int n, aux=1, aux1=4;
	int i, j;
	scanf("%d", &n);
	for(i=1; i <= n; i++){
		for(j=aux; j<=aux1; j++){
			if(j%4 == 0){
				printf("PUM");
			}else{
				printf("%d ", j);
			}
		}
		printf("\n");
		aux += 4;
		aux1 += 4;
	}
	
	
	return 0;
}