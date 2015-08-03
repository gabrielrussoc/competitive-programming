#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, v[55];
int memo[55][55][3];

int pd(int fl, int i, int p){

	if(i == n) return 0;
	if(fl > 31) return 123456;
	
	if(memo[fl][i][p] != -1) return memo[fl][i][p];

	int r1,r2;
	r1 = 4+pd(fl+1,i,0);
	r2 = abs(v[i]-fl)*20 + pd(fl,i+1,1);
	if(p == 0 && fl != 1) r2 += 10;

	int ans = min(r1,r2);


	memo[fl][i][p] = ans;
	return ans;
}

int main(){
	
	while(scanf("%d",&n) && n != 0){
		memset(memo,-1,sizeof memo);
		for(int i = 0; i < n; i++)
			scanf("%d",&v[i]);

		int ans = pd(1,0,0);
		printf("%d\n",ans-10);

	}

}