#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

map<long long,long long> m;

long long resolve(long long n){

	if(n == 0) return n;

	if(m.find(n) != m.end()) return m[n];

	long long r1 = resolve(n/2) + resolve(n/3) + resolve(n/4);
	long long r2 = n;
	m.insert(make_pair(n,max(r1,r2)));
	return m[n];
}

int main(){
	
	long long n;
	while(scanf("%lld",&n) != EOF)
		printf("%lld\n",resolve(n));

}