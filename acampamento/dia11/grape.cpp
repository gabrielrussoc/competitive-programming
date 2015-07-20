#include <bits/stdc++.h>

using namespace std;

int N, M, Q, p1, p2;
int m[505][505], diag[1002][600];

int main(){
	
	while(scanf("%d %d",&N,&M) && N != 0 && M != 0){
		
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				scanf("%d",&m[i][j]);

		
		int c = 0;
		for(int k = N-1; k >= 0; k--){
			int i = k;
			int j = 0;
			int t = 1;
			while(j < M && i < N){
				diag[c][t++] = m[i++][j++];
			}
			diag[c][0] = t;
			c++;
		}
		for(int k = 1; k < M; k++){
			int i = 0;
			int j = k;
			int t = 1;
			while(j < M && i < N){
				diag[c][t++] = m[i++][j++];
			}
			diag[c][0] = t;
			c++;
		}
		scanf("%d",&Q);
		while(Q--){
			int l,u;
			scanf("%d %d",&l,&u);
			int max = 0;
			for(int k = 0; k < c; k++){
				int lo = 1, hi = diag[k][0]-1;
				while(lo != hi){
					int mid = (lo + hi)/2;
					if(diag[k][mid] >= l)
						hi = mid;
					else
						lo = mid+1;
				}
				p1 = hi;

				lo = 1; hi = diag[k][0]-1;
				while(lo != hi){
					int mid = (lo + hi+1)/2;
					if(diag[k][mid] <= u)
						lo = mid;
					else
						hi = mid-1;
				}
				p2 = hi;

				if(diag[k][p1] >= l && diag[k][p1] <= u && diag[k][p2] >= l && diag[k][p2] <= u)
					if(p2-p1+1 > max) max = p2-p1+1;
			}
			printf("%d\n",max);
		}
		printf("-\n");

	}

}