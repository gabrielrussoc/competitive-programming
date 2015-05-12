#include <stdio.h>

int main(){
	
	int a,b,c,v,t;
	t = 1;

	while(scanf("%d",&v) && v != 0){
		a = b = c = 0;

		a = v/50;
		v = v%50;
		b = v/10;
		v = v%10;
		c = v/5;
		v = v%5;

		printf("Teste %d\n",t);
		printf("%d %d %d %d\n\n",a,b,c,v);
		t++;

	}


	return 0;
}