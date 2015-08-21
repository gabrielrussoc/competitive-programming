#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int n, v[100005];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	int r = v[1]-v[0];
	int ans = 1;
	for(int i = 2; i < n; i++)
		if(v[i] - v[i-1] != r){
			ans++;
			i++;
			r = v[i] - v[i-1];
		}

	cout << ans << endl;


}
