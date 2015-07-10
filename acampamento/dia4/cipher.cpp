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
			char c;
			scanf("%c%[^\n]",&c,aux);
			int t = strlen(aux);
			while(t < n)
				aux[t++] = ' ';
			aux[n] = '\0';
			//printf("%s\n",aux);

			s = aux;
			for(int i = 0; i < n; i++){
				int cont = 1;
				int cur = v[i];
				while(cur != i){
					cur = v[cur];
					cont++;
				}
				for(int j = 0; j < (k%cont); j++)
					cur = v[cur];
				aux[cur] = s[i]; 
			}

			printf("%s\n",aux);
		}
		printf("\n");
	}
}