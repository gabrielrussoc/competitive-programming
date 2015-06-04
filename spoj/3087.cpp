#include <map>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main(){
	
	map<string,string> dic;
	int t;
	scanf("%d",&t);
	while(t--){

		int n,m;
		string jp, pt;
		scanf("%d %d",&m,&n);

		getline(cin,jp);
		for(int i = 0; i < m; i++){

			getline(cin,jp);
			getline(cin,pt);

			dic.insert(pair<string,string> (jp,pt));


		}

		map<string,string>::iterator it;

		string line;
		
		for(int i = 0; i < n; i++){
			getline(cin,line);

			int k = 0;
			bool f = false;
			while(k < line.size()){
				pt.clear();
				while(line[k] != ' ' && k < line.size()){
					pt += line[k];
					k++;
				}

				if(f)
					printf(" ");
		
				it = dic.find(pt);
			
				if(it != dic.end())
					printf("%s",it -> second.c_str());
				else
					printf("%s",pt.c_str());

				f = true;
				k++;
			}
			printf("\n");
		}

		printf("\n");
		dic.clear();

	}


}