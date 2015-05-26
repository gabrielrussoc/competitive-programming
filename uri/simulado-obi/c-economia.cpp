#include <cstdio>

using namespace std;

int main(){
	
	int q,y,n,aux;
	y = n = 0;

	scanf("%d",&q);

	for(int i = 0; i < q; i++){
		scanf("%d",&aux);
		if(!aux)
			y++;
		else
			n++;
	}

	if(y > n)
		printf("Y\n");
	else
		printf("N\n");


	return 0;
}