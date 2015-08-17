#include <cstdio>
#include <set>
#include <iostream>
#include <set>
#include <string>

using namespace std;
typedef pair<int,string> pii;

int main(){
	int n,t;
	set<pii> s;
	set<string> team[1024];
	cin >> n >> t;
	int hab;
	string nome;
	for(int i = 0; i < n; i++){
		cin >> nome >> hab;
		s.insert(make_pair(-hab,nome));
	}

	set<pii>::iterator it;
	int i = 0;
	for(it = s.begin(); it != s.end(); it++){
		team[i].insert(it -> second);
		i++;
		i %= t;
	}
	
	set<string>::iterator it2;
	for(i = 0; i < t; i++){
		printf("Time %d\n",i+1);
		for(it2 = team[i].begin(); it2 != team[i].end(); it2++)
			cout << *it2 << endl;
		cout << endl;
	
	}



}
