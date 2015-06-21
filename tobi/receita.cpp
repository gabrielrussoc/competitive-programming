#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
		
	int a,b,c;
	cin >> a >> b >> c;

	int ans = min(a/2,b/3);
	ans = min(ans, c/5);

	cout << ans << endl;
}