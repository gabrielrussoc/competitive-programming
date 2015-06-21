#include <cstdio>

int main(){
	
	int m[102][102];
	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d",&m[i][j]);

	int a;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d",&a);
			m[i][j] += a;
		}
	}


	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			printf("%d%c",m[i][j],j == n-1 ? '\n' : ' ');

}