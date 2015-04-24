#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000


int main(){

	char dig[10001];
	int somapar, somaimpar, i;	
	
	while(scanf(" %s",dig) != EOF){
		somapar = somaimpar = 0;
		for(i = 0; dig[i] != '\0'; i++){
			if(i%2 == 0)
				somapar += dig[i] -'0';
			else
				somaimpar += dig[i] -'0';
		}
		
		if(somapar % 11 == somaimpar % 11)
			printf("Y\n");
		else {
			printf("N\n");
		}
	
	}	

	return 0;
}
