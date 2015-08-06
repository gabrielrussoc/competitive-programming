#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, v[55];
int memo[55][55];

int pd(int f, int i){

	if(i == n) return 0;
	if(f > 31) return 123456;

	int ans;
	for(int j = 0; j < n-i; j++){
		int maxi = 0;
		for(int k = i; k < j+i; k++)
			maxi = max(maxi,abs(f-v[k])*20 + 4*f);
		ans = min(maxi,10+pd(f+1,i+j));
	}

	memo[f][i] = ans;
	return ans;
}


int main(){
	
	while(scanf("%d",&n) && n != 0){
		memset(memo,-1,sizeof memo);
		for(int i = 0; i < n; i++)
			scanf("%d",&v[i]);

		int ans = pd(1,0);
		printf("%d\n",ans-10);

	}

}