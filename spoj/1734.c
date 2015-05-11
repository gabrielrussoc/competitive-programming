#include <stdio.h>
#include <string.h>

int main(){

	char nome[21], res[21];
	int nota,n,i,at,k = 1;

	while(scanf("%d",&n) != EOF){

		scanf("%s",res);
		scanf("%d",&nota);

		for(i = 1; i < n; i++){
			scanf("%s",nome);
			scanf("%d",&at);

			if(at < nota){
				nota = at;
				strcpy(res,nome);
			} 
			else if(at == nota){
				if(strcmp(nome,res) > 0){
					nota = at;
					strcpy(res,nome);
				}
			}
		}

		printf("Instancia %d\n",k);
		printf("%s\n",res);
		printf("\n");
		k++;
	}
	
	return 0;
}