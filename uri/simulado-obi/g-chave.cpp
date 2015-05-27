#include <cstdio>
#define MAX 10000


using namespace std;

int main(){
	
	int v[MAX] = {0}, q, e,s,c;

	scanf("%d %d",&q,&e);

	for(int i = 0; i < e; i++){
		scanf("%d",&s);
		v[s]++;
	}

	for(int i = 0; i < q; i++){
		scanf("%d",&c);
		if(v[c])
			printf("0\n");
		else
			printf("1\n");
		v[c]++;
	}
	
	return 0;
}