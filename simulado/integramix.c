#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100004


int main(){

	int i, k,total,sub;
	char v[MAX];

	while(scanf(" %s",v) != EOF){
		total = sub = 1;
		for(i = 0; v[i] != '\0'; i++){
			total *= v[i];
			if(i == 0)
				sub *= v[i];		
		}

		for(k = 1; k < i; k++){
			
			sub *= v[k];
			if(total%sub == 0)
				break;	
		}
		
		printf("%d\n",k);	

	}

	return 0;
}
