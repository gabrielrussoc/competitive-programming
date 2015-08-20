#include <iostream>
#include <set>

using namespace std;

int main(){
	int n,m, v[500005];
	set<int> s;
	cin >> n;
	int a;
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> a;
		s.insert(a);
	}
	for(int i = 0; i < n; i++)
		if(s.find(v[i]) == s.end()) cout << v[i] << ' ';
	cout << endl;
}	
