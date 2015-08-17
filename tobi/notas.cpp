#include <iostream>
using namespace std;

int freq[105];

int main(){
	for(int i = 0; i < 105; i++)
		freq[i] = 0;
	int n, a;
	cin >> n;
	int maxi = 0, ans;
	for(int i = 0; i < n; i++){
		cin >> a;
		freq[a]++;
	}
	for(int i = 0; i < 101; i++)
		if(freq[i] >= maxi){
			maxi = freq[i];
			ans = i;
		}
	cout << ans << endl;
}
