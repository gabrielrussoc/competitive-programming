#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main(){

	map<int,int> m;

	int t,n, lo = 0, max = 0;
	scanf("%d",&t);	
	while(t--){
		scanf("%d",&n);
		int hi = 0;
		for(int i = 0; i < n; i++){
			int a;
			scanf("%d",&a);
			if(!m.insert(make_pair(a,i)).second){
				if(hi - lo > max)
					max = hi - lo;
				lo = m[a]+1;
				hi = lo-1;
			}
			hi++;	
		}
		if(hi - lo > max)
			max = hi - lo;
		printf("%d\n",max);
		m.clear();
	}
}
