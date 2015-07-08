#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int m[5009][5009];
int v[5009];


int pd(int i, int k){

	if(i == -1) return 0;
	if(k == 0 && i > -1) return INT_MAX;
	if(m[i][k] != -1) return m[i][k];

	int r1,r2;
	r1 = pd(i,k-1);
	r2 = pd(i-1,k);
	if(v[i] != k) r2++;

	int r = min(r1,r2);
	m[i][k] = r;
	return r;
}


int main(){
	
	memset(m,-1,sizeof m);
	int n, m;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++){
		double foo;
		scanf("%d %lf",&v[i],&foo);
	}
	int ans = pd(n-1,m);
	printf("%d\n",ans);

}