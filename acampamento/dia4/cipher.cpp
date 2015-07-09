#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>


using namespace std;

int main(){
	
	int n;
	int v[205];
	char aux[205];
	string s;
	while(scanf("%d",&n) && n != 0){
		for(int i = 0; i < n; i++){
			int a;
			scanf("%d",&a);
			v[i] = a-1;
		}
		int k;
		while(scanf("%d",&k) && k != 0){
			scanf(" %[^\n]",aux);
			int t = strlen(aux);
			while(t < n)
				aux[t++] = ' ';
			aux[n] = '\0';

			s = aux;

			//printf("%s\n",aux);

			while(k--){
				for(int i = 0; i < n; i++)
					aux[v[i]] = s[i];
				s = aux;
				printf("%s\n",aux);
			}
			//printf("%s\n",aux);
		}
	}
}