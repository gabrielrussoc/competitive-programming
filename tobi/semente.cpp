#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int f,r;
	int v[1003];
	cin >> f >> r;
	for(int i = 0; i < r; i++)
		cin >> v[i];
	int ans = 0;

	for(int i = 1; i <= f; i++){
		int lo = 0, hi = r-1;
		int mid;
		while(lo != hi){
			mid = (lo+hi+1)/2;
			if(v[mid] <= i)
				lo = mid;
			else
				hi = mid-1;
		}
		if(v[mid] <= i) ans = max(ans,i-v[mid]);
		lo = 0, hi = r-1;
		while(lo != hi){
			mid = (lo+hi)/2;
			if(v[mid] >= i)
				hi = mid;
			else
				lo = mid+1;
		}
		if(v[mid] >= i) ans = max(ans,v[mid]-i);
	}
	cout << ans << endl;
}
