#include <cstdio>

int main(){
	int l,d,k,p;
	scanf("%d %d %d %d",&l,&d,&k,&p);

	int ans = p*(l/d) + k*l;

	printf("%d\n",ans); 
}