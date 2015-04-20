#include <stdio.h>

int main(){

	char dig;
	double contrato[1e100];

	while(scanf("%c",&dig) && dig != '0'){

		printf("OI\n");

		while(scanf(" %s",&contrato) != '\0'){
			if(contrato != dig){
				printf("%c",contrato);
			}
		}
		printf("\n");

	}
	
	return 0;
}