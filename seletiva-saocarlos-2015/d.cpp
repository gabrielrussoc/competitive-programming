#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int v[1000009];
long long memo[1000009];
int n;

long long solve(int i){
	if(i >= n) return 0;
	if(memo[i] != -1) return memo[i];

	long long ans = max(v[i] + solve(i+3),solve(i+1));
	memo[i] = ans;
	return ans;

}


int main(){
	memset(memo,-1,sizeof memo);
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&v[i]);
	long long ans = solve(0);
	cout << ans << endl;
}
