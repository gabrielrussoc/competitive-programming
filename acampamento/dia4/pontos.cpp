#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

long long qd(long long a){
	return a*a;
}

int main(){
	
	int x,y;
	long double ans;
	int n;
	pair<int,int> v[1004];

	scanf("%d",&n);
	if(n == 0 || n == 1){
		printf("0\n");
		return 0;
	}
	for(int i = 0; i < n; i++){
		scanf("%d %d",&x,&y);
		v[i] = make_pair(x,y);
	}


	ans = LLONG_MAX;
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++){
			long double ans1 = sqrt(qd(v[i].first - v[j].first) + qd(v[i].second - v[j].second));
			if(ans1 < ans)
				ans = ans1;
		}

	printf("%.3llf\n",ans);


}