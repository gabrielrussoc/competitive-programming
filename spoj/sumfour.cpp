#include <vector>
#include <algorithm>
#include <cstdio>

#define pb push_back
#define MAX 4000

using namespace std;

int a[MAX][4];

int main(){
	
	vector<int> sumab;

	int n;

	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			sumab.pb(a[i][0] + a[j][1]);

	sort(sumab.begin(),sumab.end());

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int val = -(a[i][2] + a[j][3]);
			pair<vector<int>::iterator,vector<int>::iterator> b;
			b = equal_range(sumab.begin(),sumab.end(),val);
			ans += b.second-b.first;
		}
	}

	printf("%d\n",ans);



}