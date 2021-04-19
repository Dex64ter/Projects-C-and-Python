#include <stdio.h>

int main(int argc, char** argv){
	int a=0, g=0, d=0;
	int tip;
	while(1){
		scanf("%d", &tip);
		if(tip > 0){
			if(tip == 1){
				a++;
			}
			if(tip == 2){
				g++;
			}
			if(tip == 3){
				d++;
			}
			if(tip == 4){
				break;
			}
		}
	}
	printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n", a, g, d);
	
	
	return 0;
}
