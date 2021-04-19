#include <stdio.h>

int main(int argc, char** argv){
	float n1, n2, media;
	int r;
	while(1){
		while(1){
			scanf("%f", &n1);
			if(n1<0 || n1 >10){
				printf("nota invalida\n");
			}else{
				break;
			}
		}
		while(1){
			scanf("%f", &n2);
			if(n2<0 || n2 >10){
				printf("nota invalida\n");
			}else{
				break;
			}
		}
		media = (n1 + n2)/2;
		printf("media = %.2f\n", media);
		while(1){
			printf("novo calculo (1-sim 2-nao)\n");
			scanf("%d", &r);
			if((r == 2) || (r == 1)){
				break;
			}
		}
		if(r == 2){
			break;
		}
	}
	return 0;
}
