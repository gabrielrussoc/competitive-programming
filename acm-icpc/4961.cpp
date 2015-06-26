#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

pair<int,char> tb[27][27];
char in[205];
int tot[205][205];
int m[205][205];

int pd(int i, int j){

	if(i == j) return 0;
	if(m[i][j] != -1) return m[i][j];

	int r = INT_MAX;

	for(int k = i; k < j; k++)
		r = min(r,pd(i,k) + pd(k+1,j) + tot[i][k] + tot[k+1][j]);

	m[i][j] = r;

	return r;
}

int main(){
	
	int k;
	char v[28];
	while(scanf("%d",&k) && k != 0){

		memset(m,-1,sizeof m);

		for(int i = 0; i < k; i++)
			scanf(" %c",&v[i]);

		for(int i = 0; i < k; i++){
			for(int j = 0; j < k; j++){
				int t;
				char c, foo;
				scanf("%d %c %c",&t,&foo,&c);
				tb[v[i]-'a'][v[j]-'a'] = make_pair(t,c);
			}
		}

		int n;
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			memset(m,-1,sizeof m);
			scanf(" %s",in);

			char at;
			tot[0] = tb[in[0]-'a'][in[1]-'a'].first;
			at = tb[in[0]-'a'][in[1]-'a'].second;
			for(int j = 2; j <= n; j++){
				tot[j-1] = tb[at-'a'][in[j]-'a'].first + tot[j-2];
				at = tb[at-'a'][in[j]-'a'].second;
			}

			for(int j = 0; j < n; j++)
				for(int k = j+1; k < n; k++)
					for(int l = j; l <= k; l++){
						tot[j][k] += v[l][l];
					}


			printf("%d\n",pd(0,n-1));

		}



	}


}