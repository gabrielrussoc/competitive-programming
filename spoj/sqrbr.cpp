#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,k;
long long m[55][55];
int v[42];

long long pd(int p, int i){

	if(p < 0 || (i == (2*n)+1 && p != 0))
		return 0;
	if(i == (2*n)+1 && p == 0)
		return 1;

	if(m[p][i] != -1) return m[p][i];

	int r;
	if(v[i])
		r = pd(p+1,i+1);
	else
		r = pd(p+1,i+1) + pd(p-1,i+1);

	m[p][i] = r;

	return r; 	
}


int main(){
	
	int d;
	scanf("%d",&d);

	while(d--){
		for(int i = 0; i < 55; i++)
			for(int j = 0; j < 55; j++)
				m[i][j] = -1;

		for(int i = 0; i < 42; i++)
			v[i] = 0;
		
		scanf("%d %d",&n,&k);
		for(int i = 0; i < k; i++){
			int a;
			scanf("%d",&a);
			v[a]++;
		}
		long long ans = pd(0,1);
		printf("%lld\n",ans);
	}

}