#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	
	vector<string> v;

	int n,k;
	scanf("%d %d",&n,&k);

	for(int i = 0; i < n; i++){
		char aux[25];
		scanf(" %s",aux);
		string s = aux;
		v.push_back(s);
	}

	sort(v.begin(),v.end());

	printf("%s\n",v[k-1].c_str());

}