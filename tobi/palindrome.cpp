#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

char v[2005];
int memo[2005];
int ispalzao[2005][2005];
int n;

int ispal(int i, int j){
	
	int &k = ispalzao[i][j];
	if(k != -1) return k;
	if(i >= j) return 1;
	int ans;
	if(v[i] == v[j]) ans = ispal(i+1,j-1);
	else ans = 0;
	k = ans;
	return ans;
}

int dp(int i){
	int &m = memo[i];
	if(m != -1) return m;
	if(ispal(i,n-1)) return (m = 0);
	int ans = INT_MAX;
	for(int p = i; p < n-1; p++)
        if(ispal(i,p))
		    ans = min(ans,1+dp(p+1));

	m = ans;
	return m;
}

int main(){

	int tc = 1;

	while(scanf("%d",&n) && n != 0){
        memset(memo,-1,sizeof memo);
        memset(ispalzao,-1,sizeof ispalzao);
        scanf(" %s",v);
		printf("Teste %d\n",tc++);
		printf("%d\n\n",1+dp(0));
	}

}
