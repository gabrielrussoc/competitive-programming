#include <cstdio>
#define MAX 10000


using namespace std;

int main(){
	
	int f, l, i = 0, c[MAX];
	char v[MAX];

	while(scanf("%c",&v[i]) != EOF){ 
		if(v[i] != '\n')
			i++;
	}

	for(int j = 0; j < i/4; j++)
		c[j] = (v[j] - '0')*1000 + (v[j+(i/4)] - '0')*100 + (v[j+(2*i/4)] - '0')*10 + (v[j+(3*i/4)] - '0');

	f = c[0];
	l = c[i/4 - 1];

	for(int j = 1; j < i/4 - 1; j++)
		printf("%c",(f*c[j] + l)%257);

	printf("\n");


	
	return 0;
}