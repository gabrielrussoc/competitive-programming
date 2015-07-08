#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int m[15][105];


int pd(int t, int i){

	if(m[t][i] != -1) return m[t][i];

	if(t == 1){
		if(i == 0) return 1;
		else return 0;
	}

	int r = 0;
	for(int j = 1; j <= t; j++)
		r += pd(t-1,i-t+j);

	m[t][i] = r;
	return r;
}


int main(){

	int d;
	scanf("%d",&d);
	memset(m,-1,sizeof m);
	while(d--){
		scanf("%d %d",&n,&k);
		printf("%d\n",pd(n,k));
	}
	

}