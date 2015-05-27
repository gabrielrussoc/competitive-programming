#include <cstdio>
#include <cmath>
#include <climits>
#define MAX 30

using namespace std;

int main(){
	
	unsigned long long r, ans = 1, a;

	scanf("%llu",&r);

	a = pow(3,MAX);
	a = a % 2147483647;
	while(r > MAX){
		ans *= a;
		ans = ans % 2147483647;
		r -= MAX;
	}

	a = pow(3,r);
	a = a % 2147483647;
	ans = ans * a;
	ans = ans % 2147483647;

	printf("%llu\n",ans);

	return 0;
}