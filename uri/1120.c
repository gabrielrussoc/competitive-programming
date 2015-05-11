#include <stdio.h>
#include <string.h>

int main(){

	char dig,contrato[101];
	int foi,i;

	while(scanf(" %c",&dig) && dig != '0'){

		foi = 0;
		scanf("%s",contrato);
		for(i = 0; contrato[i] != '\0'; i++){
			if(dig != contrato[i]){
				if(contrato[i] == '0' && !foi)
					continue;
				else{
					printf("%c",contrato[i]);
					foi = 1;
				}

			}
		}
		if(!foi)
			printf("0");
		printf("\n");

	}
	
	return 0;
}