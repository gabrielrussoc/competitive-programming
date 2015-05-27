#include <cstdio>

using namespace std;

int main(){
	
	unsigned long long a, b;
	unsigned long long ans = 0;

	scanf("%llu %llu",&a,&b);
	a--;

		
	ans = (b*(b+1))/2 - (a*(a+1))/2;


	printf("%llu\n",ans);

	return 0;
}