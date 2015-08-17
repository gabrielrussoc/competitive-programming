#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){

	int n,k;
	int v[100005];
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	sort(v,v+n);
	int mini = 10000007;
	for(int i = 0; i <= k; i++){
		if(abs(v[n-i-1] - v[k-i]) < mini) mini = abs(v[n-i-1] - v[k-i]);
	}
	cout << mini << endl;


}
