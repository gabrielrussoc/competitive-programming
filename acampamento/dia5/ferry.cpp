#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;


int m[207][30003],m2[207];
int c[207];
int n,p;

int pd(int k, int r, int t){

	if(m[k][r] != -1) return m[k][r];
	if(t-r > n || r > n) return -1;
	if(k == p) return 0;
	
	int r1,r2;
	r1 = 1 + pd(k+1,r+c[k],t+c[k]);
	r2 = 1 + pd(k+1,r,t+c[k]);

	int ans = max(r1,r2);

	m[k][r] = ans;
	return ans;
}

void pd2(int k, int r, int t){

	if(k == p) return;
	if(t-r > n || r > n) return;

	int r1,r2;
	r1 = 1 + pd(k+1,r+c[k],t+c[k]);
	r2 = 1 + pd(k+1,r,t+c[k]);

	if(r1 > r2){
		m2[k] = 1;
		pd2(k+1,r+c[k],t+c[k]);
	}
	else{
		m2[k] = 0;
		pd2(k+1,r,t+c[k]);
	}

}


int main(){

	memset(m,-1,sizeof m);
	scanf("%d",&n);
	n *= 100;

	p = 0;
	int a;
	while(scanf("%d",&a) && a != 0){
		c[p] = a;
		p++;
		if(p > 200) break;
	}

	int ans = pd(0,0,0);
	pd2(0,0,0);

	printf("%d\n",ans);

	for(int i = 0; i < ans; i++)
		printf("%s\n", m2[i] == 1 ? "port" : "starboard");

}

