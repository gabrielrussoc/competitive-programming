#include <cstdio>
#define MAX 100009


using namespace std;

int main(){
	
	int n, p[MAX],b, soma, glr[MAX];
	char w;

	scanf("%d",&n);

	for(int i = 1; i <= n; i++)
		scanf("%d",&p[i]);

	soma = 0;

	for(int i = 1; i <= n; i++){
		glr[i] = soma;
		soma += p[i];
	}


	while(scanf(" %c  %d",&w,&b) != EOF){
		int ans = 0;

		if(w == 'a'){
			for(int j = b+1; j <= n; j++)
				glr[j] -= p[b];
		}
		else
			printf("%d\n",glr[b]);


	}


	return 0;
}