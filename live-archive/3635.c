#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10005

int main(){

	int n, f, i, temp, c;
	double v[MAX], lo, mid, hi;
	double pi = acos(-1);

	scanf("%d",&c);

	while(c){
		lo = hi = 0;
		scanf("%d %d",&n,&f);

		for(i = 0; i < n; i++){
			scanf("%lf",&v[i]);
			v[i] = v[i]*v[i]*pi;
			if(v[i] > hi)
				hi = v[i];
		}

		while(hi - lo > 0.00001){
			mid = (lo+hi)/2.0;

			temp = 0;
			for(i = 0; i < n; i++){
				temp += v[i]/mid;
			}

			if(temp >= f+1)
				lo = mid;
			else
				hi = mid - 0.00001;

		}

		printf("%.4lf\n",lo);
		c--;
	}


	return 0;
}