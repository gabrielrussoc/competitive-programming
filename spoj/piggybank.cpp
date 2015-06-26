#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int v[505][2];
int m[505][10003];

int n;


int pd(int i, int w){

	if(w < 0 || i == n) return 50000009;

	if(w == 0) return 0;
	if(m[i][w] != -1) return m[i][w];

	int r1 = pd(i+1,w);
	int r2 = v[i][0] + pd(i,w-v[i][1]);
	
	m[i][w] = min(r1,r2);

	return m[i][w];
}


int main(){
	
	int t;
	scanf("%d",&t);
	while(t--){
		memset(m,-1,sizeof m);
		int e,f;
		scanf("%d %d",&e,&f);
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%d %d",&v[i][0],&v[i][1]);

		int ans = pd(0,f-e);

		if(ans != 50000009)
			printf("The minimum amount of money in the piggy-bank is %d.\n",ans);
		else
			printf("This is impossible.\n");
	}

}