#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

bool abre(char c){
	if(c == '{' || c == '[' || c == '(') return true;
	return false;
}

bool match(char a, char b){
	if(a == '{') return b == '}';
	else if(a == '[') return b == ']';
	else return b == ')';
}


int main(){
	int t;
	char s[100005];
	scanf("%d",&t);

	while(t--){
		stack<char> p;
		scanf(" %s",s);
		int k = strlen(s);
		
		//printf("%s\n",s);
		p.push(s[0]);
		bool ans = true;
		for(int i = 1; i < k; i++){
			if(abre(s[i])) 
				p.push(s[i]);
			else {
				if(p.empty()){
					ans = false;
					break;
				}
				if(!match(p.top(),s[i])){
					ans = false;
					break;	
				}
				p.pop();
			}
		}
		if(ans && p.empty())
			printf("S\n");
		else
			printf("N\n");
	}
}
