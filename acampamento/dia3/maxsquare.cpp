#include <cstdio>
#include <algorithm>

using namespace std;

int m[1002][1002];
int s[1002][1002];


int main(){
	
	int N, M;
	while(scanf("%d %d",&N,&M) && N != 0){
		int ans = 0;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++){
				scanf("%d",&m[i][j]);
				if(m[i][j]) ans = 1;
			}

		s[0][0] = m[0][0];
		for(int i = 1; i < N; i++)
			s[i][0] = m[i][0];
		for(int j = 1; j < M; j++)
			s[0][j] = m[0][j];

		for(int i = 1; i < N; i++){
			for(int j = 1; j < N; j++){
				if(m[i][j] == 1){
					s[i][j] = min(min(s[i-1][j-1],s[i][j-1]),s[i-1][j]) + 1;
					if(s[i][j] > ans)
						ans = s[i][j];
				}
				else
					s[i][j] = 0;
			}
		}

		printf("%d\n",ans);
	}



}