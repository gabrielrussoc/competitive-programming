#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

struct p{
	int id;
	int med;
}v[105];

bool comp(p i, p j){
	if(i.med > j.med)
		return true;
	else if(i.med == j.med)
		return (i.id < j.id);
	else return false;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);

	for(int i = 0; i < n; i++){
		v[i].id = i+1;
		v[i].med = 0;
	}

	for(int i = 0; i < m; i++){
		int o,p,b;
		scanf("%d %d %d",&o,&p,&b);
		v[o-1].med++;
		v[p-1].med++;
		v[b-1].med++;
	}
	sort(v,v+n,comp);

	for(int i = 0; i < n; i++)
		printf("%d%c",v[i].id,i == n - 1 ? '\n' : ' ');
}