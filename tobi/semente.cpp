#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int f,r;
	int v[1003];
	cin >> f >> r;
	for(int i = 0; i < r; i++)
		cin >> v[i];

    int ans = v[0]-1;
    for(int i = 1; i < r; i++){
        int x = v[i]-v[i-1];
        ans = max(ans,x/2);
    }   
    ans = max(ans,f-v[r-1]);
    cout << ans << endl;
}
