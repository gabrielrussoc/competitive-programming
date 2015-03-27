#include <stdio.h>

int main(){
	
	int n,h;
	float m,sal;


	scanf("%d %d %f",&n,&h,&m);
	sal = m*h;
	printf("NUMBER = %d\nSALARY = U$ %.2f\n",n,sal);

	return 0;
}