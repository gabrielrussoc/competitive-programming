#include <cstdio>

int main(){
	
	int v[2005];
	int n;

	scanf("%d",&n);

	for(int i = 0; i < n; i++)
		scanf("%d",&v[i]);

	for(int i = 0; i < n; i++){
		int cont = 0;
		for(int j = 0; j < n; j++){
			if(i != j && v[i] < v[j])
				cont++;
		}
		printf("%d%c",cont+1,i == n-1 ? '\n' : ' ');
	}


}