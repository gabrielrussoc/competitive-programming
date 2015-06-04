#include <cstdio>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	
	map<string,int> mapa;

	int n;
	string s;
	char aux[12];

	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%s",aux);
		s = aux;

		if(!mapa.insert(pair <string,int> (s,1)).second)
			mapa[s]++;
	}

	map<string,int>::iterator it;

	int max = 0;
	string ans;
	for(it = mapa.begin(); it != mapa.end(); it++)
		if(it -> second > max){
			max = it -> second;
			ans = it -> first;
		}

	printf("%s\n",ans.c_str());




}