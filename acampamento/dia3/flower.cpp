#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

	int r,g,b;
	scanf("%d %d %d",&r,&g,&b);

	int ans = max(max(r/3+ g/3 + b/3, 1 + (r-1)/3 + (g-1)/3 + (b-1)/3), 2 + (r-2)/3 + (g-2)/3 + (b-2)/3);

	if(r == 0 || g == 0 || b == 0)
		ans = r/3 + g/3 + b/3;
	
	printf("%d\n",ans);

}
