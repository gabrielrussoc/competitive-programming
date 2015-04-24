#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000


int main(){
	int ad, bd, cd, as, bs, cs, min, a, b, c;

	while(scanf("%d", &ad) != EOF){
		scanf("%d %d %d %d %d", &bd, &cd, &as, &bs, &cs);
		a = ad - as; b = bd - bs; c = cd - cs;
		if(a > 0){
			min = -b/(2*a);
			printf("%d\n", min);
		} else
			printf("sem min\n");
	}

	

	return 0;
}
