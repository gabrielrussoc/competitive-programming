#include <cstdio>

using namespace std;

int main(){

	int r, p;

	scanf("%d %d",&p,&r);

	if(p == 0)
		printf("C\n");
	else{
		if(r == 0)
			printf("B\n");
		else
			printf("A\n");
	}

}
