#include <algorithm>
#include <cstdio>
#include <vector>

#define pb push_back

using namespace std;

int main(){
	
	int a, d;
	vector<int> va, vd;

	while(scanf("%d %d",&a,&d) && a != 0){
		int j;

		for(int i = 0; i < a; i++){
			scanf("%d",&j);
			va.pb(j);
		}

		for(int i = 0; i < d; i++){
			scanf("%d",&j);
			vd.pb(j);
		}

		sort(va.begin(),va.end());
		sort(vd.begin(),vd.end());

		if(va[0] >= vd[1])
			printf("N\n");
		else
			printf("Y\n");

		va.clear();
		vd.clear();

	}

}