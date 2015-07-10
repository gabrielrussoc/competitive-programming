#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 201
#define SMAX 101
using namespace std;

int n, m, tmp, ans;
int vpd[MAX][SMAX][SMAX];
int cars[MAX];

int pd(int k, int l, int r){
	if(vpd[k][l][r]!=-1) return vpd[k][l][r];
	if(k == m) return 0;
	if(l<cars[k] && r<cars[k]) return 0;
	if(l >= cars[k]){
		if(r>=cars[k])
			vpd[k][l][r] = 1 + max(pd(k+1, l-cars[k], r), pd(k+1, l, r-cars[k]));
		else
			vpd[k][l][r] = 1 + pd(k+1, l-cars[k], r);
	}
	else{
		vpd[k][l][r] = 1 + pd(k+1, l, r-cars[k]);
	}
	return vpd[k][l][r];
}

int main(){
	scanf("%d", &n);
	vector<string> v;
	memset(vpd, -1, sizeof vpd);
	m = 0;
	while(scanf("%d", &tmp), tmp!=0){
		cars[m] = tmp/100;
		m++;
	}
	ans = pd(0, n, n);
	printf("%d\n", ans);
}