#include <cstdio>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

int main(){

	int n;
	pii c[10004];

	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d %d",&c[i].second, &c[i].first);

	sort(c,c+n);
	int last = 0;
	int ans = 0;
	for(int i = 0; i < n; i++)
		if(c[i].second >= last){
			last = c[i].first;
			ans++;
		}

	printf("%d\n",ans);

}
