#include <cstdio>
#define MAX 505

using namespace std;

int main(){
	
	int brs[MAX][MAX],score[MAX];
	int q, n, m, a, b;

	scanf("%d %d %d",&n,&m,&q);

	for(int i = 0; i < n; i++){
		int cont, ans;
		cont = ans = 0;
		for(int j = 0; j < m; j++){
			scanf("%d",&brs[i][j]);
			if(brs[i][j])
				cont++;
			else
				cont = 0;

			if(cont > ans){
				ans = cont;
			}
		}
		score[i] = ans;
	}



	for(int k = 0; k < q; k++){
		scanf("%d %d",&a,&b);
		a--;
		b--;

		brs[a][b]++;
		brs[a][b] = brs[a][b] % 2;

		int cont;
		cont = score[a] = 0;
		for(int j = 0; j < m; j++){
			if(brs[a][j])
				cont++;
			else	
				cont = 0;

			if(cont > score[a])
				score[a] = cont;
		}

		int max = 0;
		for(int i = 0; i < n; i++)
			if(score[i] > max)
				max = score[i];

		printf("%d\n",max);

	}


	return 0;
}