#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

int l,n;
int c[55];
int m[1005][1005];

int pd(int i, int j, int a, int b){

	if(m[i][j] != -1) return m[i][j];
	if(a == b) return 0;

	int r = INT_MAX;

	for(int k = a; k < b; k++)
		r = min(r,j-i + pd(c[k],j,k+1,b) + pd(i,c[k],a,k));

	m[i][j] = r;

	return r;
}


int main(){

	while(scanf("%d",&l) && l != 0){
		memset(m,-1,sizeof m);

		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%d",&c[i]);

		int ans = pd(0,l,0,n);
		printf("The minimum cutting is %d.\n",ans);
	}
}