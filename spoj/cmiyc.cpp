#include <cstdio>

int main(){
	
	int t;
	long long n;

	scanf("%d",&t);
	while(t--){

		scanf("%lld",&n);
		printf("%lld\n",n%3 == 0 ? n/3 : 0);

	}	


}