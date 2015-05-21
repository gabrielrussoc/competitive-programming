#include <cstdio>
#include <algorithm>
#include <cmath>

int main(){
	
	int v[5], i,c,d;
	c = d = 0;

	for(i = 0; i < 5; i++)
		scanf("%d",&v[i]);

	for(i = 0; i < 4; i++){
		if(v[i] < v[i+1])
			c = 1;
		else
			d = 1;
	}

	if(c && !d)
		printf("C\n");
	else if(d && !c)
		printf("D\n");
	else
		printf("N\n");




	return 0;
}