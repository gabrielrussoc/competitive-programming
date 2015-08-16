#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n,m, v[1000006];
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
		scanf("%d",&v[i]);
	
	sort(v,v+n);
	printf("%d\n",v[m-1]);

}
