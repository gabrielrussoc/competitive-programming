#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	long long n, m, cont;
	while(scanf("%lld %lld", &n, &m), n!=0 || m!=0){
		if(n<m) swap(n, m);
		cont = 0;
		if(m == 0) printf("Stan wins\n");
		while(m!=0){
			if(n == m || n >= 2*m){
				printf("%s wins\n", cont%2 == 0 ? "Stan"  : "Ollie");
				break;
			}
			n %= m;
			swap(n, m);
			cont++;
		}
	}
}