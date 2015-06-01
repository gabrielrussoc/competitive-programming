#include <algorithm>
#include <vector>
#include <cstdio>
#define PB push_back

using namespace std;

int main(){
	
	int n;
	vector<int> v;
	int a;
	bool blank = false;

	while(scanf("%d",&n) && n != 0){

		if(blank)
			printf("\n");

		for(int i = 0; i < n; i++){
			scanf("%d",&a);
			v.PB(a);
		}

		sort(v.begin(),v.end());

		for(int i = 0; i < n; i++)
			printf("%d ",v[i]);
		printf("\n");

		while(next_permutation(v.begin(),v.end())){
			for(int i = 0; i < n; i++)
				printf("%d ",v[i]);
			printf("\n");
		}

		
		blank = true;
		v.clear();


	}


}