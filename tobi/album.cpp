#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int x,y,a,b,c,d;

	scanf("%d %d %d %d %d %d",&x,&y,&a,&b,&c,&d);

	if(a+c <= x && max(b,d) <= y)
		printf("S\n");
	else if(a+c <= y && max(b,d) <= x)
		printf("S\n");
	else if(b+d <= x && max(a,c) <= y)
		printf("S\n");
	else if(b+d <= y && max(a,c) <= x)
		printf("S\n");
	else if(a+d <= x && max(b,c) <= y)
		printf("S\n");
	else if(a+d <= y && max(b,c) <= x)
		printf("S\n");
	else if(b+c <= x && max(a,d) <= y)
		printf("S\n");
	else if(b+c <= y && max(a,d) <= x)
		printf("S\n");
	else
		printf("N\n");

}