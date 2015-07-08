#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

	int r,g,b;
	int ans = 0;
	scanf("%d %d %d",&r,&g,&b);

	int ans1;
	
	ans1 = r/3 + g/3 + b/3 + min(min(r%3,g%3),b%3);
	ans = max(ans,ans1);
	ans1 = r/3 + min(min(r%3,g),b);
	ans = max(ans,ans1);
	ans1 = g/3 + min(min(r,g%3),b);
	ans = max(ans,ans1);
	ans1 = b/3 + min(min(r,g),b%3);
	ans = max(ans,ans1);
	ans1 = r/3 + g/3 + min(min(r%3,g%3),b);
	ans = max(ans,ans1);
	ans1 = r/3 + b/3 + min(min(r%3,g),b%3);
	ans = max(ans,ans1);
	ans1 = g/3 + b/3 + min(min(r,g%3),b%3);
	ans = max(ans,ans1);
	int m = min(min(r,g),b); 
	ans1 = m + (r-m)/3 + (g-m)/3 + (b-m)/3;
	ans = max(ans,ans1);
	
	printf("%d\n",ans);

}
