#include <bits/stdc++.h>

using namespace std;

int p[10220];
int v[2250];
int k = 0;

void sieve(int n){

	for(int i = 2; i <= n; i++){
		if(!p[i]){
			for(int j = i*i; j <= n; j += i)
				p[j] = 1;
			v[k++] = i;
		}
	}

}


int main(){	

	int n;
	memset(p,0,sizeof p);
	sieve(10100);
	while(scanf("%d",&n) && n != 0){
		int ans = 0;
		for(int i = 0; i < k; i++){
			int aux = v[i];
			for(int j = i+1; aux < n; j++)
				aux += v[j];
			if(aux == n)
				ans++;
		}
		printf("%d\n",ans);
	}


}