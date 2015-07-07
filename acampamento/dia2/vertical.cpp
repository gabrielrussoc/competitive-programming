#include <cstdio>

using namespace std;

int main(){

	char c;
	int v[30];
	for(int i = 0; i < 30; i++)
		v[i] = 0;

	int b = 0;
	while(scanf("%c",&c) != EOF){
		if(c - 'A' >= 0 && c - 'A' < 26){
			v[c-'A']++;
			if(v[c-'A'] > b)
				b = v[c-'A'];
		}
	}

	for(int i = b; i >= 1; i--){
		for(int j = 0; j < 26; j++){
			if(v[j] >= i)
				printf("*%c",j == 25 ? '\n' : ' ');
			else
				printf(" %c",j == 25 ? '\n' : ' ');
		}
	}
	for(int i = 0; i < 26; i++)
		printf("%c%c",'A'+i,i == 25 ? '\n' : ' ');



	
}
