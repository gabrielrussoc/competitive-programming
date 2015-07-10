#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	
	map<int,int> m;
	int n;
	int v[300006];
	scanf("%d",&n);

	for(int i = 0; i < n; i++)
		scanf("%d",&v[i]);

	sort(v,v+n);

	for(int i = 0; i < n; i++){
		if(m.insert(make_pair(v[i],1)).second){
			printf("%d ",v[i]);
		}
		else{
			printf("%d ",v[i] + m[v[i]]);
			if(!m.insert(make_pair(v[i] + m[v[i]],1)).second)
				m[v[i] + m[v[i]]]++;
			m[v[i]]++;
		}
	}
	printf("\n");
}