#include <cstdio>

using namespace std;

int main(){

	int n,k;
	scanf("%d %d",&n,&k);
	int last = 1, hi = 0;
	printf("%d",last);
	for(int i = 1; i < n; i++){	
		if(k){
			if(i%2 == 1)
				last += k;
			else
				last -= k;
			printf(" %d",last);
			if(last > hi)
				hi = last;
			k--;
		}
		else
			printf(" %d",++hi);
	}
	printf("\n");

}
