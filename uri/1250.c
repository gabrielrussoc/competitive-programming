#include <stdio.h>

int main(){
	
	int n, t, i, j, dano, alt[50];
	char pulos[50];

	scanf("%d",&n);

	for(i = 0; i < n; i++){

		/*num de tiros*/
		scanf("%d",&t);

		/*altura de cada tiro*/
		for(j = 0; j < t; j++){
			scanf("%d",&alt[j]);
		}

		/*vejo oq ele fez e se foi atingido*/
		for(j = 0; j < t; j++){
			scanf(" %c",&pulos[j]);

			if(pulos[j] == 'J' && alt[j] > 2)
				dano++;
			else if(pulos[j] == 'S' && alt[j] <= 2)
				dano++;
		}

		printf("%d\n",dano);

		dano = 0;

	}

	return 0;
}