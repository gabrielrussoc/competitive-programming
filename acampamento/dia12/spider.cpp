#include <algorithm>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>

using namespace std;

int n, m, v[41];
int memo[41][1003];
int path[41];

int pd(int i, int h){

	if(i == m && h == 0) return 2;
	if(h < 0) return 12340;
	if(i == m && h != 0) return 12340;
	if(memo[i][h] != -1) return memo[i][h];

	int ans = max(h,min(pd(i+1,h+v[i]),pd(i+1,h-v[i])));
	memo[i][h] = ans;
	return ans;

}

void pd2(int i, int h){

	if(i == m && h == 0) return;
	if(h < 0) return;
	if(i == m && h != 0) return;

	int r1, r2;
	r1 = pd(i+1,h+v[i]);
	r2 = pd(i+1,h-v[i]);
	
	if(r1 < r2){
		path[i] = 1;
		pd2(i+1,h+v[i]);
	}
	else{
		path[i] = 0;
		pd2(i+1,h-v[i]);
	}
}

int main(){
	
	scanf("%d",&n);
	while(n--){
		memset(memo,-1,sizeof memo);
		scanf("%d",&m);
		for(int i = 0; i < m; i++)
			scanf("%d",&v[i]);

		int ans = pd(0,0);
		//printf("%d\n",ans);
		if(ans == 12340){
			printf("IMPOSSIBLE\n");
			continue;
		}
		pd2(0,0);
		for(int i = 0; i < m; i++)
			printf("%c",path[i] == 0 ? 'D' : 'U');
		printf("\n");		
	}

}