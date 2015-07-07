#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){

	int n,m;
	scanf("%d %d",&n, &m);

	int d1,d2,h1,h2;
	int max = 0;
	scanf("%d %d",&d1,&h1);
	for(int i = 1; i < m; i++){
		scanf("%d %d",&d2,&h2);
		if(abs(h1-h2) > d2-d1){
			printf("IMPOSSIBLE\n");
			return 0;		
		}
		int lo, hi;
		lo = h1;
		hi = d2-d1 + h1;
		while(lo != hi){
			int mid = (lo+hi)/2;
			if(abs(mid - h2) <= d2 - mid + h1)
				lo = mid;
			else
				hi = mid - 1;		
		}
		if(lo > max)
			max = lo;
		d1 = d2;
		h1 = h2;
		
	}
	printf("%d\n",max);
}
