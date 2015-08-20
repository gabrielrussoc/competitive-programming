#include <cstdio>
#include <iostream>
using namespace std;

int main () {
	int n, v[10004];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	int ans = n*10;
	for(int i = 0; i < n-1; i++)
		if(v[i+1]-v[i] < 10) ans -= 10-v[i+1]+v[i];

	cout << ans << endl;

}
