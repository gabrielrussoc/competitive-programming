#include <cstdio>
#include <algorithm>
#include <iostream>
#define pii pair<int,int>
using namespace std;

int main(){

	int s,p,tc = 1;
	pii v[5005];
	pii ans[5005];
	while(cin >> p >> s, s != 0, p != 0){
		for(int i = 0; i < s; i++)
			cin >> v[i].first >> v[i].second;
		sort(v,v+s);
		ans[0].first = v[0].first;
		ans[0].second = v[0].second;
		int k = 0;
		for(int i = 1; i < s; i++){
			if(v[i].first <= ans[k].second)
				ans[k].second = max(v[i].second,ans[k].second);
			else{
				ans[k+1].first = v[i].first;
				ans[k+1].second = v[i].second;
				k++;
			}
		}
		cout << "Teste " << tc++ << endl;
		for(int i = 0; i <= k; i++)
			cout << ans[i].first << ' ' << ans[i].second << endl;
		cout << endl;
		

	}

}
