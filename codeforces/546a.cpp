#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	
	int k,w,n, tgt;

	scanf("%d %d %d",&k,&n,&w);

	tgt = 0;
	for(int i = 1; i <= w; i++)
		tgt += k*i;

	if(n < tgt)
		printf("%d\n",tgt-n);
	else
		printf("0\n");


	return 0;
}