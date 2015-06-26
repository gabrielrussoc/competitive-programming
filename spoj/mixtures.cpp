#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

int m[102][102];
int v[102][102];

int pd(int i, int j){

	if(i == j) return 0;
	if(m[i][j] != -1) return m[i][j];

	int k;
	int r = INT_MAX;

	for(k = i; k < j; k++)
		r = min(r,pd(i,k) + pd(k+1,j) + v[i][k] * v[k+1][j]);

	m[i][j] = r;
	return r;

}

int main(){


	int n;
	while(scanf("%d",&n) != EOF){

		memset(m,-1,sizeof m);
		memset(v,0,sizeof v);

		for(int i = 0; i < n; i++)
			scanf("%d",&v[i][i]);

		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				for(int k = i; k <= j; k++){
					v[i][j] += v[k][k];
					v[i][j] = v[i][j]%100;
				}


		printf("%d\n",pd(0,n-1));

	}
}