#include <stdio.h>
int main(){
	int num[10], i,maior, aux;
	
	scanf("%d",&maior);	
	
	for(i = 1; i < 10; i++){
		scanf("%d",&num[i]);
		if(num[i] > maior){
			maior = num[i];
			aux = i + 1;		
		}	
	}
	
	printf("%d\n%d\n",maior,aux);	

	return 0;
}
