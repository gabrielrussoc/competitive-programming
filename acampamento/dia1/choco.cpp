#include <cstdio>

using namespace std;

int main(){

	int n, m;

	scanf("%d %d",&n,&m);

	if(n%(m+1) == 0)
		printf("Carlos\n");
	else
		printf("Paula\n");	

}
