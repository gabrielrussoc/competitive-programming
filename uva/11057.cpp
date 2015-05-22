#include <cstdio>
#include <algorithm>
#define MAX 10005

using namespace std;

int main(){

	int ans_a, ans_b, n, b[MAX],lo,up,d;

	while(scanf("%d",&n) != EOF){
		
		for(int i = 0; i < n; i++)
			scanf("%d",&b[i]);
		scanf("%d",&d);

		sort(b,b+n);

		lo = 0;
		up = n-1;
		int dif = 1000004;

		while(up > lo){
			if(b[up] + b[lo] == d){
				if(b[up] - b[lo] < dif){
					ans_b = b[up];
					ans_a = b[lo];
				}
				up--;
				lo++;
			}

			else if(b[up] + b[lo] < d) lo++;
			else up--;
		}


		printf("Peter should buy books whose prices are %d and %d.\n",ans_a,ans_b);
	}

	
	
	return 0;
}