#include <stdio.h>

int call;

int fib(int n){

	call++;

	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;

	else return fib(n-1) + fib(n-2);

}

int main(){
	
	int n,num,resp,i;

	scanf("%d",&n);

	for(i = 0; i < n; i++){
		call = 0;
		scanf("%d",&num);
		resp = fib(num);
		printf("fib(%d) = %d calls = %d\n",num,call-1,resp);
	}

	return 0;
}