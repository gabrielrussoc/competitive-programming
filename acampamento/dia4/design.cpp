#include <cstdio>
#include <cstring>

using namespace std;

int p[1000006];

int main(){
	
	int n;
	memset(p,0,sizeof p);
	scanf("%d",&n);

	for(int i = 2; i <= n; i++){
		if(p[i] == 0)
			for(unsigned long long j = i*i; j <= n; j+= i)
				p[j] = 1;		
	}

	int i = 4;
	while(1){
		if(p[n-i] == 1 && p[i] == 1) break;
		i++;
	}

	printf("%d %d\n",i,n-i);


}