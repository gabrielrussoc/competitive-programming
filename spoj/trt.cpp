#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int m[2001][2001];
int v[2001];

int pd(int i, int n, int a){

	if(m[n][a] != -1) return m[n][a];
	if(i == n) return v[i]*a;

	int r = max(v[i]*a + pd(i+1,n,a+1),v[n]*a + pd(i,n-1,a+1));

	m[n][a] = r;

	return r;
}

int main(){

	memset(m, -1, sizeof m);
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&v[i]);

	printf("%d\n",pd(0,n-1,1));


}