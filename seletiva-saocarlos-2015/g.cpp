#include <stack>
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

stack<int> p;
string s;

void solve(int a, int b){
	for(int i = a; i <= b; i++){
		if(s[i] == '[') s[i] = '(';
		else if(s[i] == ']') s[i] = ')';
		else if (s[i] == '+') s[i] = '*';
		else if (s[i] == '*') s[i] = '+';
		else if (s[i]-'a' >= 0 && s[i]-'a' <= 25) s[i] = toupper(s[i]);
		else s[i] = tolower(s[i]);
	}

}

int main(){
	
	cin >> s;
	int k = s.length();
	for(int i = 0; i < k; i++){
		if(s[i] == '[') p.push(i);
		else if(s[i] == ']'){
			solve(p.top(),i);
			p.pop();
		}
	}
	cout << s << endl;

}
