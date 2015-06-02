#include <cstdio>
#include <algorithm>
#include <vector>

#define pb push_back

using namespace std;

int main(){
	
	int g[5][5];

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			scanf("%d",&g[i][j]);


	vector<int> ans;
	
	int max = 0;

	for(int i = 0; i < 5; i++)
		ans.pb(i+1);

		do {

			int res = 0;
			vector<int> tmp;

			tmp = ans;
			int s = 5;

			while(s >= 2){
				for(int i = 0; i < s - s%2; i += 2)
					res += g[tmp[i]-1][tmp[i+1]-1] + g[tmp[i+1]-1][tmp[i]-1];
				s--;
				tmp.erase(tmp.begin());
			}


			if(res > max)
				max = res;

		} while(next_permutation(ans.begin(),ans.end()));


		printf("%d\n",max);
}