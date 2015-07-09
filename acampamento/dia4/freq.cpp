#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int main(){
	int n, x;
	set<int> p;

	cin >> n;

	while(n--){
		cin >> x;
		p.insert(x);
	}

	cout << p.size() << endl;

}