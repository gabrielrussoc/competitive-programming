#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000


int main(){
	
	unsigned int n;
	int impar;
	
	while(scanf("%u", &n) != EOF){
		impar = 0;		
		while(n){
			if(((n%10) % 2) == 1){
				impar++;			
			}
			n = n/10;	
		}
		
		printf("%d\n",impar);

	}

			
	return 0;
}
