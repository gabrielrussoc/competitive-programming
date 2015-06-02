#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>

#define pb push_back

using namespace std;

int main(){
	
	vector<string> text;
	char aux[15];
	int t, n;

	scanf("%d",&t);

	while(t--){

		scanf(" %d",&n);
		int p;
		bool a = false;
		bool b = false;
		for(int i = 0; i < n; i++){
			scanf("%s",aux);
			if(aux[0] == '#')
				a = true;
			else{
				b = true;
				p = i;
			}
			text.pb(aux);
		}
		
		if(a && b){
			for(int i = p+1; i < n; i++)
				printf("%s ",text[i].c_str());
			printf("%s ",text[p].c_str());
			for(int i = 0; i < p; i++)
				printf("%s%c",text[i].c_str(),i == p - 1 ? '\n' : ' ');
		}
		else
			for(int i = 0; i < n; i++)
				printf("%s%c",text[i].c_str(),i == n - 1 ? '\n' : ' ');

		text.clear();


	}


}