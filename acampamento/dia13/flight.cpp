#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int wind[15][1003];
ll memo[15][1003];
int x;

ll pd(int alt, int mil){

	if(alt < 0) return INT_MAX;
	if(alt == 0 && mil == x/100) return 0;
	if(mil == x/100) return INT_MAX;
	if(memo[alt][mil] != -1) return memo[alt][mil];

	int w = -wind[alt][mil];

	ll ans = min(min(60 + w + pd(alt+1,mil+1),30 + w + pd(alt,mil+1)), 20 + w + pd(alt-1,mil+1));

	memo[alt][mil] = ans;
	return ans;
}


int main(){

	int n;
	scanf("%d",&n);

	while(n--){
		memset(memo,-1,sizeof memo);
		scanf("%d",&x);
		for(int i = 9; i >= 0; i--)
			for(int j = 0; j < x/100; j++)
				scanf("%d",&wind[i][j]);

		ll ans = pd(0,0);
		printf("%lld\n\n",ans);
	}
	
}