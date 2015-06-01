#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	
	int t;
	scanf("%d",&t);

	while(t--){

		char aux[10005];
		scanf("%s",aux);
		string s = aux;
		scanf("%s",aux);
		string br = aux;

		br += br;

		int n = br.find(s);
		reverse(s.begin(),s.end());
		int k = br.find(s);


		if(n != -1 || k != -1)
			printf("S\n");
		else
			printf("N\n");


	}


}