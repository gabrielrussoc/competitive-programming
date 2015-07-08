#include <cstdio>

using namespace std;

int main(){
	
	int n;
	int v[1000005];
	scanf("%d",&n);

	int cont = 0;

	while(n > 0){
		int aux = n;
		int qb = 0;
		int i = 1;
		while(aux){
			if(aux%10) qb += i; 
			i *= 10;
			aux /= 10;
		}
		n -= qb;
		v[cont] = qb;
		cont++;
	}
	printf("%d\n",cont);
	for(int j = 0; j < cont; j++)
		printf("%d ",v[j]);
	printf("\n");


}