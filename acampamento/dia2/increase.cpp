#include <cstdio>

using namespace std;

int main(){

	int n, ans = 0,a;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a);
		ans += a;
	}
	if(ans % n == 0)
		printf("%d\n",n);
	else
		printf("%d\n",n-1);

}
