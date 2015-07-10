#include <cstdio>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	
	set<long long> s;

	long long n,k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		long long foo;
		cin >> foo;
		s.insert(foo);
	}

	if(k == 1){
		cout << s.size() << endl;
		return 0;
	}


	set<long long>::iterator it;
	for(it = s.begin(); it != s.end(); it++){
		if(s.find((*it) * k) != s.end()) 
			s.erase((*it) * k);
	}

	cout << s.size() << endl;

}