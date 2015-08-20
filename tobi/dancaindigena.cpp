#include <iostream>
#include <set>
#include <algorithm>
#define pb push_back
#define pii pair<int,int>
using namespace std;

int mod(int a, int b){
	return ((a%b)+b)%b;
}

int main(){

	
	int n, e;
	bool ini[1000006];
   	pii v[1234];
	cin >> n >> e;
	for(int i = 0; i < n; i++)
		ini[i] = false;
	int p,d;
	for(int i = 0; i < e; i++){
		cin >> p >> d;
		ini[p-1] = true;
		v[i].first = p-1;
		v[i].second = d;
	}
	
	sort(v,v+e);

	int ans = n;

	for(int i = 1; i < e; i++){
		
		set<int> pos;
		int dist = v[i].first-v[0].first;
		if(v[i].second == 1) dist = n-dist;
			

		int cont = 0;
		for(int j = 0; j < e; j++){
			int x = mod(v[j].first + dist*v[j].second,n);
			if(ini[x]) {
				pos.insert(x);
			}	
		}
		if(pos.size() == e){
			if(dist < ans)
				ans = dist;
		}
	}
	cout << ans << endl;
}
