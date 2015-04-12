#include <stdio.h>

int main(){
	
	int t,k,i,j,caso = 1,gente,amigo;
	char s;

	scanf("%d",&t);

	for(i = 0; i < t; i++){
		gente = 0;
		amigo = 0;
		scanf("%d",&k);
		for(j = 0; j < k+1; j++){
			scanf(" %c",&s);
			if(j > gente){
				amigo += j - gente;
				gente += j - gente;
			}
			gente += s - '0';
		}
		
		printf("Case #%d: %d\n",caso,amigo);
		caso++;
	}

	return 0;
}