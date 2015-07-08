#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main(){

	set<int> s;
	int v[1000004];

	int t,n;
	scanf("%d",&t);	
	while(t--){
		int a,n, ans = 0;
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%d",&v[i]);
		int i,l = 0;
		for(i = 0; i < n; i++){
			if(!s.insert(v[i]).second){
				while(v[l] != v[i]){
					s.erase(v[l]);
					l++;
				}
				l++;
			}
			if(i-l+1 > ans)
				ans = i-l+1;
		}
		printf("%d\n",ans);
		s.clear();
	}
}
