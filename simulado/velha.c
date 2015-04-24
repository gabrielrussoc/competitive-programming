#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000


int main(){

	char jogo[3][3];
	int i,j,acabou,n;

	scanf("%d",&n);
	
	while(n){
		acabou = 0;	

		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				scanf(" %c",&jogo[i][j]);
			}	
		}

		for(i = 0; i < 3; i++){
			if(jogo[i][0] == jogo[i][1] && jogo[i][1] == jogo [i][2] && jogo[i][0] != '.')
				acabou = 1;
		}

		for(j = 0; j < 3; j++){
			if(jogo[0][j] == jogo[1][j] && jogo[1][j] == jogo[2][j] && jogo[0][j] != '.')
				acabou = 1;
		}

		if(jogo[2][2] == jogo[1][1] && jogo[2][2] == jogo[0][0] && jogo[2][2] != '.')
			acabou = 1;
		if(jogo[2][0] == jogo[1][1] && jogo[2][0] == jogo[0][2] && jogo[2][0] != '.')
			acabou = 1;

		if(acabou)
			printf("Y\n");
		else
			printf("N\n");
		
		n--;
	} 

	return 0;
}
