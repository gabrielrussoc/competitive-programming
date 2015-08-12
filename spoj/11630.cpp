#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m;
int memo[10004][102];

int pd(int choco, int forbid){

	//printf("%d %d %d\n",choco,forbid,turn);

	if(choco == 0) return 0;
	if(forbid == 1 && choco == 1) return 0;
	if(memo[choco][forbid] != -1) return memo[choco][forbid];

	int k = min(choco,m);
	int ans = 1;

	for(int i = 1; i <= k; i++)
		if(i != forbid)
			ans *= pd(choco-i,i); 

	ans = (ans+1)%2;

	memo[choco][forbid] = ans;
	return ans;

}


int main(){
	
	memset(memo,-1,sizeof memo);
	scanf("%d %d",&n,&m);
	printf("%s\n",pd(n,0) == 1 ? "Paula" : "Carlos");


}