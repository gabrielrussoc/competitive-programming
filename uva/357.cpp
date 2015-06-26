#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int v[5] = {1,5,10,25,50};
long long m[6][30002];

int n;

long long pd(int i, int k){

	if(m[i][k] != -1) return m[i][k];
	if(k == 0) return 1;
	if(i > 4 || k < 0) return 0;

	long long r = pd(i,k-v[i]) + pd(i+1,k);

	m[i][k] = r;

	return r;
}

int main(){
	
	memset(m,-1,sizeof m);
	while(scanf("%d",&n) != EOF){
		long long ans = pd(0,n);

		if(ans > 1)
			printf("There are %lld ways to produce %d cents change.\n",ans,n);
		else
			printf("There is only 1 way to produce %d cents change.\n",n); 
	}



}