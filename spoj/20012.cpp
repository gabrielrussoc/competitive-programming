#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
	
	set<int> s;
	int n;
	int aux;

	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		scanf("%d",&aux);
		s.insert(aux);
	}

	while(scanf("%d",&aux) != EOF){
		if(s.find(aux) != s.end())
			printf("sim\n");
		else
			printf("nao\n");
	}



}