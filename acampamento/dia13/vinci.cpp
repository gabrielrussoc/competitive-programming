#include <cstdio>
#include <cstring>
#include <map>

typedef long long ll;

using namespace std;

map<int,int> fib;
int v[1234];

void buildfib(){

	fib[1] = 0;
	fib[2] = 1;
	ll n1 = 1, n2 = 2,aux;
	int k = 2;

	while(n1+n2 <= 2000000000){
		fib[n1+n2] = k++;
		aux = n1+n2;
		n1 = n2;
		n2 = aux;
	}
}


int main(){
	
	buildfib();

	int t;
	char in[1234],ans[1234];
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);
		int maxi = 0;
		for(int i = 0; i < n; i++){
			scanf("%d",&v[i]);
			if(v[i] > maxi)
				maxi = v[i];
		}
		int u = fib[maxi]+1;	

		scanf(" %[^\n]",in);
		int k = strlen(in);
		int j = 0;

		for(int i = 0; i < u; i++)
			ans[i] = ' ';

		for(int i = 0; j < n; i++){
			if(in[i] - 'A' >= 0 && in[i] - 'A' <= 25){
				ans[fib[v[j++]]] = in[i];
			}
		}
		ans[u] = '\0';
		printf("%s\n",ans);
	}
}