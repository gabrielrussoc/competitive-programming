#include <cstdio>

using namespace std;

int main(){
	
	int t;
	scanf("%d",&t);
	int i = 1;		
	while(i <= t){
		int l,w,h;
		scanf("%d %d %d",&l,&w,&h);
		if(l <= 20 && w <= 20 && h <= 20)
			printf("Case %d: good\n",i++);
		else
			printf("Case %d: bad\n",i++);
	}

}
