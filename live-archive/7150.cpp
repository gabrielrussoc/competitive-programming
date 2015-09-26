#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	
	int a,b,c,d,n,p;
	double eps = 0.00000001, ans, start, temp;

	scanf("%d %d %d %d %d %d",&p,&a,&b,&c,&d,&n);

	start = p*(sin(a+b) + cos(c+d) + 2);
	ans = 0;

	for(int i = 2; i <= n; i++){

		temp = p*(sin(a*i+b) + cos(c*i+d) + 2);

		if(temp - start > eps)
			start = temp;
		else if(start - temp - ans > eps)
			ans = start - temp;

	}

	printf("%.8lf\n",ans);

	return 0;
}