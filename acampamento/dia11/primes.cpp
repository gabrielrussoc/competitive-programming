#include <bits/stdc++.h>
using namespace std;

int N,K;
int v[5007];
int p[200];
int m[1200][200][16];
int c = 0;

void sieve(int n){
	for(int i = 2; i <= n; i++){
		if(v[i] == 0){
			//cout << i << endl;
			p[c++] = i;
			for(int j = i*i; j <= n; j += i)
				v[j] = 1;
		}
	}
}

int pd(int n, int i, int k){
	if(n == N && k == K) return 1;
	if(n > N || k > K) return 0;
	if(p[i] > N) return 0;
	if(m[n][i][k] != -1) return m[n][i][k];
	//cout << n << ' ' << p[i] << ' ' << k << endl;
	int ans = pd(n+p[i],i+1,k+1) + pd(n,i+1,k);

	m[n][i][k] = ans;
	return ans;
}


int main(){
	
	memset(v,0,sizeof v);
	sieve(1200);
	//cout << p[187] << endl;
	while(scanf("%d %d",&N,&K) && N != 0 && K != 0){
		memset(m,-1,sizeof m);
		printf("%d\n",pd(0,0,0));
	}


}