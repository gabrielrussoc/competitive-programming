#include <cstdio>
#define MAX 1005

using namespace std;


int main(){
	
	int n, t, ans,c[MAX],v[MAX], max, aux,aux2;
	ans = max = 0;

	scanf("%d %d",&n,&t);

	for(int i = 0; i < n; i++)
		scanf("%d %d",&c[i],&v[i]);

	for(int i = 0; i < n; i++){
		ans = 0;
		aux2 = t;
		for(int j = i; j < n; j++){
			aux = aux2/c[j];
			ans = ans + aux * v[j];
			aux2 = aux2 - aux * c[j];
		}
		if(ans > max)
			max = ans;

	}

	printf("%d\n",max);

	return 0;
}