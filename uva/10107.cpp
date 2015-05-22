#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
	
	int v[10005],mid,ans;

	for(int i = 0; scanf("%d",&v[i]) != EOF; i++){
		sort(v,v+i+1);

		mid = i/2;

		if(i%2 == 0)
			ans = v[mid];
		else
			ans = (v[mid] + v[mid+1])/2;


		printf("%d\n",ans);

	}

	return 0;
}