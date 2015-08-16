#include <cstdio>
#include <algorithm>
#include <iostream>
typedef unsigned long long ull;

using namespace std;

ull mdc(ull a, ull b) {
	
	ull aux;
	while(b){
		aux = a%b;
		a = b;
		b = aux;
	}
	return a;
}

int main(){
	string s;
	cin >> s;
	int k = s.length();
	int j = k;
	for(int i = 0; i < k; i++)
		if(s[i] == '.') j = i;
	ull aux = 1;
	for(int i = j+1; i < k; i++){
		aux *= 10;
	}
	ull pot = 1;
	ull num = 0;
	ull ans;
	for(int i = k-1; i >= 0; i--){
		if(s[i] != '.'){
			num += pot*(s[i]-'0');
			pot *= 10;
		}
	}
	aux *= 100;
	//cout << num << ' ' << pot*aux << endl;
	ans = aux/mdc(num,aux);
	cout << ans << endl;

}
