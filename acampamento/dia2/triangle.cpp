#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int m[10007];
int v[10007];

int pd(int i, int n){

	if(i <= (n*(n+1)/2 - n) || i > n*(n+1)/2) return 0;
	if(m[i] != -1) return m[i];
	if(i == 1) return v[i];

	int r;
	r = max(v[i] + pd(i-n+1,n-1), v[i] + pd(i-n,n-1));
	
	m[i] = r;
	return r;

}

int main(){

	int n;
	scanf("%d",&n);
	
	memset(m,-1,sizeof m);
	int a = n*(n+1)/2;
	for(int i = 0; i < a; i++)
		scanf("%d",&v[i+1]);

	int ans = 0;
	for(int i = a-n+1; i <= a; i++){	
		ans = max(ans,pd(i,n));
	}

	printf("%d\n",ans);


}
