#include <cstdio>

using namespace std;

int main(){
	
	int sa,sb, n, a, b;

	scanf("%d",&n);

	sa = sb = 0;
	int dif = 0;

	for(int i = 0; i < n; i++){
		scanf("%d %d",&a,&b);
		sa += a;
		sb += b;
		if(a%2 != b%2)
			dif = 1;
	}

	if(sa%2 == sb%2 && dif){
		if(sa%2 == 0)
			printf("0\n");
		else
			printf("1\n");
	}
	else if(sa%2 == 0 && sb%2 == 0)
		printf("0\n"); 
	else
		printf("-1\n");


	return 0;
}