#include <cstdio>
#include <cstring>

using namespace std;

int v[10005];
int acu[10005];
int c[15005];

int main(){

	int n;
	scanf("%d",&n);
	memset(c,0,sizeof c);

	acu[0] = 0;
	for(int i = 0; i < n; i++){
		scanf("%d",&v[i]);
		acu[i+1] = (acu[i] + v[i])%n; 
	}

	int l, u;

	for(int i = 1; i <= n; i++){
		//printf("%d\n",acu[i]);
		if(acu[i] == 0){
			l = 0;
			u = i;
			break;
		}
		if(!c[acu[i]])
			c[acu[i]] = i;
		else{
			l = c[acu[i]];
			u = i;
			break;
		}
	}
	int ans = u-l;
	printf("%d\n",ans);
	for(int i = l; i < u; i++)
		printf("%d\n",v[i]);

}