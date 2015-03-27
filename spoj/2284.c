#include <stdio.h>
int main(){
	
	char palavra[21];
	int i,d,soma;
	
	while(scanf(" %s",palavra) != EOF){
		
		soma = 0;

		for(i = 0; palavra[i] != '\0'; i++){
			if (palavra[i] <= 'Z')
				soma += palavra[i] - 'A' + 27;
			else
				soma += palavra[i] - 'a' + 1;		
		}

		for(d = 2; d*d <= soma; d++){
			if(soma%d == 0)
				break;		
		}
		
		if(d*d > soma || soma == 1)
			printf("It is a prime word.\n");
		else
			printf("It is not a prime word.\n");	
	
	}

	return 0;
}
