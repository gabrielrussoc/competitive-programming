#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, v[55], sol[55], psol[50];
int memo[55][55][4];

int pd(int f, int i, int d){

	if(i == n) return 0;
	if(f > 31) return 123456;
	if(memo[f][i][d] != -1) return memo[f][i][d];

	int r1,r2,cost;
	r1 = pd(f+1,i,0);
	if(d && f != 1) r1 += 10;
	cost = (f-1)*4 + abs(v[i]-f)*20;
	r2 = max(cost,pd(f,i+1,1));

	int ans = min(r1,r2);
	memo[f][i][d] = ans;
	return ans;
}

void pd2(int f, int i, int d){

	if(i == n) return;
	if(f > 31) return;

	int r1,r2,cost;
	r1 = pd(f+1,i,0);
	if(d && f != 1) r1 += 10;
	cost = (f-1)*4 + abs(v[i]-f)*20;
	r2 = max(cost,pd(f,i+1,1));

	if(r2 < r1){ 
		sol[f] = 1;
		pd2(f,i+1,1);
	}
	else 
		pd2(f+1,i,0);
}


int main(){
	
	while(scanf("%d",&n) && n != 0){
		memset(memo,-1,sizeof memo);
		memset(sol,0,sizeof sol);
		for(int i = 0; i < n; i++)
			scanf("%d",&v[i]);

		int ans = pd(1,0,0);
		pd2(1,0,0);
		printf("%d\n",ans);
		int cont = 0;
		for(int i = 2; i <= 31; i++){
			if(sol[i]) psol[cont++] = i;
		}
		printf("%d%c",cont,!cont ? '\n' : ' ');
		for(int i = 0; i < cont; i++)
			printf("%d%c",psol[i],i == cont-1 ? '\n' : ' ');


	}

}