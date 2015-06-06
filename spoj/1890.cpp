#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	
	vector<int> ar;
	int n, l;

	while(scanf("%d %d",&n,&l) && n != 0 && l != 0){

		int aux;
		ar.clear();
		for(int i = 0; i < l; i++){
			scanf("%d",&aux);
			ar.push_back(aux);
		}
		int max = 0;
		vector<int>::iterator it;
		for(int i = 0; i < l; i++){
			it = upper_bound(ar.begin(),ar.end(),ar[i]+n-1);
			if(it - ar.begin() - i > max)
				max = it - ar.begin() - i;
		}
		int ans = n-max;
		printf("%d\n",ans);
	}
}