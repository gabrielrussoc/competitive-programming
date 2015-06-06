#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <ctime>

#define pb push_back
#define eps 1e-8

#define MAXN

using namespace std;

char v[60][60];
char aux[3];


int main(){

	int n, m;
	scanf("%d %d",&n,&m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf(" %c",&v[i][j]);

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(v[i][j] == 'f'){
				if(j-1 >= 0 && i+1 < n){
					aux[0] = v[i+1][j-1];
					aux[1] = v[i][j-1];
					aux[2] = v[i+1][j];
					sort(aux,aux+3);
					if(!strcmp(aux,"ace"))
						ans++;
				}
				if(i-1 >= 0 && j-1 >= 0){
					aux[0] = v[i-1][j-1];
					aux[1] = v[i][j-1];
					aux[2] = v[i-1][j];
					sort(aux,aux+3);
					if(!strcmp(aux,"ace"))
						ans++;

				}
				if(j+1 < m && i-1 >= 0){
					aux[0] = v[i-1][j+1];
					aux[1] = v[i][j+1];
					aux[2] = v[i-1][j];
					sort(aux,aux+3);
					if(!strcmp(aux,"ace"))
						ans++;
				}
				if(j+1 < m && i + 1 < n){
					aux[0] = v[i+1][j+1];
					aux[1] = v[i][j+1];
					aux[2] = v[i+1][j];
					sort(aux,aux+3);
					if(!strcmp(aux,"ace"))
						ans++;
				}
			}
		}
	}
	printf("%d\n",ans);

}