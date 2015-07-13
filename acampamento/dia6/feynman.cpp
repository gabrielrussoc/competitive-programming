#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;

	while(cin >> n, n != 0){
		int ans = (n*(n+1)*(2*n+1))/6;
		cout << ans << endl;
	}

}
