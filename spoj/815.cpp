#include <cstdio>
#include <algorithm>
#define MAX 10004

using namespace std;

int main(){
	
	int v[MAX],n,m,min,max,res,t = 1;

	while(scanf("%d",&n) && n != 0){
		min = 2000;
		max = -2000;

		scanf("%d",&m);

		for(int i = 0; i < n; i++)
			scanf("%d",&v[i]);

		res = 0;
		for(int j = 0; j < n; j++){
			res += v[j];
			if(j >= m - 1){
				if(j >= m)
					res -= v[j-m];
				if(res/m < min)
					min = res/m;
				if(res/m > max)
					max = res/m;
			}
		}

		printf("Teste %d\n",t);
		printf("%d %d\n\n",min,max);
		t++;


	}

	return 0;
}