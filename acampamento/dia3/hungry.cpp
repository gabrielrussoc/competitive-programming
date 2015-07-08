#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int p[10000007];
int k;

void sieve (int n){
	int cont = 0;
	for(int i = 2; i <= n; i++){
		if(p[i] == 0){
			for(unsigned long long j = i*i; j <= n; j += i){
				if(p[j] == 0)
					p[j] = 1;
			}
			cont++;
			printf("%d ", i);
			if(cont == k)
				break;
		}		
	}
}

int main(){
		
	scanf("%d", &k);

	memset(p, 0, sizeof p);
	sieve(10000000);
	printf("\n");

}
