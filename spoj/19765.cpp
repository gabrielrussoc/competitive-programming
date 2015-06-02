#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main(){
	
	int n;
	while(scanf("%d",&n) && n != 0){

		char s[102];
		string ss;
		set<string> esp;
		for(int i = 0; i < n; i++){
			scanf("%s",s);
			ss = s;
			sort(ss.begin(),ss.end());
			esp.insert(ss);
		}

		printf("%lu\n",esp.size());
		esp.clear();


	}



}