#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int v[100006];
long long m[100006];

long long pd(long long k){

	if(k <= 0) return 0;
	if(m[k] != -1) return m[k];

	long long r = max(v[k]*k + pd(k-2),pd(k-1));
	m[k] = r;
	return r;
}


int main(){
	
	int n, max = 0;
	memset(v,0,sizeof v);
	memset(m,-1,sizeof m);
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d",&a);
		v[a]++;
		if(a > max)
			max = a;
	}

	long long ans = pd(max);
	cout << ans << endl;



}