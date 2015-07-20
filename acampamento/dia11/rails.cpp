#include <bits/stdc++.h>

using namespace std;

stack<int> p;
int v[1230];


int main(){
	
	int n;
	while(scanf("%d",&n) && n != 0){
		while(scanf("%d",&v[0]) && v[0] != 0){
			for(int i = 1; i < n; i++)
				scanf("%d",&v[i]);

			bool ok = true;
			int at = 0;
			int i = 2;
			p.push(1);
			while(at < n && ok){
				if(i-1 > n) ok = false;
				while(v[at] != p.top() && ok){
					p.push(i);
					i++;
					if(i-1 > n) ok = false;
				}
				while(p.size() && v[at] == p.top() && ok){
					p.pop();
					at++;
				}
				if(!p.size()){
					p.push(i);
					i++;
				}
			}


			if(ok)
				printf("Yes\n");
			else
				printf("No\n");

			while(p.size())
				p.pop();
		}
		printf("\n");

	}


}